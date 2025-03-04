template<typename T>
Electron<T>::Electron() : Particle<T>(9.09e-31) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(const Particle<T> &p) : Particle<T>(p) {
    this->charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(const Electron<T> &e) : 
    Particle<T>(e.position, e.velocity, e.acceleration, e.mass) {
    this->force = e.force;
    this->charge = e.charge;
}

template<typename T>
Electron<T>::Electron(const Vector<T> &position) : 
    Particle<T>(position, 9.09e-31) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(const Vector<T> &position, const T mass) :
    Particle<T>(position, mass) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(const Vector<T> &position, const T mass, const T charge) :
    Particle<T>(position, mass) {
    this->charge = charge;
}   

template<typename T>
Electron<T>::Electron(const Vector<T> &position, 
    const Vector<T> &velocity, 
    const Vector<T> &acceleration, 
    const T mass, 
    const T charge)
    : Particle<T>(position, velocity, acceleration, mass) {
        this->charge = charge;
}

template<typename T>
T Electron<T>::getCharge() {
    return charge;
}