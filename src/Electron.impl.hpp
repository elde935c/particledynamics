template<typename T>
Electron<T>::Electron() : Particle<T>() {
    charge = -1.60217662e-19;
}

template<typename T>
Electron<T>::Electron(Vector<T> position) : Particle<T>(position) {
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
    charge = charge;
}   

template<typename T>
Electron<T>::Electron(Vector<T> position, 
        Vector<T> velocity, 
        Vector<T> acceleration, 
        T mass, 
        T charge)
    : Particle<T>(position, velocity, acceleration, mass) {
        charge = -1.60217662e-19;
}

template<typename T>
T Electron<T>::getCharge() {
    return charge;
}

template<typename T>
void Electron<T>::setCharge(T charge) {
    charge = charge;
}