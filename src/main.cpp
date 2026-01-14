#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <ctime>
#include <cstdlib>
#include "../include/particle.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Particle Simulator");
    window.setFramerateLimit(144);

    ParticleSystem particles(15000);
    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    particles.emit(mousePos);
                }
            }
        }

        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        window.clear(sf::Color(10, 10, 15));
        window.draw(particles);
        window.display();
    }

    return 0;
}