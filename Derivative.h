#if !defined(DERIVATIVE_HEADER)
#define DERIVATIVE_HEADER

namespace Numerical {
namespace Derivative {

// Two point derivative approximations.
double Forward_2pt(double (*F)(double), const double x, const double h);
double Backward_2pt(double (*F)(double), const double x, const double h);

// Three point derivative approximation.
double Central_3pt(double (*F)(double), const double x, const double h);
double Forward_3pt(double (*F)(double), const double x, const double h);
double Backward_3pt(double (*F)(double), const double x, const double h);

} // namespace Derivative {
} // namespace Numerical {

#endif
