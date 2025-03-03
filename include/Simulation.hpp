#pragma once

#include <functional>

#include "SimulationBase.hpp"
#include "Particle.hpp"
#include "Force.hpp"

template <typename T = float>
class Simulation : public SimulationBase {
    public:
        Simulation(T time = 0);

        T getTime();

        int getNumberOfParticles();

        std::vector<Particle<T>> getParticles();

        void addParticle(Particle<T> particle);

        void defineForce(typename Force<T>::ForceType forcetype,
             T parameter);

        void incrementTime(T dt);

    private:
        T time;
        std::vector<Particle<T>> particles;
        // todo change to general number of arguments
        std::function<void(Particle<T>&, Particle<T>&)> forceFunction;
};

#include "Simulation.impl.hpp"