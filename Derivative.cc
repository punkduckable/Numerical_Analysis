#if !defined(DERIVATIVE_SOURCE)
#define DERIVATIVE_SOURCE

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



double Numerical::Derivative::Central_3pt(double (*F)(double), const double x, const double h) {
  // Check for bad input
  if(h == 0) {
    printf("Error! h must be non-zero\n");
    return NAN;
  } // if(h == 0) {

  return (1/(2*h))*(F(x+h) - F(x-h));
} // double Numerical::Derivative::Central_3pt(double (*F)(double), const double x, const double h) {

#endif
