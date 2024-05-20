// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_H_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/SteeringCommand in the package serial_motor_demo_msgs.
typedef struct serial_motor_demo_msgs__msg__SteeringCommand
{
  int16_t steering_angle;
  int16_t turning_radius;
} serial_motor_demo_msgs__msg__SteeringCommand;

// Struct for a sequence of serial_motor_demo_msgs__msg__SteeringCommand.
typedef struct serial_motor_demo_msgs__msg__SteeringCommand__Sequence
{
  serial_motor_demo_msgs__msg__SteeringCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} serial_motor_demo_msgs__msg__SteeringCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_H_
