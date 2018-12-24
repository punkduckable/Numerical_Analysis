#if !defined(TRAPEZOIDAL_HEADER)
#define TRAPEZOIDAL_HEADER

namespace Numerical {
namespace Integration {

double Trapezoidal( double (*F)(double), const double a, const double b, const unsigned int n);

} // namespace Integration
} // namespace Numerical {

#endif
