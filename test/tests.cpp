// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>

#include "circle.h"
#include "tasks.h"

const double EPS = 0.001;

// -----------------------------
// ТЕСТЫ КЛАССА CIRCLE
// -----------------------------

TEST(CircleTest, ConstructorRadius3) {
  Circle c(3.0);
  EXPECT_NEAR(3.0, c.getRadius(), EPS);
}

TEST(CircleTest, ConstructorRadius7) {
  Circle c(7.0);
  EXPECT_NEAR(7.0, c.getRadius(), EPS);
}

TEST(CircleTest, RadiusUpdatesFerence) {
  Circle c(0);
  c.setRadius(3.0);
  EXPECT_NEAR(18.8496, c.getFerence(), EPS);
}

TEST(CircleTest, RadiusUpdatesArea) {
  Circle c(0);
  c.setRadius(3.0);
  EXPECT_NEAR(28.2743, c.getArea(), EPS);
}

TEST(CircleTest, FerenceUpdatesRadius) {
  Circle c(0);
  c.setFerence(18.8496);
  EXPECT_NEAR(3.0, c.getRadius(), EPS);
}

TEST(CircleTest, FerenceUpdatesArea) {
  Circle c(0);
  c.setFerence(18.8496);
  EXPECT_NEAR(28.2743, c.getArea(), EPS);
}

TEST(CircleTest, AreaUpdatesRadius) {
  Circle c(0);
  c.setArea(78.5398);
  EXPECT_NEAR(5.0, c.getRadius(), EPS);
}

TEST(CircleTest, AreaUpdatesFerence) {
  Circle c(0);
  c.setArea(78.5398);
  EXPECT_NEAR(31.4159, c.getFerence(), EPS);
}

TEST(CircleTest, SmallRadiusValue) {
  Circle c(0.05);
  EXPECT_GT(c.getArea(), 0.0);
}

TEST(CircleTest, VeryLargeRadius) {
  Circle c(50000);
  EXPECT_GT(c.getFerence(), 300000);
}

TEST(CircleTest, MultipleChanges) {
  Circle c(2);
  c.setRadius(6);
  c.setFerence(12);
  EXPECT_GT(c.getArea(), 10);
}

TEST(CircleTest, AreaPositive) {
  Circle c(2);
  EXPECT_GT(c.getArea(), 0);
}

// -----------------------------
// ТЕСТЫ ЗАДАЧИ "ЗЕМЛЯ И ВЕРЕВКА"
// -----------------------------

TEST(EarthTaskTest, ThreeMeterGap) {
  double gap = calculateEarthGap(6378.1, 3.0);
  EXPECT_NEAR(0.47746, gap, 0.001);
}

TEST(EarthTaskTest, FourMeterGap) {
  double gap = calculateEarthGap(6378.1, 4.0);
  EXPECT_NEAR(0.63662, gap, 0.001);
}

TEST(EarthTaskTest, TenMeterGap) {
  double gap = calculateEarthGap(6378.1, 10.0);
  EXPECT_NEAR(1.59155, gap, 0.001);
}

TEST(EarthTaskTest, SmallPlanetGap) {
  double gap = calculateEarthGap(200.0, 3.0);
  EXPECT_NEAR(0.47746, gap, 0.001);
}

TEST(EarthTaskTest, LargePlanetGap) {
  double gap = calculateEarthGap(50000.0, 3.0);
  EXPECT_NEAR(0.47746, gap, 0.001);
}

TEST(EarthTaskTest, FiftyMetersAdded) {
  double gap = calculateEarthGap(6378.1, 50.0);
  EXPECT_NEAR(7.95775, gap, 0.001);
}

TEST(EarthTaskTest, ZeroAddedLength) {
  double gap = calculateEarthGap(6378.1, 0.0);
  EXPECT_NEAR(0.0, gap, EPS);
}

// -----------------------------
// ТЕСТЫ ЗАДАЧИ "БАССЕЙН"
// -----------------------------

TEST(PoolTaskTest, StandardRoadCost) {
  Pool res = calculateCostOfPool(4.0, 2.0);
  EXPECT_NEAR(62831.85, res.costOfRoad, 0.5);
}

TEST(PoolTaskTest, StandardFenceCost) {
  Pool res = calculateCostOfPool(4.0, 2.0);
  EXPECT_NEAR(75398.22, res.costOfFence, 0.5);
}

TEST(PoolTaskTest, NoPathCost) {
  Pool res = calculateCostOfPool(5.0, 0.0);
  EXPECT_NEAR(0.0, res.costOfRoad, EPS);
}

TEST(PoolTaskTest, SmallPoolCost) {
  Pool res = calculateCostOfPool(1.0, 0.3);
  EXPECT_GT(res.costOfRoad, 0);
}

TEST(PoolTaskTest, FenceCostPositive) {
  Pool res = calculateCostOfPool(2.0, 1.0);
  EXPECT_GT(res.costOfFence, 0);
}

TEST(PoolTaskTest, LargePoolFence) {
  Pool res = calculateCostOfPool(8.0, 1.5);
  EXPECT_GT(res.costOfFence, 100000);
}
