#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <cstdint>


struct Particle {
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Time lifetime;
    sf::Time initialLifetime;
};


class ParticleSystem : public sf::Drawable , public sf::Transformable {
public:
    ParticleSystem(std::size_t count);
    void emit(sf::Vector2f position);
    void update(sf::Time elapsed);
private:

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void resetParticle(std::size_t index, sf::Vector2f position);

    std::vector<Particle> particles;
    sf::VertexArray vertices;
    sf::Time maxLifetime;
};




