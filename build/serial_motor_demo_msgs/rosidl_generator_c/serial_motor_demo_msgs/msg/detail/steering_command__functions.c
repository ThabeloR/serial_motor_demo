// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice
#include "serial_motor_demo_msgs/msg/detail/steering_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
serial_motor_demo_msgs__msg__SteeringCommand__init(serial_motor_demo_msgs__msg__SteeringCommand * msg)
{
  if (!msg) {
    return false;
  }
  // steering_angle
  // turning_radius
  return true;
}

void
serial_motor_demo_msgs__msg__SteeringCommand__fini(serial_motor_demo_msgs__msg__SteeringCommand * msg)
{
  if (!msg) {
    return;
  }
  // steering_angle
  // turning_radius
}

bool
serial_motor_demo_msgs__msg__SteeringCommand__are_equal(const serial_motor_demo_msgs__msg__SteeringCommand * lhs, const serial_motor_demo_msgs__msg__SteeringCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  // turning_radius
  if (lhs->turning_radius != rhs->turning_radius) {
    return false;
  }
  return true;
}

bool
serial_motor_demo_msgs__msg__SteeringCommand__copy(
  const serial_motor_demo_msgs__msg__SteeringCommand * input,
  serial_motor_demo_msgs__msg__SteeringCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // steering_angle
  output->steering_angle = input->steering_angle;
  // turning_radius
  output->turning_radius = input->turning_radius;
  return true;
}

serial_motor_demo_msgs__msg__SteeringCommand *
serial_motor_demo_msgs__msg__SteeringCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__SteeringCommand * msg = (serial_motor_demo_msgs__msg__SteeringCommand *)allocator.allocate(sizeof(serial_motor_demo_msgs__msg__SteeringCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(serial_motor_demo_msgs__msg__SteeringCommand));
  bool success = serial_motor_demo_msgs__msg__SteeringCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
serial_motor_demo_msgs__msg__SteeringCommand__destroy(serial_motor_demo_msgs__msg__SteeringCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    serial_motor_demo_msgs__msg__SteeringCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__init(serial_motor_demo_msgs__msg__SteeringCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__SteeringCommand * data = NULL;

  if (size) {
    data = (serial_motor_demo_msgs__msg__SteeringCommand *)allocator.zero_allocate(size, sizeof(serial_motor_demo_msgs__msg__SteeringCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = serial_motor_demo_msgs__msg__SteeringCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        serial_motor_demo_msgs__msg__SteeringCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__fini(serial_motor_demo_msgs__msg__SteeringCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      serial_motor_demo_msgs__msg__SteeringCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

serial_motor_demo_msgs__msg__SteeringCommand__Sequence *
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  serial_motor_demo_msgs__msg__SteeringCommand__Sequence * array = (serial_motor_demo_msgs__msg__SteeringCommand__Sequence *)allocator.allocate(sizeof(serial_motor_demo_msgs__msg__SteeringCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = serial_motor_demo_msgs__msg__SteeringCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__destroy(serial_motor_demo_msgs__msg__SteeringCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    serial_motor_demo_msgs__msg__SteeringCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__are_equal(const serial_motor_demo_msgs__msg__SteeringCommand__Sequence * lhs, const serial_motor_demo_msgs__msg__SteeringCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!serial_motor_demo_msgs__msg__SteeringCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
serial_motor_demo_msgs__msg__SteeringCommand__Sequence__copy(
  const serial_motor_demo_msgs__msg__SteeringCommand__Sequence * input,
  serial_motor_demo_msgs__msg__SteeringCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(serial_motor_demo_msgs__msg__SteeringCommand);
    serial_motor_demo_msgs__msg__SteeringCommand * data =
      (serial_motor_demo_msgs__msg__SteeringCommand *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!serial_motor_demo_msgs__msg__SteeringCommand__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          serial_motor_demo_msgs__msg__SteeringCommand__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!serial_motor_demo_msgs__msg__SteeringCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
