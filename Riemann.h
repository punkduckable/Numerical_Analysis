#if !defined(LEFT_RIEMANN_HEADER)
#define LEFT_RIEMANN_HEADER

namespace Numerical {
namespace Integration {
namespace Riemann {

double Left    (double (*F)(double), const double a, const double b, const unsigned int n);
double Right   (double (*F)(double), const double a, const double b, const unsigned int n);
double Midpoint(double (*F)(double), const double a, const double b, const unsigned int n);

} // namespace Riemann
} // namespace Integration
} // namespace Numerical

#endif
