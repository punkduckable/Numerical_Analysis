double Numerical::Integration::Trapezoidal(double (*F)(double), const double a, const double b, const unsigned int n) {
  //////////////////////////////////////////////////////////////////////////////
  // Nodes

  /* First, we need to allocate the new nodes. Since n is a variable (that is
  passed to the function) we allocate the nodes using a dynamic array. It should
  be noted that n is the number of SUBDOMAINS not nodes. Since there's always
  1 more node than subdomain, the node array has n+1 elements. */
  double *x = new double[n+1];

  // Get the nodes. Throw an error if something goes wrong.
  if(Numerical::Nodes::Linearly_Spaced(a,b,n,x)) {
    printf("Error! The Trapezoidal method failed to allocate nodes. Aborting\n");
    return 0;
  } // if(Linearly_Spaced_Nodes(a,b,n,x)) {

  //////////////////////////////////////////////////////////////////////////////
  // Trapezoidal rule
  // Here we actually implement the Trapezoidal rule. With evenly spaced nodes,
  // the trapezoidal rule is
  //                              Trap Approx = h*{ .5*f(x_0) + sum(from i = 1 to n-1 of f(x_i)) + 5*f(x_n)}

  // We use multiple accumulators.
  double Integral0 = 0;
  double Integral1 = 0;
  double Integral2 = 0;
  double Integral3 = 0;

  // add in contributions from edge nodes.
  Integral0 += .5*(F(x[0]) + F(x[n]));

  // Main loop
  int i;
  for(i = 1; i < (int)n - 3; i += 4) {
    Integral0 += F(x[i+0]);
    Integral1 += F(x[i+1]);
    Integral2 += F(x[i+2]);
    Integral3 += F(x[i+3]);
  } // for(i = 1; i < n - 3; i += 4) {

  // Clean up loop
  for( ; i < n; i++)
    Integral0 += F(x[i]);

  // Combine the multiple accumulators
  double Integral = Integral0 + Integral1 + Integral2 + Integral3;

  // Calculate h, multiply Integral by h
  const double h = (b - a)/(double)n;
  Integral *= h;

  // Free nodes
  delete [] x;

  // All done.
  return Integral;
} // double Numerical::Integration::Trapezoidal(double (*F)(double), const double a, const double b, const unsigned int n) {
