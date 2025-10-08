/**
 * @file pid.cpp
 * @author Rahul Kumar
 * @brief Implementation of PID Controller class for Acme Robotics mobile robot
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include "pid.hpp"

/**
 * @brief Constructor implementation for PID controller
 * @param k_p_ Proportional gain coefficient
 * @param k_i_ Integral gain coefficient
 * @param k_d_ Derivative gain coefficient
 */
PID::PID(double k_p_, double k_i_, double k_d_): k_p(k_p_), k_i(k_i_), k_d(k_d_) {}

/**
 * @brief Implementation of velocity computation using PID control
 * 
 * Note: This is currently a stub implementation that returns a constant value.
 */
double PID::compute_vel(double target_vel, double current_vel) {
    return 1.5;  // Stub implementation
}