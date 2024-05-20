// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "serial_motor_demo_msgs/msg/detail/steering_command__rosidl_typesupport_introspection_c.h"
#include "serial_motor_demo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "serial_motor_demo_msgs/msg/detail/steering_command__functions.h"
#include "serial_motor_demo_msgs/msg/detail/steering_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  serial_motor_demo_msgs__msg__SteeringCommand__init(message_memory);
}

void SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_fini_function(void * message_memory)
{
  serial_motor_demo_msgs__msg__SteeringCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_member_array[2] = {
  {
    "steering_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(serial_motor_demo_msgs__msg__SteeringCommand, steering_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "turning_radius",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(serial_motor_demo_msgs__msg__SteeringCommand, turning_radius),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_members = {
  "serial_motor_demo_msgs__msg",  // message namespace
  "SteeringCommand",  // message name
  2,  // number of fields
  sizeof(serial_motor_demo_msgs__msg__SteeringCommand),
  SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_member_array,  // message members
  SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_type_support_handle = {
  0,
  &SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_serial_motor_demo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, serial_motor_demo_msgs, msg, SteeringCommand)() {
  if (!SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_type_support_handle.typesupport_identifier) {
    SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SteeringCommand__rosidl_typesupport_introspection_c__SteeringCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
