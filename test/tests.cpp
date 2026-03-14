// Copyright 2025 UNN-CS Team

#include <cstdint>
#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

const double EPS = 0.001;

// -----------------------------
// ТЕСТЫ КЛАССА CIRCLE
// -----------------------------

TEST(CircleTest, ConstructorRadius5) {
  Circle c(5.0);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, ConstructorRadius12) {
  Circle c(12.0);
  EXPECT_NEAR(12.0, c.getRadius(), EPS);
}

TEST(CircleTest, RadiusUpdatesFerence) {
  Circle c(0);
  c.setRadius(4.0);
  EXPECT_NEAR(25.1327, c.getFerence(), EPS);
}

TEST(CircleTest, RadiusUpdatesArea) {
  Circle c(0);
  c.setRadius(4.0);
  EXPECT_NEAR(50.2654, c.getArea(), EPS);
}

TEST(CircleTest, FerenceUpdatesRadius) {
  Circle c(0);
  c.setFerence(31.4159);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, FerenceUpdatesArea) {
  Circle c(0);
  c.setFerence(31.4159);
  EXPECT_NEAR(78.5398, c.getArea(), EPS);
}

TEST(CircleTest, AreaUpdatesRadius) {
  Circle c(0);
  c.setArea(314.159);
  EXPECT_NEAR(10.0, c.getRadius(), EPS);
}

TEST(CircleTest, AreaUpdatesFerence) {
  Circle c(0);
  c.setArea(314.159);
  EXPECT_NEAR(62.8318, c.getFerence(), EPS);
}

TEST(CircleTest, SmallRadiusValue) {
  Circle c(0.01);
  EXPECT_GT(c.getArea(), 0.0);
}

TEST(CircleTest, VeryLargeRadius) {
  Circle c(100000);
  EXPECT_GT(c.getFerence(), 600000);
}

TEST(CircleTest, MultipleChanges) {
  Circle c(2);
  c.setRadius(6);
  c.setFerence(12);
  EXPECT_GT(c.getArea(), 10);
}

TEST(CircleTest, AreaPositive) {
  Circle c(8);
  EXPECT_GT(c.getArea(), 0);
}

// -----------------------------
// ТЕСТЫ ЗАДАЧИ "ЗЕМЛЯ И ВЕРЕВКА"
// -----------------------------

TEST(EarthTaskTest, OneMeterGap) {
  double gap = calculateEarthGap(6378.1, 1.0);
  EXPECT_NEAR(0.15915, gap, 0.001);
}

TEST(EarthTaskTest, TwoMeterGap) {
  double gap = calculateEarthGap(6378.1, 2.0);
  EXPECT_NEAR(0.31831, gap, 0.001);
}

TEST(EarthTaskTest, FiveMeterGap) {
  double gap = calculateEarthGap(6378.1, 5.0);
  EXPECT_NEAR(0.79577, gap, 0.001);
}

TEST(EarthTaskTest, SmallPlanetGap) {
  double gap = calculateEarthGap(100.0, 1.0);
  EXPECT_NEAR(0.15915, gap, 0.001);
}

TEST(EarthTaskTest, LargePlanetGap) {
  double gap = calculateEarthGap(20000.0, 1.0);
  EXPECT_NEAR(0.15915, gap, 0.001);
}

TEST(EarthTaskTest, HundredMetersAdded) {
  double gap = calculateEarthGap(6378.1, 100.0);
  EXPECT_NEAR(15.9155, gap, 0.001);
}

TEST(EarthTaskTest, ZeroAddedLength) {
  double gap = calculateEarthGap(6378.1, 0.0);
  EXPECT_NEAR(0.0, gap, EPS);
}

// -----------------------------
// ТЕСТЫ ЗАДАЧИ "БАССЕЙН"
// -----------------------------

TEST(PoolTaskTest, StandardRoadCost) {
  Pool res = calculateCostOfPool(3.0, 1.0);
  EXPECT_NEAR(21991.14, res.costOfRoad, 0.5);
}

TEST(PoolTaskTest, StandardFenceCost) {
  Pool res = calculateCostOfPool(3.0, 1.0);
  EXPECT_NEAR(50265.48, res.costOfFence, 0.5);
}

TEST(PoolTaskTest, NoPathCost) {
  Pool res = calculateCostOfPool(4.0, 0.0);
  EXPECT_NEAR(0.0, res.costOfRoad, EPS);
}

TEST(PoolTaskTest, SmallPoolCost) {
  Pool res = calculateCostOfPool(1.0, 0.5);
  EXPECT_GT(res.costOfRoad, 0);
}

TEST(PoolTaskTest, FenceCostPositive) {
  Pool res = calculateCostOfPool(3.0, 1.0);
  EXPECT_GT(res.costOfFence, 0);
}

TEST(PoolTaskTest, LargePoolFence) {
  Pool res = calculateCostOfPool(10.0, 2.0);
  EXPECT_GT(res.costOfFence, 70000);
}
