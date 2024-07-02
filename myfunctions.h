#ifndef _ADD_H
#define _ADD_H
#include <vector>
#include <cmath>
#include <complex>

double fExample(double x, double y)
{
    return 2 * (x * y);
}

double slopeF(double x, double y)
{
  return std::cos(std::abs(x * y) / (-5)) * 5;
}

typedef double (*SlopeFunction)(double, double);
std::vector<std::vector<double>> euler(double x0, double y0, double xLast, double h, SlopeFunction slopeF) {
  double xn = x0;
  double yn = y0;
  std::vector<std::vector<double>> result;

  for (; xn <= xLast; xn += h) 
  {
    double slope = slopeF(xn, yn);
    double yn_1 = yn + h * slope;

    result.push_back({xn, yn});
    std::cout << xn << "\t" << yn << "\t" << slope << std::endl;
    yn = yn_1;
  }
  return result;
}

std::vector<std::vector<double>> modified_Euler(double x0, double y0, double xLast, double h, SlopeFunction slopeF) 
{
  double xn = x0;
  double yn = y0;
  std::vector<std::vector<double>> result;

  for (; xn <= xLast; xn += h) 
  {
    double slope = slopeF(xn, yn);
    double yn_1_estimate = yn + h * slope;
    double yn_1 = yn + h * (slope + slopeF(xn + h, yn_1_estimate))/2;

    result.push_back({xn, yn});
    std::cout << xn << "\t" << yn << "\t" << slope << std::endl;
    yn = yn_1;
  }
  return result;
}

std::vector<std::vector<double>> RK4(double x0, double y0, double xLast, double h, SlopeFunction slopeF) 
{
  double xn = x0;
  double yn = y0;
  std::vector<std::vector<double>> result;

  for (; xn <= xLast; xn += h) 
  {
    double k1 = slopeF(xn, yn);
    double k2 = slopeF(xn + h / 2, yn + h * k1 / 2);
    double k3 = slopeF(xn + h / 2, yn + h * k2 / 2);
    double k4 = slopeF(xn + h, yn + h * k3);
    double yn_1 = yn + h / 6 * (k1 + 2*k2 + 2*k3 + k4);

    result.push_back({xn, yn});
    std::cout << xn << "\t" << yn << std::endl;
    yn = yn_1;
  }
  return result;
}

#endif
