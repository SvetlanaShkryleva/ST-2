// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double calculateEarthGap(double earthRadius, double addedLength) {
  Circle earth(earthRadius * 1000);

  double initialFerence = earth.getFerence();
  earth.setFerence(initialFerence + addedLength);

  double gap = earth.getRadius() - (earthRadius * 1000);
  return gap;
}

Pool calculateCostOfPool(double poolRadius, double pathWidth) {
  Circle pool(poolRadius);
  Circle outerCircle(poolRadius + pathWidth);

  double concreteArea = outerCircle.getArea() - pool.getArea();
  double fenceLength = outerCircle.getFerence();

  Pool res;
  res.costOfRoad = concreteArea * 1000;
  res.costOfFence = fenceLength * 2000;
  return res;
}