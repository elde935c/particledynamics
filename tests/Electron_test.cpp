#include <gtest/gtest.h>
#include "Electron.hpp"

TEST(ElectronTest, DefaultConstructor) {
    Electron<float> e;
    Vector<float> expectedPosition(std::vector<float>{0.0, 0.0});
    Vector<float> expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector<float> expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 9.09e-31;
    float expectedCharge = -1.60217662e-19;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
    EXPECT_EQ(e.getCharge(), expectedCharge);
}

TEST(ElectronTest, PositionConstructor) {
    Vector<float> position(std::vector<float>{1.0, 2.0});
    Electron<float> e(position);
    Vector<float> expectedPosition(std::vector<float>{1.0, 2.0});
    Vector<float> expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector<float> expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 9.09e-31;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
}

TEST(ElectronTest, PositionMassConstructor) {
    Vector<float> position(std::vector<float>{1.0, 2.0});
    float mass = 2.0;
    Electron<float> e(position, mass);
    Vector<float> expectedPosition(std::vector<float>{1.0, 2.0});
    Vector<float> expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector<float> expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 2.0;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
}

TEST(ElectronTest, PositionMassChargeConstructor) {
    Vector<float> position(std::vector<float>{1.0, 2.0});
    float mass = 2.0;
    float charge = 3.0;
    Electron<float> e(position, mass, charge);
    Vector<float> expectedPosition(std::vector<float>{1.0, 2.0});
    Vector<float> expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector<float> expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 2.0;
    float expectedCharge = 3.0;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
    EXPECT_EQ(e.getCharge(), expectedCharge);
}


TEST(ElectronTest, PositionVelocityAccelerationMassChargeConstructor) {
    Vector<float> position(std::vector<float>{1.0, 2.0});
    Vector<float> velocity(std::vector<float>{3.0, 4.0});
    Vector<float> acceleration(std::vector<float>{5.0, 6.0});
    float mass = 2.0;
    float charge = 3.0;
    Electron<float> e(position, velocity, acceleration, mass, charge);
    Vector<float> expectedPosition(std::vector<float>{1.0, 2.0});
    Vector<float> expectedVelocity(std::vector<float>{3.0, 4.0});
    Vector<float> expectedAcceleration(std::vector<float>{5.0, 6.0});
    float expectedMass = 2.0;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
    EXPECT_EQ(e.getCharge(), charge);
}