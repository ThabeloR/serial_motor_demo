// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice

#ifndef SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_HPP_
#define SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__serial_motor_demo_msgs__msg__SteeringCommand __attribute__((deprecated))
#else
# define DEPRECATED__serial_motor_demo_msgs__msg__SteeringCommand __declspec(deprecated)
#endif

namespace serial_motor_demo_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SteeringCommand_
{
  using Type = SteeringCommand_<ContainerAllocator>;

  explicit SteeringCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steering_angle = 0;
      this->turning_radius = 0;
    }
  }

  explicit SteeringCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->steering_angle = 0;
      this->turning_radius = 0;
    }
  }

  // field types and members
  using _steering_angle_type =
    int16_t;
  _steering_angle_type steering_angle;
  using _turning_radius_type =
    int16_t;
  _turning_radius_type turning_radius;

  // setters for named parameter idiom
  Type & set__steering_angle(
    const int16_t & _arg)
  {
    this->steering_angle = _arg;
    return *this;
  }
  Type & set__turning_radius(
    const int16_t & _arg)
  {
    this->turning_radius = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__serial_motor_demo_msgs__msg__SteeringCommand
    std::shared_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__serial_motor_demo_msgs__msg__SteeringCommand
    std::shared_ptr<serial_motor_demo_msgs::msg::SteeringCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SteeringCommand_ & other) const
  {
    if (this->steering_angle != other.steering_angle) {
      return false;
    }
    if (this->turning_radius != other.turning_radius) {
      return false;
    }
    return true;
  }
  bool operator!=(const SteeringCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SteeringCommand_

// alias to use template instance with default allocator
using SteeringCommand =
  serial_motor_demo_msgs::msg::SteeringCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace serial_motor_demo_msgs

#endif  // SERIAL_MOTOR_DEMO_MSGS__MSG__DETAIL__STEERING_COMMAND__STRUCT_HPP_
