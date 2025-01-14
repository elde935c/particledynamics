#include <gtest/gtest.h>
#include "Particle.hpp"
// #include "Vector.h"

TEST(ParticleTest, DefaultConstructor) {
    Particle<float> p;
    Vector expectedPosition(std::vector<float>{0.0, 0.0});
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});
    double expectedMass = 1.0;

    EXPECT_EQ(p.getPosition(), expectedPosition);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), expectedMass);
}

TEST(ParticleTest, PositionConstructor) {
    Vector position(std::vector<float>{1.0, 2.0});
    Particle p(position);
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});
    double expectedMass = 1.0;

    EXPECT_EQ(p.getPosition(), position);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), expectedMass);
}

TEST(ParticleTest, PositionMassConstructor) {
    Vector position(std::vector<float>{1.0, 2.0});
    double mass = 2.0;
    Particle p(position, mass);
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});

    EXPECT_EQ(p.getPosition(), position);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), mass);
}

TEST(ParticleTest, FullConstructor) {
    Vector position(std::vector<float>{1.0, 2.0});
    Vector velocity(std::vector<float>{0.5, 0.5});
    Vector acceleration(std::vector<float>{0.1, 0.1});
    double mass = 2.0;
    Particle p(position, velocity, acceleration, mass);

    EXPECT_EQ(p.getPosition(), position);
    EXPECT_EQ(p.getVelocity(), velocity);
    EXPECT_EQ(p.getAcceleration(), acceleration);
    EXPECT_EQ(p.getMass(), mass);
}

TEST(ParticleTest, SetPosition) {
    Vector<float> initialPosition(std::vector<float>{1.0, 2.0});
    Vector<float> newPosition(std::vector<float>{3.0, 4.0});
    double mass = 2.0;
    Particle<float> p(initialPosition, mass);

    p.setPosition(newPosition);

    EXPECT_EQ(p.getPosition(), newPosition);
}

TEST(ParticleTest, UpdatePositionNoAcceleration) {
    Vector<float> position(std::vector<float>{0.0, 0.0});
    Vector<float> velocity(std::vector<float>{1.0, 1.0});
    Vector<float> acceleration(std::vector<float>{0.0, 0.0});
    double mass = 1.0;
    Particle<float> p(position, velocity, acceleration, mass);

    p.setForce(Vector<float>(std::vector<float>{0.0, 0.0}));

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedPosition(position + velocity*dt);
    EXPECT_EQ(p.getPosition(), expectedPosition);
}

TEST(ParticleTest, UpdateVelocityNoVelocity) {
    Particle<float> p;
    Vector<float> force(std::vector<float>{1.0, 1.0});
    p.setForce(force);

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedPosition(dt*dt*force);
    EXPECT_EQ(p.getVelocity(), expectedPosition);
}

TEST(ParticleTest, UpdatePositionAndVelocity) {
    Vector<float> position(std::vector<float>{0.0, 0.0});
    Vector<float> velocity(std::vector<float>{1.0, 1.0});
    Vector<float> acceleration(std::vector<float>{1.0, 1.0});
    double mass = 1.0;
    Particle<float> p(position, velocity, acceleration, mass);

    Vector<float> force(std::vector<float>{1.0, 1.0});
    p.setForce(force);

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedVelocity(velocity +force*dt/mass);
    Vector<float> expectedPosition(position + velocity*dt + 0.5*dt*dt*force/mass);
    Vector<float> expectedAcceleration(force/mass);
    
    EXPECT_EQ(p.getPosition(), expectedPosition);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
}