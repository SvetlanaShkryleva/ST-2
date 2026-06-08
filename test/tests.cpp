// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>

#include "circle.h"
#include "tasks.h"

const double TOLERANCE = 0.001;

// ============================================================
// Тесты для класса Circle (работа с радиусом, длиной, площадью)
// ============================================================

TEST(CircleCheck, ConstructWithRadius2) {
    Circle c(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, TOLERANCE);
}

TEST(CircleCheck, ConstructWithRadius5) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, TOLERANCE);
}

TEST(CircleCheck, SetRadiusUpdatesLength) {
    Circle c(0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getFerence(), 12.56637, TOLERANCE);
}

TEST(CircleCheck, SetRadiusUpdatesArea) {
    Circle c(0);
    c.setRadius(2.0);
    EXPECT_NEAR(c.getArea(), 12.56637, TOLERANCE);
}

TEST(CircleCheck, SetLengthUpdatesRadius) {
    Circle c(0);
    c.setFerence(12.56637);
    EXPECT_NEAR(c.getRadius(), 2.0, TOLERANCE);
}

TEST(CircleCheck, SetLengthUpdatesArea) {
    Circle c(0);
    c.setFerence(12.56637);
    EXPECT_NEAR(c.getArea(), 12.56637, TOLERANCE);
}

TEST(CircleCheck, SetAreaUpdatesRadius) {
    Circle c(0);
    c.setArea(78.53982);
    EXPECT_NEAR(c.getRadius(), 5.0, TOLERANCE);
}

TEST(CircleCheck, SetAreaUpdatesLength) {
    Circle c(0);
    c.setArea(78.53982);
    EXPECT_NEAR(c.getFerence(), 31.41593, TOLERANCE);
}

TEST(CircleCheck, TinyRadiusWorks) {
    Circle c(0.1);
    EXPECT_GT(c.getArea(), 0.0);
    EXPECT_LT(c.getArea(), 1.0);
}

TEST(CircleCheck, HugeRadiusWorks) {
    Circle c(10000.0);
    EXPECT_GT(c.getFerence(), 60000.0);
}

TEST(CircleCheck, SequentialChanges) {
    Circle c(3.0);
    c.setRadius(4.0);
    c.setFerence(30.0);
    EXPECT_GT(c.getArea(), 70.0);
}

TEST(CircleCheck, AreaAlwaysPositive) {
    Circle c(0.5);
    EXPECT_GT(c.getArea(), 0.0);
}

// ============================================================
// Тесты для задачи "Земля и верёвка" (зазор при удлинении)
// ============================================================

TEST(EarthRope, Add5Meters) {
    double gap = calculateEarthGap(6378.1, 5.0);
    EXPECT_NEAR(gap, 0.79577, 0.001);
}

TEST(EarthRope, Add6Meters) {
    double gap = calculateEarthGap(6378.1, 6.0);
    EXPECT_NEAR(gap, 0.95493, 0.001);
}

TEST(EarthRope, Add15Meters) {
    double gap = calculateEarthGap(6378.1, 15.0);
    EXPECT_NEAR(gap, 2.38732, 0.001);
}

TEST(EarthRope, Add30Meters) {
    double gap = calculateEarthGap(6378.1, 30.0);
    EXPECT_NEAR(gap, 4.77465, 0.001);
}

TEST(EarthRope, SmallPlanetSameGap) {
    double gap = calculateEarthGap(300.0, 5.0);
    EXPECT_NEAR(gap, 0.79577, 0.001);
}

TEST(EarthRope, GiantPlanetSameGap) {
    double gap = calculateEarthGap(100000.0, 5.0);
    EXPECT_NEAR(gap, 0.79577, 0.001);
}

TEST(EarthRope, NoAddition) {
    double gap = calculateEarthGap(6378.1, 0.0);
    EXPECT_NEAR(gap, 0.0, TOLERANCE);
}

TEST(EarthRope, NegativeAddition) {
    double gap = calculateEarthGap(6378.1, -3.0);
    EXPECT_NEAR(gap, -0.47746, 0.001);
}

// ============================================================
// Тесты для задачи "Бассейн" (стоимость дорожки и забора)
// ============================================================

TEST(PoolCost, Radius6mPath2m) {
    Pool res = calculateCostOfPool(6.0, 2.0);
    EXPECT_NEAR(res.costOfRoad, 87964.6, 0.5);
    EXPECT_NEAR(res.costOfFence, 100531.0, 0.5);
}

TEST(PoolCost, Radius5mPath1m) {
    Pool res = calculateCostOfPool(5.0, 1.0);
    EXPECT_NEAR(res.costOfRoad, 34557.5, 0.5);
    EXPECT_NEAR(res.costOfFence, 75398.2, 0.5);
}

TEST(PoolCost, NoPath) {
    Pool res = calculateCostOfPool(5.0, 0.0);
    EXPECT_NEAR(res.costOfRoad, 0.0, TOLERANCE);
    EXPECT_NEAR(res.costOfFence, 62831.85, 0.5);
}

TEST(PoolCost, TinyPool) {
    Pool res = calculateCostOfPool(1.0, 0.5);
    EXPECT_GT(res.costOfRoad, 0.0);
    EXPECT_GT(res.costOfFence, 0.0);
}

TEST(PoolCost, LargePoolFenceExpensive) {
    Pool res = calculateCostOfPool(10.0, 2.0);
    EXPECT_GT(res.costOfFence, 150000.0);
}

TEST(PoolCost, PathWidthZeroCostRoadZero) {
    Pool res = calculateCostOfPool(4.0, 0.0);
    EXPECT_NEAR(res.costOfRoad, 0.0, TOLERANCE);
}
