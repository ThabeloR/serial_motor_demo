// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__BUILDER_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__BUILDER_HPP_

#include "serial_motor_demo_msgs/msg/detail/steering_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace serial_motor_demo_msgs
{

namespace msg
{

namespace builder
{

class Init_SteeringCommand_turning_radius
{
public:
  explicit Init_SteeringCommand_turning_radius(::serial_motor_demo_msgs::msg::SteeringCommand & msg)
  : msg_(msg)
  {}
  ::serial_motor_demo_msgs::msg::SteeringCommand turning_radius(::serial_motor_demo_msgs::msg::SteeringCommand::_turning_radius_type arg)
  {
    msg_.turning_radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::serial_motor_demo_msgs::msg::SteeringCommand msg_;
};

class Init_SteeringCommand_steering_angle
{
public:
  Init_SteeringCommand_steering_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SteeringCommand_turning_radius steering_angle(::serial_motor_demo_msgs::msg::SteeringCommand::_steering_angle_type arg)
  {
    msg_.steering_angle = std::move(arg);
    return Init_SteeringCommand_turning_radius(msg_);
  }

private:
  ::serial_motor_demo_msgs::msg::SteeringCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::serial_motor_demo_msgs::msg::SteeringCommand>()
{
  return serial_motor_demo_msgs::msg::builder::Init_SteeringCommand_steering_angle();
}

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__BUILDER_HPP_
