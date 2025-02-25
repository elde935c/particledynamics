#pragma once

#include "Particle.hpp"

using namespace MyMath;

template <typename T = float>
class Electron : public Particle<T> {
    private :
        T charge;
    public:
        Electron();
        Electron(const Particle<T> p);
        Electron(const Electron<T> e);
        Electron(Vector<T> position);
        Electron(Vector<T> position, T mass);
        Electron(Vector<T> position, T mass, T charge);
        Electron(Vector<T> position,
                Vector<T> velocity,
                Vector<T> acceleration,
                T mass,
                T charge);
            
        T getCharge();
        void setCharge(T charge);
};

#include "Electron.impl.hpp"