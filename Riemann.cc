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
  // The Left Riemann approximation is,
  //                                Left Approx = Sum(F(x_i)*h)

  // Calculate h.
  double h = (b-a)/(double)n;

  // Since addition commutes, I can use multiple accumulators to improve runtime.
  double Integral;
  double Integral0 = 0;
  double Integral1 = 0;
  double Integral2 = 0;
  double Integral3 = 0;

  /* Further, since the node with, h, is the same for every node, we can pull it out
  of the summation. Therefore,
                                  Left Approx = h*Sum(F(x_i))
  This eliminates n-1 multiplications (we only have to do one multiplication
  rather than one for each step). */

  // Main loop
  int i;
  for(i = 0; i < n - 3; i += 4) {
    Integral0 += F(x[i]);
    Integral1 += F(x[i+1]);
    Integral2 += F(x[i+2]);
    Integral3 += F(x[i+3]);
  } // for(int i = 0; i < (n+1) - 3; i += 4) {

  // Clean-up loop
  for( ; i < n+1; i++)
    Integral0 += F(x[i]);

  // Combine the multiple accumulators.
  Integral = Integral0 + Integral1 + Integral2 + Integral3;

  // Now multiply by h.
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
  // The Right Riemann approximation is,
  //                                Right Approx = Sum(F(x_i+1)*h)

  // Calculate h.
  double h = (b-a)/(double)n;


  // Since addition commutes, I can use multiple accumulators to improve runtime.
  double Integral;
  double Integral0 = 0;
  double Integral1 = 0;
  double Integral2 = 0;
  double Integral3 = 0;


  /* Further, since the node with, h, is the same for every node, we can pull it out
  of the summation. Therefore,
                                  Right Approx = h*Sum(F(x_i+1))
  This eliminates n-1 multiplications (we only have to do one multiplication
  rather than one for each step). */

  // Main loopp
  int i;
  for(i = 0; i < n - 3; i += 4) {
    Integral0 += F(x[i+1]);
    Integral1 += F(x[i+3]);
    Integral2 += F(x[i+3]);
    Integral3 += F(x[i+4]);
  } // for(i = 0; i < n - 3; i += 4) {

  // Clean up loop
  for( ; i < n; i++)
    Integral0 += F(x[i+1]);

  // Combine the multiple accumulators
  Integral = Integral0 + Integral1 + Integral2 + Integral3;

  // Now multiply through by h
  Integral *= h;

  // Free the nodes
  delete [] x;

  // Return the approximate integral
  return Integral;
} // double Numerical::Integration::Riemann::Right(double (*F)(double), const double a, const double b, const unsigned int n) {

#endif
