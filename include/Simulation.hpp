#pragma once

#include <functional>

#include "Simulation.hpp"
#include "Particle.hpp"
#include "Force.hpp"

template <typename T = float>
class Simulation : public SimulationBase {
    public:
        Simulation : SimulationBase() {}

        void incrementTime(float dt) override;

        void defineForce(Force<T>::ForceType forcetype, T parameter);

    private:
        std::vector<Particle<T>> particles;
        // todo change to general number of arguments
        std::function<void(Particle<T>&, Particle<T>&)> forceFunction;
};

#include "Simulation.impl.hpp"