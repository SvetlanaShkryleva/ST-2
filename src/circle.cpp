// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double Circle::pi = 3.14159265358979323846;

Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  radius = r;
  ference = 2 * pi * radius;
  area = pi * radius * radius;
}

void Circle::setFerence(double f) {
  ference = f;
  radius = ference / (2 * pi);
  area = pi * radius * radius;
}

void Circle::setArea(double a) {
  area = a;
  radius = sqrt(area / pi);
  ference = 2 * pi * radius;
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
