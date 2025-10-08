/**
 * @file pid.hpp
 * @author Rahul Kumar
 * @brief PID Controller class declaration for Acme Robotics mobile robot
 * @version 0.1
 * @copyright Copyright (c) 2025
 * 
 * This class implements a PID controller for velocity control in mobile robots.
 * The controller takes target velocity and current velocity as inputs and
 * computes the control output using proportional, integral, and derivative terms.
 */

#ifndef _PID_H_
#define _PID_H_

/**
 * @class PID
 * @brief A PID controller that computes velocity based on target and current values
 * 
 * This class implements a PID (Proportional-Integral-Derivative) controller
 * for precise velocity control. It maintains three gain parameters:
 * - Proportional gain (k_p) for immediate error correction
 * - Integral gain (k_i) for eliminating steady-state error
 * - Derivative gain (k_d) for dampening oscillations
 */
class PID {
    public:
        /**
         * @brief Construct a new PID controller
         * @param k_p Proportional gain coefficient
         * @param k_i Integral gain coefficient
         * @param k_d Derivative gain coefficient
         */
        PID(double k_p, double k_i, double k_d);

        /**
         * @brief Compute new velocity using PID control
         * @param target_vel Target velocity setpoint
         * @param current_vel Current actual velocity
         * @return double Computed velocity command
         * 
         * This method implements the PID control law but is implemented as stub:
         * return a constant value.
         */
        double compute_vel(double target_vel, double current_vel);

    private:
        double k_p;  ///< Proportional gain coefficient
        double k_i;  ///< Integral gain coefficient
        double k_d;  ///< Derivative gain coefficient
};

#endif