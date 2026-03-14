// Copyright 2022 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double calculateEarthGap(double earthRadius, double addedLength);

struct Pool {
  double costOfRoad;
  double costOfFence;
};

Pool calculateCostOfPool(double poolRadius, double pathWidth);

#endif // INCLUDE_TASKS_H_
