#pragma once

#include "Particle.hpp"

using namespace MyMath;

template <typename T = float>
class Electron : public Particle<T> {
    private :
        T charge;
    public:
        Electron();
        Electron(const Particle<T> &p);
        Electron(const Electron<T> &e);
        Electron(const Vector<T> &position);
        Electron(const Vector<T> &position, const T mass);
        Electron(const Vector<T> &position, const T mass, const T charge);
        Electron(const Vector<T> &position,
            const Vector<T> &velocity,
            const Vector<T> &acceleration,
            const T mass,
            const T charge);
            
        T getCharge();
};

#include "Electron.impl.hpp"