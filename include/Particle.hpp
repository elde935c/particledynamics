#pragma once

#include "Vector.h"

using namespace MyMath;

template <typename T = float>
class Particle {
private:
    Vector<T> position;
    Vector<T> velocity;
    Vector<T> acceleration;
    Vector<T> force;
    double mass;

public :
    Particle();
    Particle(Vector<T> position);
    Particle(Vector<T> position, double mass) ;   
    Particle(Vector<T> position,
             Vector<T> velocity,
             Vector<T> acceleration,
             double mass);

    Vector<T> getPosition();
    Vector<T> getVelocity();
    Vector<T> getAcceleration();
    double getMass();

    void setPosition(Vector<T> position);
    void setVelocity(Vector<T> velocity);
    void setAcceleration(Vector<T> acceleration);
    void setMass(double mass);
    void setForce(Vector<T> force);

    void update(double dt);
};

#include "Particle.impl.hpp"