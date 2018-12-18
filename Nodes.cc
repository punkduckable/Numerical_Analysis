#if !defined(NODES_SOURCE)
#define NODES_SOURCE

int Numerical::Nodes::Linearly_Spaced(const double a, const double b, const unsigned int n, double *Nodes) {
  /* This function is used to find a set of n nodes that are evenly spaced
  between a and b. For this to work, n must be non-zero. */
  if(n==0)
    return 1;

  /* We calculate the nodes in a rather non-conventional way. To understand my
  approach, let's first consider two different methods for finding nodes, x_i,
                                  x_i = a + i*h                                 {1}
                                  x_i = b - (n - i)h                            {2}
  A quick check (and the fact that b - a = nh) shows that both approaches should
  give the same values. In reality, however, the two methods will not be
  identical because of roundoff error. I believe that the biggest source of this
  error is the calculation of h,
                                  h = (b-a)/n
  suppose that the error of this calculation is E. Therefore, the calculated
  value of h, which we will call h_calc, satisifies
                                  h - h_calc = E
  Because of this, the values of the nodes using the two methods are,
                                  x_i = a + i*h_calc + i*E
                                  x_i = b - (n-i)*h_calc - (n-i)*E
  We can try and minimize the error by averaging the two,
                                  x_i = (a + b + h_calc*(2i - n))/2 + E*(2i - n)/2
  This approach more evenly distrubites the roundoff error across the interval.
  I think that this makes it a little better.
  */

  // With this established, let's now calculate the nodes
  const double h = (b - a)/(double)n;
  for(int i = 0; i <= n; i++)
    Nodes[i] = .5*(a + b + h*(2*(double)i - (double)n));

  return 0;
} // int Numerical::Nodes::Linearly_Spaced(const double a, const double b, const unsigned int n, double *Nodes) {



#endif
