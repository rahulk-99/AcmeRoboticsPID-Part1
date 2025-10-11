#include<iostream>
// #include "lib.hpp"
// #include "lib1.hpp"
// #include "lib2.hpp"
#include "pid.hpp"

int main() {
  // dummy();
  // my_function1(30);
  // bool cond = true;
  // if (cond)
  //   my_function2(30.3);
  // return 0;
  PID pid1(1.0, 0.1, 0.05, 0.01);
  std::cout << pid1.compute_vel(0.1, 0.2) << std::endl;
}
