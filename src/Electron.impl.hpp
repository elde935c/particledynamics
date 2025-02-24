template<typename T>
Electron<T>::Electron() : Particle<T>(9.09e-31) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(const Particle<T> p) : Particle<T>(p) {
    charge = -1.60217662e-19;
    this->mass = 9.09e-31;
}

template<typename T>
Electron<T>::Electron(Vector<T> position) : 
    Particle<T>(position, 9.09e-31) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(Vector<T> position, T mass) :
    Particle<T>(position, mass) {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(Vector<T> position, T mass, T charge) :
    Particle<T>(position, mass) {
    this->charge = charge;
}   

template<typename T>
Electron<T>::Electron(Vector<T> position, 
        Vector<T> velocity, 
        Vector<T> acceleration, 
        T mass, 
        T charge)
    : Particle<T>(position, velocity, acceleration, mass) {
        this->charge = charge;
}

template<typename T>
T Electron<T>::getCharge() {
    return charge;
}

template<typename T>
void Electron<T>::setCharge(T charge) {
    this->charge = charge;
}