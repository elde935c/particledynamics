#include <gtest/gtest.h>
#include "Particle.hpp"

TEST(ParticleTest, DefaultConstructor) {
    Particle<float> p;
    Vector expectedPosition(std::vector<float>{0.0, 0.0});
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 1.0;

    EXPECT_EQ(p.getPosition(), expectedPosition);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), expectedMass);
}

TEST(ParticleTest, CopyConstructor) {
    Vector<float> position(std::vector<float>{1.0, 2.0});
    Vector<float> velocity(std::vector<float>{3.0, 4.0});
    Vector<float> acceleration(std::vector<float>{5.0, 6.0});
    float mass = 7.0;
    Particle<float> p1(position, velocity, acceleration, mass);
    Particle<float> p2(p1);

    EXPECT_EQ(p2.getPosition(), position);
    EXPECT_EQ(p2.getVelocity(), velocity);
    EXPECT_EQ(p2.getAcceleration(), acceleration);
    EXPECT_EQ(p2.getMass(), mass);
}

TEST (ParticleTest, MassConstructor) {
    float mass = 2.0;
    Particle<float> p(mass);
    Vector expectedPosition(std::vector<float>{0.0, 0.0});
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});

    EXPECT_EQ(p.getMass(), mass);
}

TEST(ParticleTest, PositionConstructor) {
    Vector position(std::vector<float>{1.0, 2.0});
    Particle p(position);
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});
    float expectedMass = 1.0;

    EXPECT_EQ(p.getPosition(), position);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), expectedMass);
}

TEST(ParticleTest, PositionMassConstructor) {
    Vector position(std::vector<float>{1.0, 2.0});
    float mass = 2.0;
    Particle p(position, mass);
    Vector expectedVelocity(std::vector<float>{0.0, 0.0});
    Vector expectedAcceleration(std::vector<float>{0.0, 0.0});

    EXPECT_EQ(p.getPosition(), position);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
    EXPECT_EQ(p.getMass(), mass);
}

TEST(ParticleTest, FullConstructorDoublePrecision) {
    Vector position(std::vector<double>{1.0, 2.0});
    Vector velocity(std::vector<double>{0.5, 0.5});
    Vector acceleration(std::vector<double>{0.1, 0.1});
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
    float mass = 2.0;
    Particle<float> p(initialPosition, mass);

    p.setPosition(newPosition);

    EXPECT_EQ(p.getPosition(), newPosition);
}

TEST(ParticleTest, UpdatePositionNoAcceleration) {
    Vector<float> position(std::vector<float>{0.0, 0.0});
    Vector<float> velocity(std::vector<float>{1.0, 1.0});
    Vector<float> acceleration(std::vector<float>{0.0, 0.0});
    float mass = 1.0;
    Particle<float> p(position, velocity, acceleration, mass);

    p.addForce(Vector<float>(std::vector<float>{0.0, 0.0}));

    float dt = 1.0;
    p.update(dt);

    Vector<float> expectedPosition(position + velocity*dt);
    EXPECT_EQ(p.getPosition(), expectedPosition);
}

TEST(ParticleTest, UpdateVelocityNoVelocity) {
    Particle<float> p;
    Vector<float> force(std::vector<float>{1.0, 1.0});
    p.addForce(force);

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedPosition(dt*dt*force);
    EXPECT_EQ(p.getVelocity(), expectedPosition);
}

TEST(ParticleTest, UpdatePositionAndVelocity) {
    Vector<float> position(std::vector<float>{0.0, 0.0});
    Vector<float> velocity(std::vector<float>{1.0, 1.0});
    Vector<float> acceleration(std::vector<float>{1.0, 1.0});
    float mass = 1.0;
    Particle<float> p(position, velocity, acceleration, mass);

    Vector<float> force(std::vector<float>{1.0, 1.0});
    p.addForce(force);

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedVelocity(velocity +force*dt/mass);
    Vector<float> expectedPosition(position + velocity*dt + 0.5*dt*dt*force/mass);
    Vector<float> expectedAcceleration(force/mass);
    
    EXPECT_EQ(p.getPosition(), expectedPosition);
    EXPECT_EQ(p.getVelocity(), expectedVelocity);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
}

TEST(ParticleTest, resetForce) {
    Vector<float> position(std::vector<float>{0.0, 0.0});
    Vector<float> velocity(std::vector<float>{1.0, 1.0});
    Vector<float> acceleration(std::vector<float>{1.0, 1.0});
    float mass = 1.0;
    Particle<float> p(position, velocity, acceleration, mass);

    Vector<float> force0(std::vector<float>{1.0, 1.0});
    p.addForce(force0);
    p.resetForce();
    Vector<float> force1(std::vector<float>{1.0, 1.0});
    p.addForce(force1);

    double dt = 1.0;
    p.update(dt);

    Vector<float> expectedAcceleration(force1/mass);
    EXPECT_EQ(p.getAcceleration(), expectedAcceleration);
}

