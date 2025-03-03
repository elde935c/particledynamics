template<typename T>
Simulation<T>::Simulation(T time) : SimulationBase() {
    this->time = time;
}

template<typename T>
T Simulation<T>::getTime() {
    return time;
}

template<typename T>
int Simulation<T>::getNumberOfParticles() {
    return particles.size();
}

template<typename T>
std::vector<Particle<T>> Simulation<T>::getParticles() {
    return particles;
}

template<typename T>
void Simulation<T>::addParticle(Particle<T> particle) {
    particles.push_back(particle);
}

template <typename T>
void Simulation<T>::defineForce(typename Force<T>::ForceType forcetype,
     T parameter) {
    switch (forcetype) {
        case Force<T>::ForceType::GRAVITY:
            if (std::isnan(parameter)) {
                forceFunction = [](Particle<T>& p1, Particle<T>& p2) {
                    Force<T>::gravity(p1, p2);
                };
            }
            else {
                forceFunction = [parameter](Particle<T>& p1, Particle<T>& p2) {
                    Force<T>::gravity(p1, p2, parameter);
                };
            }
            break;
        case Force<T>::ForceType::COULOMBS_LAW:
            if (std::isnan(parameter)) {
                forceFunction = [](Particle<T>& p1, Particle<T>& p2) {
                    Force<T>::coulombsLaw(static_cast<Electron<T>&>(p1),
                    static_cast<Electron<T>&>(p2));
                };
            }
            else {
                forceFunction = [parameter](Particle<T>& p1, Particle<T>& p2) {
                    Force<T>::coulombsLaw(static_cast<Electron<T>&>(p1),
                     static_cast<Electron<T>&>(p2), parameter);
                };
            }
            break;
        default:
            break;
    }
}

template <typename T>
void Simulation<T>::incrementTime(T dt) {
    for (auto &particle : particles) {
        particle.resetForce();
    }

    for (int i = 0; i < particles.size(); i++) {
        for (int j = i + 1; j < particles.size(); j++) {
            forceFunction(particles[i], particles[j]);
        }
    }

    for (auto &particle : particles) {
        particle.update(dt);
    }

    time += dt;
}