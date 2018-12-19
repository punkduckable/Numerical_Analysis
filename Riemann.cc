#if !defined(LEFT_RIEMANN_SOURCE)
#define LEFT_RIEMANN_SOURCE

double Numerical::Integration::Left_Riemann(double (*F)(double), const double a, const double b, const unsigned int n) {
  //////////////////////////////////////////////////////////////////////////////
  // Nodes

  // First, need to allocate the nodes. Note that there are n+1 nodes.
  double *x = new double[n+1];

  // Get the nodes. Throw an error if something goes wrong.
  if(Numerical::Nodes::Linearly_Spaced(a,b,n,x)) {
    printf("Error! Unable to calculate nodes. Aborting\n");
    return 0;
  } // if(Linearly_Spaced_Nodes(a,b,n,x)) {

  //////////////////////////////////////////////////////////////////////////////
  // Integration

  // Now we can perform the Left Riemann approximation
  double Integral = 0;
  double h = (b-a)/n;
  for(int i = 0; i < n+1; i++)
    Integral += F(x[i])*h;

  // Free nodes
  delete [] x;

  return Integral;
} // double Numerical::Integration::Left_Riemann(const double a, const double b, const unsigned int n, double (*F)(double)) {

#endif
