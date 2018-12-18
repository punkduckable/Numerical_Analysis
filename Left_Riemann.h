#if !defined(LEFT_RIEMANN_HEADER)
#define LEFT_RIEMANN_HEADER

namespace Numerical {
namespace Integration {

double Left_Riemann(double (*F)(double), const double a, const double b, const unsigned int n);

} // namespace Integration
} // namespace Numerical

#endif
