#if !defined(LEFT_RIEMANN_SOURCE)
#define LEFT_RIEMANN_SOURCE

double Numerical::Integration::Riemann::Left(double (*F)(double), const double a, const double b, const unsigned int n) {
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

  /* Now we can perform the Left Riemann approximation,
                                  Left Approx = Sum(F(x_i)*h)
  But, since the node with, h, is the same for every node, we can pull it out
  of the summation. Therefore,
                                  Left Approx = h*Sum(F(x_i))
  This eliminates n-1 multiplications (we only have to do one multiplication
  rather than one for each step). */
  double Integral = 0;
  double h = (b-a)/(double)n;
  for(int i = 0; i < n+1; i++)
    Integral += F(x[i]);

  Integral *= h;

  // Free nodes
  delete [] x;

  // Return the approximate integral
  return Integral;
} // double Numerical::Integration::Riemann::Left(double (*F)(double), const double a, const double b, const unsigned int n) {



double Numerical::Integration::Riemann::Right(double (*F)(double), const double a, const double b, const unsigned int n) {
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

  /* Now we can perform the Right Riemann approximation,
                                  Right Approx = Sum(F(x_i+1)*h)
  But, since the node with, h, is the same for every node, we can pull it out
  of the summation. Therefore,
                                  Right Approx = h*Sum(F(x_i+1))
  This eliminates n-1 multiplications (we only have to do one multiplication
  rather than one for each step). */
  double Integral = 0;
  double h = (b-a)/(double)n;
  for(int i = 0; i < n+1; i++)
    Integral += F(x[i+1]);

  Integral *= h;


  // Free the nodes
  delete [] x;

  // Return the approximate integral
  return Integral;
} // double Numerical::Integration::Riemann::Right(double (*F)(double), const double a, const double b, const unsigned int n) {

#endif
