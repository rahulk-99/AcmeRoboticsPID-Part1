/**
 * @file pid.cpp
 * @author Part1- Driver:  Rahul Kumar
 * @author Part1- Navigator:  Venkata Madhav Tadavarthi
 * @author Part2- Driver and Navigator:  Marcus William Hurt
 * @brief Implementation of PID Controller class for Acme Robotics mobile robot
 * @version 0.2
 * @copyright Copyright (c) 2025
 */

 #include "pid.hpp"

 /**
  * @brief Construct a new PID controller object.
  * @param Kp Proportional gain coefficient.
  * @param Ki Integral gain coefficient.
  * @param Kd Derivative gain coefficient.
  * @param dt Time step interval in seconds.
  */
 PID::PID(double Kp, double Ki, double Kd, double dt) :
     _Kp(Kp),
     _Ki(Ki),
     _Kd(Kd),
     _dt(dt),
     _integral(0.0),
     _previous_error(0.0) {}
 
 /**
  * @brief Implementation of velocity computation using PID control.
  *
  * Note: This is currently a stub implementation that returns a constant value.
  * The input parameters are ignored for now.
  */
 double PID::compute_vel(double target_vel, double current_vel) {
    double error = target_vel - current_vel;
    _integral += error * _dt;

    double derivative = (error - _previous_error) / _dt;
    _previous_error = error;
    
    return _Kp * error + _Ki * _integral + _Kd * derivative;
 }