template <typename T>
void defineForce(Force<T>::ForceType forcetype, T parameter) {
    switch (forcetype) {
        case Force::ForceType::GRAVITY:
            forceFunction = Force::gravity<T>;
            break;
        case Force::ForceType::COULOMBS_LAW:
            forceFunction = Force::coulombsLaw<T>;
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