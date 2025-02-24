#pragma once

#include "Particle.hpp"
#include "Electron.hpp"

using namespace MyMath;

template <typename T>
class Force {
    public:
        static void gravity(Particle<T> &p0, Particle<T> &p1,
             double G = 6.67430e-11);

        static void coulombsLaw(Electron<T> &e0, Electron<T> &e1,
             double k = 8.9875517873681764e9);

        enum class ForceType {
            GRAVITY,
            COULOMBS_LAW
        };
};

#include "Force.impl.hpp"