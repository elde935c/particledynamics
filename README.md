# Particle Dynamics

This project simulates the dynamics of particles using basic physics principles. It includes a `Particle` class that represents a particle with position, velocity, acceleration, and mass. The project also includes unit tests to verify the functionality of the `Particle` class.

## Features

- Define particles with position, velocity, acceleration, and mass.
- Update particle states over time using the `update` method.
- Set and get particle properties.
- Unit tests using Google Test framework.

## Requirements

- CMake 3.10 or higher
- GCC or MinGW (for Windows)
- Google Test

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/particledynamics.git
    cd particledynamics
    ```

2. Create a build directory and navigate to it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    cmake --build .
    ```

