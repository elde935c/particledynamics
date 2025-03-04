#pragma once

#include "Vector.h"

using namespace MyMath;

template <typename T = float>
class Particle {
protected:
    Vector<T> position;
    Vector<T> velocity;
    Vector<T> acceleration;
    Vector<T> force;
    T mass;

public :
    Particle();
    Particle(const Particle<T> &p);
    Particle(const T mass);
    Particle(const Vector<T> &position);
    Particle(const Vector<T> & position, const T mass) ;   
    Particle(const Vector<T> & position,
             const Vector<T> & velocity,
             const Vector<T> &acceleration,
             const T mass);

    Vector<T> getPosition();
    Vector<T> getVelocity();
    Vector<T> getAcceleration();
    Vector<T> getForce();
    T getMass();

    void resetForce();
    void addForce(const Vector<T> & additionalForce);

    void update(const T dt);
};

#include "Particle.impl.hpp"