#pragma once

#include "Particle.hpp"

using namespace MyMath;

template <typename T>
class Force {
    public:
        static void gravity(Particle<T> &p0, Particle<T> &p1,
             double G = 6.67430e-11);
};

#include "Force.impl.hpp"