// Include C++ library files
#include <stdio.h>
#include <math.h>

// Include my files
#include "Nodes.h"
#include "Left_Riemann.h"

#include "Nodes.cc"
#include "Left_Riemann.cc"

// Prototypes
double F(double x) {
  return exp(-x*x);
} // double F(double x) {

int main(void) {
  double Integral = Numerical::Integration::Left_Riemann(F,0,-3,10000);

  printf("Integral = %lf\n", Integral);
  return 0;
} // int main() {
