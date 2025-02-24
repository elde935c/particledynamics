template<typename T>
Simulation<T>::Simulation() : SimulationBase() {
    particles = std::vector<Particle<T>>();
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
                forceFunction = std::bind(&Force<T>::gravity, std::placeholders::_1,
                    std::placeholders::_2, parameter);
            }
            break;
        case Force<T>::ForceType::COULOMBS_LAW:
            if (std::isnan(parameter)) {
                forceFunction = [](Particle<T>& p1, Particle<T>& p2) {
                    Force<T>::coulombsLaw(static_cast<Electron<T>>(p1),
                    static_cast<Electron<T>>(p2));
                };
            }
            else {
                forceFunction = std::bind(&Force<T>::coulombsLaw, std::placeholders::_1,
                    std::placeholders::_2, parameter);
            }
            break;
        default:
            break;
    }
}

template <typename T>
void Simulation<T>::incrementTime(float dt) {
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
}