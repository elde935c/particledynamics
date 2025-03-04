#include <gtest/gtest.h>

#include "Simulation.hpp"

TEST(SimulationTest, ConstructFloatSimulation) {
    auto sim = Simulation<float>(0.0f);
    EXPECT_EQ(sim.getTime(), 0.0f);
}

TEST(SimulationTest, ConstructDoubleSimulation) {
    auto sim = Simulation<double>(0.0);
    EXPECT_EQ(sim.getTime(), 0.0);
}

TEST(SimulationTest, AddParticle) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Particle<float>());
    EXPECT_EQ(sim.getNumberOfParticles(), 1);
}

TEST(SimulationTest, addElectron) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Electron<float>());
    EXPECT_EQ(sim.getNumberOfParticles(), 1);
}

TEST(SimulationTest, conserveParticlePropertiesGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Particle<float>());
    sim.addParticle(new Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, NAN);
    sim.incrementTime(0.0f);
    auto particles = sim.getParticles();
    EXPECT_EQ(particles[0]->getPosition(), Vector<float>({0.0f, 0.0f}));
    EXPECT_EQ(particles[0]->getVelocity(), Vector<float>({0.0f, 0.0f}));
    EXPECT_EQ(particles[0]->getMass(), 1.0f);
}

TEST(SimulationTest, conserveElectronPropertiesCoulombsLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Electron<float>());
    sim.addParticle(new Electron<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, NAN);
    sim.incrementTime(0.0f);
    auto particles = sim.getParticles();
    EXPECT_EQ(particles[0]->getPosition(), Vector<float>({0.0f, 0.0f}));
    EXPECT_EQ(particles[0]->getVelocity(), Vector<float>({0.0f, 0.0f}));
    EXPECT_EQ(particles[0]->getMass(), 9.09e-31f);
    EXPECT_EQ(static_cast<Electron<float>*>(particles[0])->getCharge(), -1.60217662e-19f);
}

TEST(SimulationTest, ApplyGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Particle<float>());
    sim.addParticle(new Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, NAN);
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0]->getForce(), Vector<float>({0.0f, 6.67430e-11f}));
    EXPECT_EQ(sim.getParticles()[1]->getForce(), Vector<float>({0.0f, -6.67430e-11f}));
}

TEST(SimulationTest, ApplyCustomGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Particle<float>());
    sim.addParticle(new Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, 1.0f);
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0]->getForce(), Vector<float>({0.0f, 1.0f}));
    EXPECT_EQ(sim.getParticles()[1]->getForce(), Vector<float>({0.0f, -1.0f}));
}

TEST(SimulationTest, ApplyCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(new Electron<float>());
    sim.addParticle(new Electron<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, NAN);
    sim.incrementTime(0.01f);
    float k = 8.9875517873681764e9f;
    float q = -1.60217662e-19f;
    EXPECT_EQ(sim.getParticles()[0]->getForce(), Vector<float>({0.0f, -k*q*q}));
    EXPECT_EQ(sim.getParticles()[1]->getForce(), Vector<float>({0.0f, k*q*q}));
}

TEST(SimulationTest, ApplyCustomCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    auto e = Electron<float>(Vector<float>({0.0f, 0.0f}), 1.0f, 1.0f);
    sim.addParticle(&e);
    sim.addParticle(new Electron<float>(Vector<float>({0.0f, 1.0f}), 1.0f, -1.0f));
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, 1.f);
    
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0]->getForce(), Vector<float>({0.0f, 1.0f}));
    EXPECT_EQ(sim.getParticles()[1]->getForce(), Vector<float>({0.0f, -1.0f}));
}