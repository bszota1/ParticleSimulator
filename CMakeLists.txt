cmake_minimum_required(VERSION 3.20)
project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(ParticleSimulator src/main.cpp
        include/particle.h
        src/particle.cpp)

target_link_libraries(ParticleSimulator PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

