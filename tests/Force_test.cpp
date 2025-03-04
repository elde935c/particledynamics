#include <gtest/gtest.h>
#include "Particle.hpp"
#include "Electron.hpp"
#include "Force.hpp"

TEST(ForceTest, Gravity) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    Particle<float> p0(position0);
    Particle<float> p1(position1);

    Force<float>::gravity(&p0, &p1);

    Vector<float> expectedForce(std::vector<float>{6.67430e-11, 0.0});
    EXPECT_EQ(p0.getForce(), expectedForce);
    EXPECT_EQ(p1.getForce(), -expectedForce);
}


TEST(ForceTest, CustomGravity) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    Particle<float> p0(position0);
    Particle<float> p1(position1);

    double G = 1.;

    Force<float>::gravity(&p0, &p1, G);

    Vector<float> expectedForce(std::vector<float>{1., 0.0});
    EXPECT_EQ(p0.getForce(), expectedForce);
    EXPECT_EQ(p1.getForce(), -expectedForce);
}

TEST(ForceTest, CustomGravity2) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{2.0, 0.0});
    Particle<float> p0(position0);
    Particle<float> p1(position1);

    double G = 1.;

    Force<float>::gravity(&p0, &p1, G);

    Vector<float> expectedForce(std::vector<float>{0.25, 0.0});
    EXPECT_EQ(p0.getForce(), expectedForce);
    EXPECT_EQ(p1.getForce(), -expectedForce);
}

TEST(ForceTest, CoulombsLaw) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    Electron<float> p0(position0);
    Electron<float> p1(position1);

    Force<float>::coulombsLaw(&p0, &p1);

    float k = 8.9875517873681764e9;
    float q = -1.60217662e-19;
    float F = k * q * q;

    Vector<float> expectedForce(std::vector<float>{F, 0.0});
    EXPECT_EQ(p0.getForce(), -expectedForce);
    EXPECT_EQ(p1.getForce(), expectedForce);
}

TEST(ForceTest , CustomCoulombsLawPositiveCharge) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    float mass = 1.;
    float charge = 1.;
    Electron<float> p0(position0, mass, charge);
    Electron<float> p1(position1, mass, charge);

    Force<float>::coulombsLaw(&p0, &p1, 1.);

    Vector<float> expectedForce(std::vector<float>{1.0, 0.0});
    EXPECT_EQ(p0.getForce(), -expectedForce);
    EXPECT_EQ(p1.getForce(), expectedForce);
}

TEST(ForceTest , CustomCoulombsLawNegativeCharge) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    float mass = 1.;
    float charge = -1.;
    Electron<float> p0(position0, mass, charge);
    Electron<float> p1(position1, mass, charge);

    Force<float>::coulombsLaw(&p0, &p1, 1.);

    Vector<float> expectedForce(std::vector<float>{1.0, 0.0});
    EXPECT_EQ(p0.getForce(), -expectedForce);
    EXPECT_EQ(p1.getForce(), expectedForce);
}

TEST(ForceTest , CustomCoulombsLawMixedCharge) {
    Vector<float> position0(std::vector<float>{0.0, 0.0});
    Vector<float> position1(std::vector<float>{1.0, 0.0});
    float mass = 1.;
    float charge = -1.;
    Electron<float> p0(position0, mass, charge);
    Electron<float> p1(position1, mass, -charge);

    Force<float>::coulombsLaw(&p0, &p1, 1.);

    Vector<float> expectedForce(std::vector<float>{1.0, 0.0});
    EXPECT_EQ(p0.getForce(), expectedForce);
    EXPECT_EQ(p1.getForce(), -expectedForce);
}