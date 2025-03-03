template <typename T>
void Force<T>::gravity(Particle<T> &p0, Particle<T> &p1,
     double G) {
    Vector<T> r = p1.getPosition() - p0.getPosition();
    double F = G * p0.getMass() * p1.getMass();
    Vector<T> F0 = F * r / std::pow(r.norm(), 3);
    Vector<T> F1 = -F0;
    p0.addForce(F0);
    p1.addForce(F1);
}

template<typename T> // todo, why are there doubles here instead of T
void Force<T>::coulombsLaw(Electron<T> &e0, Electron<T> &e1,
     double k) {
    Vector<T> r = e0.getPosition() - e1.getPosition(); 
    //Note that it is e0 - e1 and NOT e1 - e0
    double F = k * e0.getCharge() * e1.getCharge();
    Vector<T> F0 = F * r / std::pow(r.norm(), 3);
    Vector<T> F1 = -F0;
    e0.addForce(F0);
    e1.addForce(F1);
}