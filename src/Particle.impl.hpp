template <typename T>
Particle<T>::Particle() {
    position = Vector(std::vector<float>{0.0, 0.0});
    velocity = Vector(std::vector<float>{0.0, 0.0});
    acceleration = Vector(std::vector<float>{0.0, 0.0});
    mass = 1.0;
    force = Vector(std::vector<float>{0.0, 0.0});
}

template <typename T>
Particle<T>::Particle(T mass) {
    position = Vector(std::vector<float>{0.0, 0.0});
    velocity = Vector(std::vector<float>{0.0, 0.0});
    acceleration = Vector(std::vector<float>{0.0, 0.0});
    this->mass = mass;
    force = Vector(std::vector<float>{0.0, 0.0});
}

template <typename T>
Particle<T>::Particle(Vector<T> position) 
    : position(position) {
    velocity = Vector(position*0);
    acceleration = Vector(position*0);
    force = Vector(position*0);
    mass = 1.0;
}

template <typename T>
Particle<T>::Particle(Vector<T> position, T mass)
    : position(position), mass(mass) {
    velocity = Vector<T>(position*0);
    acceleration = Vector<T>(position*0);
    force = Vector<T>(position*0);
}

template <typename T>
Particle<T>::Particle(Vector<T> position,
     Vector<T> velocity, Vector<T> acceleration, T mass)
    : position(position), velocity(velocity), 
    acceleration(acceleration), mass(mass) {
        force = Vector<T>(position*0);
    }

template <typename T>
Vector<T> Particle<T>::getPosition() {
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
void Particle<T>::setPosition(Vector<T> position) {
    this->position = position;
}

template <typename T>
void Particle<T>::setVelocity(Vector<T> velocity) {
    this->velocity = velocity;
}

template <typename T>
void Particle<T>::setAcceleration(Vector<T> acceleration) {
    this->acceleration = acceleration;
}

template <typename T>
void Particle<T>::setMass(T mass) {
    this->mass = mass;
}

template <typename T>
void Particle<T>::resetForce() {
    this->force *= 0;
}

template <typename T>
void Particle<T>::addForce(Vector<T> additionalForce) {
    this->force += additionalForce;
}

template <typename T>
void Particle<T>::update(double dt) {
    acceleration = force/mass;
    position += velocity*dt + 0.5*acceleration*dt*dt;
    velocity += acceleration*dt;
}