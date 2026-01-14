## Particle Simulator
A lightweight and high-performance 2D particle simulator written in C++ using the SFML 3 library. This project demonstrates efficient rendering techniques using vertex arrays and basic physics simulations like gravity and air resistance.

## Features
1. High Performance: Capable of updating and rendering 15,000 particles simultaneously by utilizing sf::PrimitiveType::Points.

1. Physics Engine: Implements a constant gravity force (0.5f) and a dynamic drag coefficient (0.99f) to simulate realistic motion.

1. Dynamic Visuals:

1. Color Morphing: Particles transition from yellow to red as they age.

1. Alpha Fading: Smooth transparency transition based on the particle's remaining lifetime.

1. Additive Blending: Uses sf::BlendAdd to create a glowing, "hot" effect where particles overlap.

## Requirements
To build and run this project, you will need:

1. A compiler supporting C++17 or higher.

1. SFML 3 (Graphics, Window, System, and Audio modules).

1. CMake version 3.20 or newer.

## Building the Project
1. Ensure SFML 3 is installed on your system.

1. Clone or download the source files.

1. Use the following commands in your terminal:

``` Bash
mkdir build
cd build
cmake ..
cmake --build .
```
[!NOTE] The CMakeLists.txt is currently configured for macOS using Homebrew (path: /opt/homebrew). If you are on Windows or Linux, you may need to adjust the CMAKE_PREFIX_PATH.

## How to Use
1. Left Mouse Button: Click anywhere in the window to emit a burst of particles from the cursor's position.

1. Window Management: The simulation runs in an 800x600 window at a 144 FPS limit.

## Project Structure
1. src/main.cpp: Entry point, window management, and the main simulation loop.

1. src/particle.cpp / include/particle.h: Core logic for the particle system, including physics updates and vertex manipulation.

1. CMakeLists.txt: Build configuration and dependency management