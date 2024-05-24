import RPi.GPIO as GPIO
import time
import math
from sensor_msgs.msg import Range

class Sonar:

    def __init__(self, gpio_trigger, gpio_echo, range_min=10, range_max=400,field_of_view=math.radians(30)):
        self.fov = field_of_view # in radians
        GPIO.setmode(GPIO.BCM)
        self._gpio_trigger = gpio_trigger
        self._gpio_echo = gpio_echo
        self._range_min = range_min
        self._range_max = range_max
        self._is_reading = False
        self._speed_sound = 17150.0  # in cm/s
        self._last_time_reading = 0
        self._timeout = range_max / self._speed_sound * 2

        GPIO.setup(gpio_trigger, GPIO.OUT)
        GPIO.setup(gpio_echo, GPIO.IN)

        # Waiting for sensor to settle
        GPIO.output(gpio_trigger, GPIO.LOW)
        time.sleep(1)

    def get_range(self):
        self._is_reading = True

        # Trigger the sensor
        GPIO.output(self._gpio_trigger, GPIO.HIGH)
        time.sleep(0.00001)
        GPIO.output(self._gpio_trigger, GPIO.LOW)

        # Measure pulse duration
        pulse_start_time = time.time()
        while GPIO.input(self._gpio_echo) == 0:
            pulse_start_time = time.time()

        pulse_end_time = time.time()
        while GPIO.input(self._gpio_echo) == 1:
            pulse_end_time = time.time()
            if pulse_end_time - pulse_start_time > self._timeout:
                self._is_reading = False
                return -1  # Timeout: return invalid reading

        self._last_time_reading = time.time()
        self._is_reading = False

        # Calculate distance
        pulse_duration = pulse_end_time - pulse_start_time
        distance = pulse_duration * self._speed_sound

        # Clamp distance to valid range
        distance = max(self._range_min, min(distance, self._range_max))
        
        return distance

    @property
    def is_reading(self):
        return self._is_reading

    def get_range_message(self, frame_id, stamp):
        """Get a ROS 2 Range message for the current distance reading."""
        distance = self.get_range()
        if distance > 0:  # Valid reading
            msg = Range()
            msg.header.stamp = stamp
            msg.header.frame_id = frame_id
            msg.radiation_type = Range.ULTRASOUND
            msg.field_of_view = self.fov  # Adjust based on your sensor's specs
            msg.min_range = self._range_min / 100.0  # Convert cm to meters
            msg.max_range = self._range_max / 100.0  # Convert cm to meters
            msg.range = distance / 100.0  # Convert cm to meters
            return msg
        else:
            return None  # Invalid reading 