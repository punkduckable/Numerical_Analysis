// Include C++ library files
#include <stdio.h>
#include <math.h>

// Include my files
#include "Nodes.h"
#include "Riemann.h"

#include "Nodes.cc"
#include "Riemann.cc"

// Prototypes
double F(double x) {
  return exp(-x*x);
} // double F(double x) {

int main(void) {
  double Left_Integral  = Numerical::Integration::Riemann::Left (F,-3,0,1000);
  double Right_Integral = Numerical::Integration::Riemann::Right(F,-3,0,1000);


  printf("Left Integral  = %lf\n", Left_Integral );
  printf("Right Integral = %lf\n", Right_Integral);

  return 0;
} // int main() {
