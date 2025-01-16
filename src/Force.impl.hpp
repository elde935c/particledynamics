template <typename T>
void Force<T>::gravity(Particle<T> &p0, Particle<T> &p1) {
    Vector<T> r = p1.getPosition() - p0.getPosition();
    double r2 = dot(r, r);
    double G = 6.67430e-11;
    double F = G * p0.getMass() * p1.getMass() / r2;
    Vector<T> F0 = F * r / r2;
    Vector<T> F1 = -F0;
    p0.addForce(F0);
    p1.addForce(F1);
}