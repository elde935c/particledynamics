#include <gtest/gtest.h>
#include "Particle.hpp"
#include "Force.hpp"

TEST(ForceTest, Gravity) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    Particle<float> p0(position0);
    Particle<float> p1(position1);

    Force<float>::gravity(p0, p1);

    Vector<float> expectedForce(std::vector<float>{6.67430e-11, 0.0});
    EXPECT_EQ(p0.getForce(), expectedForce);
    EXPECT_EQ(p1.getForce(), -expectedForce);
}