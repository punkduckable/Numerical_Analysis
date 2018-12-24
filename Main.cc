// Include C++ library files
#include <stdio.h>
#include <math.h>

// Include my files
#include "Nodes.h"
#include "Riemann.h"
#include "Trapezoidal.h"
#include "Derivative.h"

#include "Nodes.cc"
#include "Riemann.cc"
#include "Trapezoidal.cc"
#include "Derivative.cc"

// functions
double F(const double x) {
  return exp(-x*x);
} // double F(const double x) {

double G(const double x) {
  return exp(-.01*x*x)*sin(3.8*sqrt(x)) + sin(50*x)*exp(-.03*x*x);
} // double G(const double x) {

int main(void) {
  //////////////////////////////////////////////////////////////////////////////
  // Derivative tests
  double D_Forward_2pt  = Numerical::Derivative::Forward_2pt(G, 7, .0001);
  double D_Backward_2pt = Numerical::Derivative::Backward_2pt(G, 7, .0001);

  double D_Central_3pt  = Numerical::Derivative::Central_3pt(G, 7, .0001);
  double D_Forward_3pt  = Numerical::Derivative::Forward_3pt(G, 7, .0001);
  double D_Backward_3pt = Numerical::Derivative::Backward_3pt(G, 7, .0001);

  double D_Central_5pt  = Numerical::Derivative::Central_5pt(G, 7, .0001);
  double D_Forward_5pt  = Numerical::Derivative::Forward_5pt(G, 7, .0001);
  double D_Backward_5pt = Numerical::Derivative::Backward_5pt(G, 7, .0001);


  printf("Forward difference 2 point  = %lf\n", D_Forward_2pt);
  printf("Backward difference 2 point = %lf\n\n", D_Backward_2pt);

  printf("Central difference 3 point  = %lf\n", D_Central_3pt);
  printf("Forward difference 3 point  = %lf\n", D_Forward_3pt);
  printf("Backward difference 3 point = %lf\n\n", D_Backward_3pt);

  printf("Central difference 5 point  = %lf\n", D_Central_5pt);
  printf("Forward difference 5 point  = %lf\n", D_Forward_5pt);
  printf("Backward difference 5 point = %lf\n", D_Backward_5pt);


  //////////////////////////////////////////////////////////////////////////////
  // Integral tests
  double Left_Integral        = Numerical::Integration::Riemann::Left (F,-3,0,1000);
  double Right_Integral       = Numerical::Integration::Riemann::Right(F,-3,0,1000);
  double Midpoint_Integral    = Numerical::Integration::Riemann::Midpoint(F,-3,0,10);
  double Trapezoidal_Integral = Numerical::Integration::Trapezoidal(F,-3,0,10);


  printf("Left Integral        = %lf\n", Left_Integral );
  printf("Right Integral       = %lf\n", Right_Integral);
  printf("Midpoint Integral    = %lf\n", Midpoint_Integral);
  printf("Trapezoidal Integral = %lf\n", Trapezoidal_Integral);

  return 0;
} // int main() {
