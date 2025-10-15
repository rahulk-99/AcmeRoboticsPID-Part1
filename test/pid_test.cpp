/**
 * @file pid_test.cpp
 * @author Part1- Driver:  Rahul Kumar
 * @author Part1- Navigator:  Venkata Madhav Tadavarthi
 * @author Part2- Driver and Navigator:  Marcus William Hurt
 * @brief Unit tests for PID Controller class
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

 #include <gtest/gtest.h>
 #include "pid.hpp"
 
 // A small tolerance is necessary for comparing floating-point numbers.
 constexpr double TOLERANCE = 1e-5;
 
 /**
  * @brief Test 1: Verify the proportional term calculation in compute_vel.
  *
  * This test isolates the proportional component by setting Ki and Kd to zero.
  * The expected output should be exactly Kp * (target_vel - current_vel).
  */
 TEST(PIDTest, ProportionalTermShouldBeCorrect) {
     // Arrange: Create a PID controller with only Kp active.
     double Kp = 0.5, Ki = 0.0, Kd = 0.0, dt = 0.1;
     PID controller(Kp, Ki, Kd, dt);
 
     double target_velocity = 20.0;
     double current_velocity = 15.0;
     double error = target_velocity - current_velocity; // 10.0
     double expected_output = Kp * error; // 0.5 * 10.0 = 5.0
 
     // Act: Compute the velocity command.
     double actual_output = controller.compute_vel(target_velocity, current_velocity);
 
     // Assert: The computed output should match the expected proportional output.
     EXPECT_NEAR(actual_output, expected_output, TOLERANCE);
 }
 
 /**
  * @brief Test 2: Verify that the integral term accumulates error over time.
  *
  * This test checks that when a constant error is present, the integral
  * term grows with each time step, which is the core function of the 'I'
  * in PID.
  */
 TEST(PIDTest, IntegralTermShouldAccumulateError) {
     // Arrange: Create a PID controller with only Ki active.
     double Kp = 0.0, Ki = 0.2, Kd = 0.0, dt = 0.1;
     PID controller(Kp, Ki, Kd, dt);
 
     double target_velocity = 15.0;
     double current_velocity = 10.0;
     [[maybe_unused]] double error = target_velocity - current_velocity; // 5.0
 
     // --- First call ---
     // Act & Assert: The first output should be Ki * (error * dt)
     // Expected Output = 0.2 * (5.0 * 0.1) = 0.1
     double output1 = controller.compute_vel(target_velocity, current_velocity);
     EXPECT_NEAR(output1, 0.1, TOLERANCE);
 
     // --- Second call with the same error ---
     // Act & Assert: The internal integral has now doubled.
     // Expected New Integral = (5.0 * 0.1) + (5.0 * 0.1) = 1.0
     // Expected Output = 0.2 * 1.0 = 0.2
     double output2 = controller.compute_vel(target_velocity, current_velocity);
     EXPECT_NEAR(output2, 0.2, TOLERANCE);
 }
 
 /**
  * @brief Test 3: Verify the derivative term calculation.
  *
  * This test isolates the derivative component. It calls compute twice to
  * establish a "previous_error" and then checks the result of the second call.
  */
 TEST(PIDTest, DerivativeTermShouldBeCorrect) {
     // Arrange: Create a controller with only Kd active.
     double Kp = 0.0, Ki = 0.0, Kd = 0.8, dt = 0.1;
     PID controller(Kp, Ki, Kd, dt);
 
     // Act 1: First call to establish the initial error state.
     // previous_error becomes 10.0 after this call.
     controller.compute_vel(50.0, 40.0);
 
     // Act 2: Second call with a new error.
     double current_error = 50.0 - 45.0; // New error is 5.0
     double previous_error = 10.0; // From the previous step
     double derivative = (current_error - previous_error) / dt; // (5.0 - 10.0) / 0.1 = -50.0
     double expected_output = Kd * derivative; // 0.8 * -50.0 = -40.0
 
     double actual_output = controller.compute_vel(50.0, 45.0);
 
     // Assert: Check if the derivative calculation is correct.
     EXPECT_NEAR(actual_output, expected_output, TOLERANCE);
 }
 
 
 /**
  * @brief Test 4: Verify behavior when there is no error.
  *
  * If the target and current velocities are the same, the output should
  * be zero (assuming no prior integral error).
  */
 TEST(PIDTest, ZeroErrorShouldResultInZeroOutput) {
     // Arrange
     double Kp = 1.0, Ki = 0.1, Kd = 0.05, dt = 0.1;
     PID controller(Kp, Ki, Kd, dt);
 
     // Act
     double output = controller.compute_vel(25.0, 25.0);
 
     // Assert
     EXPECT_NEAR(output, 0.0, TOLERANCE);
 }