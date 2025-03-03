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

TEST(SimulationTest, addElectron) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Electron<float>());
    EXPECT_EQ(sim.getNumberOfParticles(), 1);
}

TEST(SimulationTest, DefineGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Particle<float>());
    sim.addParticle(Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, NAN);
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0].getForce(), Vector<float>({0.0f, 6.67430e-11f}));
    EXPECT_EQ(sim.getParticles()[1].getForce(), Vector<float>({0.0f, -6.67430e-11f}));
}

TEST(SimulationTest, DefineCustomGravity) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Particle<float>());
    sim.addParticle(Particle<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::GRAVITY, 1.0f);
    sim.incrementTime(0.01f);
    EXPECT_EQ(sim.getParticles()[0].getForce(), Vector<float>({0.0f, 1.0f}));
    EXPECT_EQ(sim.getParticles()[1].getForce(), Vector<float>({0.0f, -1.0f}));
}

TEST(SimulationTest, DefineCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Electron<float>());
    sim.addParticle(Electron<float>(Vector<float>({0.0f, 1.0f})));
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, NAN);
    sim.incrementTime(0.01f);
    float k = 8.9875517873681764e9f;
    float q = -1.60217662e-19f;
    std::cout<<static_cast<Electron<float>>(sim.getParticles()[0]).getCharge()<<std::endl;
    std::cout<< k*q*q << std::endl;
    std::cout << sim.getParticles()[0].getForce()[1] << std::endl;
    EXPECT_EQ(sim.getParticles()[0].getForce(), Vector<float>({0.0f, -k*q*q}));
    EXPECT_EQ(sim.getParticles()[1].getForce(), Vector<float>({0.0f, k*q*q}));
}

TEST(SimulationTest, DefineCustomCoulombLaw) {
    auto sim = Simulation<float>(0.0f);
    sim.addParticle(Electron<float>(Vector<float>({0.0f, 0.0f}), 1.0f, 1.0f));
    sim.addParticle(Electron<float>(Vector<float>({0.0f, 1.0f}), 1.0f, -1.0f));
    sim.defineForce(Force<float>::ForceType::COULOMBS_LAW, 1.f);
    sim.incrementTime(0.01f);
    std::cout<<static_cast<Electron<float>>(sim.getParticles()[0]).getCharge()<<std::endl;
    std::cout<< sim.getParticles()[0].getForce()[1] << std::endl;
    EXPECT_EQ(sim.getParticles()[0].getForce(), Vector<float>({0.0f, 1.0f}));
    EXPECT_EQ(sim.getParticles()[1].getForce(), Vector<float>({0.0f, -1.0f}));
}