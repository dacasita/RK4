#define _USE_MATH_DEFINES
#include <cmath>
#include "../matplotlibcpp.h"
#include "myfunctions.h"
#include <complex>
#include <unordered_map>
#include <iostream>

namespace plt = matplotlibcpp;
#include <opencv2/opencv.hpp>

using namespace cv;

int main() 
{
  double x0 = 1;
  double y0 = 1;
  double xLast = 1.1;
  double h = 0.05;

  SlopeFunction chosenSlopeF = fExample;
  //euler(x0, y0, xLast, h, chosenSlopeF);

  x0 = 0;
  y0 = 0;
  xLast = 10;
  h = 0.01;

  chosenSlopeF = slopeF;
  RK4(x0, y0, xLast, h, chosenSlopeF);

  return 0;
}