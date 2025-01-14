#pragma once

#include "Vector.h"
#include "Particle.hpp"

using namespace MyMath;

template <typename T>
class Force {
    public:
        static void gravity(Particle<T> &p0, Particle<T> &p1);
};

#include "Force.impl.hpp"	