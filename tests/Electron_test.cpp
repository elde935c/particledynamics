#include <gtest/gtest.h>
#include "Electron.hpp"

TEST(ElectronTest, DefaultConstructor) {
    Electron<float> e;
    Vector<float> expectedPosition(std::vector<float>{0.0, 0.0});
    Vector<float> expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector<float> expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 1.0;
    float expectedCharge = -1.60217662e-19;

    EXPECT_EQ(e.getPosition(), expectedPosition);
    EXPECT_EQ(e.getVelocity(), expectedVelocity);
    EXPECT_EQ(e.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(e.getMass(), expectedMass);
    EXPECT_EQ(e.getCharge(), expectedCharge);
}