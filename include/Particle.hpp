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
    Particle(T mass);
    Particle(Vector<T> position);
    Particle(Vector<T> position, T mass) ;   
    Particle(Vector<T> position,
             Vector<T> velocity,
             Vector<T> acceleration,
             T mass);

    const Vector<T>& getPosition();
    Vector<T> getVelocity();
    Vector<T> getAcceleration();
    Vector<T> getForce();
    T getMass();

    void setPosition(Vector<T> position);
    void setVelocity(Vector<T> velocity);
    void setAcceleration(Vector<T> acceleration);
    void setMass(T mass);
    void resetForce();
    void addForce(Vector<T> additionalForce);

    void update(double dt);
};

#include "Particle.impl.hpp"