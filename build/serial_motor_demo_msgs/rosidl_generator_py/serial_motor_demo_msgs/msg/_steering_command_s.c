// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from serial_motor_demo_msgs:msg/SteeringCommand.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "serial_motor_demo_msgs/msg/detail/steering_command__struct.h"
#include "serial_motor_demo_msgs/msg/detail/steering_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool serial_motor_demo_msgs__msg__steering_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[61];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("serial_motor_demo_msgs.msg._steering_command.SteeringCommand", full_classname_dest, 60) == 0);
  }
  serial_motor_demo_msgs__msg__SteeringCommand * ros_message = _ros_message;
  {  // steering_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "steering_angle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->steering_angle = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // turning_radius
    PyObject * field = PyObject_GetAttrString(_pymsg, "turning_radius");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->turning_radius = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * serial_motor_demo_msgs__msg__steering_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SteeringCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("serial_motor_demo_msgs.msg._steering_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SteeringCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  serial_motor_demo_msgs__msg__SteeringCommand * ros_message = (serial_motor_demo_msgs__msg__SteeringCommand *)raw_ros_message;
  {  // steering_angle
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->steering_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "steering_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // turning_radius
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->turning_radius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "turning_radius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
