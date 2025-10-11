/**
 * @file pid.hpp
 * @author Part1- Driver:  Rahul Kumar
 * @author Part1- Navigator:  Venkata Madhav Tadavarthi
 * @author Part2- Driver and Navigator:  Marcus William Hurt
 * @brief PID Controller class declaration for Acme Robotics mobile robot
 * @version 0.2
 * @copyright Copyright (c) 2025
 */

 #ifndef PID_HPP
 #define PID_HPP
 
 /**
  * @class PID
  * @brief A PID controller that computes velocity based on target and current values.
  */
 class PID {
 public:
     /**
      * @brief Construct a new PID controller object.
      * @param Kp Proportional gain coefficient.
      * @param Ki Integral gain coefficient.
      * @param Kd Derivative gain coefficient.
      * @param dt Time step interval in seconds.
      */
     PID(double Kp, double Ki, double Kd, double dt);
 
     /**
      * @brief Compute new velocity using PID control.
      * @param target_vel Target velocity setpoint.
      * @param current_vel Current actual velocity.
      * @return double Computed velocity command.
      */
     double compute_vel(double target_vel, double current_vel);
 
 private:
     // PID Gains
     double _Kp;  ///< Proportional gain coefficient
     double _Ki;  ///< Integral gain coefficient
     double _Kd;  ///< Derivative gain coefficient
 
     // State Variables
     double _dt;             ///< Time step in seconds
     double _integral;       ///< Accumulated integral error
     double _previous_error; ///< Error from the previous time step
 };
 
 #endif // PID_HPP