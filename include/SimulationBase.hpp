#pragma once

class SimulationBase {

    public: 
        SimulationBase() {}

        virtual void incrementTime(float dt) = 0;

};

#include "SimulationBase.impl.hpp"