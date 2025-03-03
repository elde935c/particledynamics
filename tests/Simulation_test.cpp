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
    sim.addParticle(Particle<float>());
    EXPECT_EQ(sim.getNumberOfParticles(), 1);
}

TEST(SimulationTest, DefineGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Particle<float>());
    sim.addParticle(Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, NAN);
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0].getForce(), Vector<float>({6.67430e-11, 0.0f}));
    EXPECT_EQ(sim.getParticles()[1].getForce(), Vector<float>({-6.67430e-11, 0.0f}));
}

TEST(SimulationTest, DefineCustomGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.defineForce(Force<float>::ForceType::GRAVITY, 1.);
}

TEST(SimulationTest, DefineCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, NAN);
}

TEST(SimulationTest, DefineCustomCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, 1.);
}