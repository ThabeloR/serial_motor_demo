// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__TRAITS_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__TRAITS_HPP_

#include "serial_motor_demo_msgs/msg/detail/steering_command__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<serial_motor_demo_msgs::msg::SteeringCommand>()
{
  return "serial_motor_demo_msgs::msg::SteeringCommand";
}

template<>
inline const char * name<serial_motor_demo_msgs::msg::SteeringCommand>()
{
  return "serial_motor_demo_msgs/msg/SteeringCommand";
}

template<>
struct has_fixed_size<serial_motor_demo_msgs::msg::SteeringCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<serial_motor_demo_msgs::msg::SteeringCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<serial_motor_demo_msgs::msg::SteeringCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__TRAITS_HPP_
