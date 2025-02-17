template <typename T>
void Force<T>::gravity(Particle<T> &p0, Particle<T> &p1,
     double G) {
    Vector<T> r = p1.getPosition() - p0.getPosition();
    double r2 = dot(r, r);
    double F = G * p0.getMass() * p1.getMass() / r2;
    Vector<T> F0 = F * r / r2;
    Vector<T> F1 = -F0;
    p0.addForce(F0);
    p1.addForce(F1);
}

template<typename T>
void Force<T>::coulombsLaw(Electron<T> &e0, Electron<T> &e1,
     double k) {
    Vector<T> r = e1.getPosition() - e0.getPosition();
    double r2 = dot(r, r);
    double F = k * e0.getCharge() * e1.getCharge() / r2;
    Vector<T> F0 = F * r / r2;
    Vector<T> F1 = -F0;
    e0.addForce(F0);
    e0.addForce(F1);
}