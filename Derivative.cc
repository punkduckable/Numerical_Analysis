#if !defined(DERIVATIVE_SOURCE)
#define DERIVATIVE_SOURCE

////////////////////////////////////////////////////////////////////////////////
// 2 point approximations

double Numerical::Derivative::Forward_2pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1/h)*(F(x+h) - F(x));
} // double Numerical::Derivative::Forward_2pt(double (*F)(double), const double x, const double h) {



double Numerical::Derivative::Backward_2pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1/h)*(F(x) - F(x-h));
} // double Numerical::Derivative::Backward_2pt(double (*F)(double), const double x, const double h) {



////////////////////////////////////////////////////////////////////////////////
// 3 point approximations

double Numerical::Derivative::Central_3pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(2.*h))*(F(x+h) - F(x-h));
} // double Numerical::Derivative::Central_3pt(double (*F)(double), const double x, const double h) {



double Numerical::Derivative::Forward_3pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(2.*h))*(-3*F(x) + 4*F(x+h) - F(x+2*h));
} // double Numerical::Derivative::Forward_3pt(double (*F)(double), const double x, const double h) {



double Numerical::Derivative::Backward_3pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(2.*h))*(3*F(x) - 4*F(x-h) + F(x-2*h));
} // double Numerical::Derivative::Backward_3pt(double (*F)(double), const double x, const double h) {



////////////////////////////////////////////////////////////////////////////////
// 5 point derivative approximations

double Numerical::Derivative::Central_5pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(12.*h))*(-F(x+2*h) + 8*F(x+h) - 8*F(x-h) + F(x-2*h));
} // double Numerical::Derivative::Central_5pt(double (*F)(double), const double x, const double h) {


double Numerical::Derivative::Forward_5pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(12.*h))*( -21*F(x) + 32*F(x+h) - 12*F(x+2*h) + F(x+4*h) );
} // double Numerical::Derivative::Forward_5pt(double (*F)(double), const double x, const double h) {



double Numerical::Derivative::Backward_5pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1./(12.*h))*( 21*F(x) - 32*F(x-h) + 12*F(x-2*h) - F(x-4*h) );
} // double Numerical::Derivative::Backward_5pt(double (*F)(double), const double x, const double h) {

#endif
