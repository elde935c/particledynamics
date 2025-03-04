template <typename T>
Particle<T>::Particle() {
    position = Vector(std::vector<float>{0.0, 0.0});
    velocity = Vector(std::vector<float>{0.0, 0.0});
    acceleration = Vector(std::vector<float>{0.0, 0.0});
    mass = 1.0;
    force = Vector(std::vector<float>{0.0, 0.0});
}

template <typename T>
Particle<T>::Particle(const Particle<T> &p) {
    this->position = p.position;
    this->velocity = p.velocity;
    this->acceleration = p.acceleration;
    this->mass = p.mass;
    this->force = p.force;
}

template <typename T>
Particle<T>::Particle(const T mass) {
    position = Vector(std::vector<float>{0.0, 0.0});
    velocity = Vector(std::vector<float>{0.0, 0.0});
    acceleration = Vector(std::vector<float>{0.0, 0.0});
    this->mass = mass;
    force = Vector(std::vector<float>{0.0, 0.0});
}

template <typename T>
Particle<T>::Particle(const Vector<T> & position) 
    : position(position) {
    velocity = Vector(position*0);
    acceleration = Vector(position*0);
    force = Vector(position*0);
    mass = 1.0;
}

template <typename T>
Particle<T>::Particle(const Vector<T> & position, const T mass)
    : position(position), mass(mass) {
    velocity = Vector<T>(position*0);
    acceleration = Vector<T>(position*0);
    force = Vector<T>(position*0);
}

template <typename T>
Particle<T>::Particle(const Vector<T> & position,
     const Vector<T> & velocity, const Vector<T> & acceleration, const T mass)
    : position(position), velocity(velocity), 
    acceleration(acceleration), mass(mass) {
        force = Vector<T>(position*0);
    }

template <typename T>
Vector<T> Particle<T>::getPosition(){
    return position;
}

template <typename T>
Vector<T> Particle<T>::getVelocity() {
    return velocity;
}

template <typename T>
Vector<T> Particle<T>::getAcceleration() {
    return acceleration;
}

template <typename T>
Vector<T> Particle<T>::getForce() {
    return force;
}

template <typename T>
T Particle<T>::getMass() {
    return mass;
}

template <typename T>
void Particle<T>::resetForce() {
    this->force *= 0;
}

template <typename T>
void Particle<T>::addForce(const Vector<T> &additionalForce) {
    this->force += additionalForce;
}

template <typename T>
void Particle<T>::update(const T dt) {
    acceleration = force/mass;
    position += velocity*dt + 0.5*acceleration*dt*dt;
    velocity += acceleration*dt;
}