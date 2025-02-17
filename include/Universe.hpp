#pragma once

#include "Particle.hpp"
#include "Force.hpp"

using namespace MyMath;

class Universe {
    public:
        Universe();

        void addStandardParticle();

        void setForce(ForceType forceType); 


    private:
        std::vector<Particle<T>> particles;
        std::function force;
        double time;
};


#include "Universe.impl.hpp"