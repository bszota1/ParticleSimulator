#include "../include/particle.h"
#include <cmath>
#include <cstdlib>
#include <cstdint>

ParticleSystem::ParticleSystem(std::size_t count)
    : particles(count)
    , vertices(sf::PrimitiveType::Points, count)
{}

void ParticleSystem::emit(sf::Vector2f position) {
    for (std::size_t i = 0; i < particles.size(); ++i) {
        resetParticle(i, position);
    }
}

void ParticleSystem::update(sf::Time elapsed) {
    const float gravity = 0.5f;
    const float drag = 0.99f;

    for (std::size_t i = 0; i < particles.size(); ++i) {
        Particle& p = particles[i];
        p.lifetime -= elapsed;

        if (p.lifetime <= sf::Time::Zero) {
            vertices[i].color.a = 0;
            continue;
        }

        p.velocity.y += gravity * elapsed.asSeconds();
        p.velocity *= std::pow(drag, elapsed.asSeconds() * 60.0f);
        p.position += p.velocity * elapsed.asSeconds();

        vertices[i].position = p.position;

        float initialSec = p.initialLifetime.asSeconds();
        float ratio = (initialSec > 0) ? p.lifetime.asSeconds() / initialSec : 0;

        vertices[i].color.r = 255;
        vertices[i].color.g = static_cast<std::uint8_t>(255 * ratio);
        vertices[i].color.b = 0;
        vertices[i].color.a = static_cast<std::uint8_t>(ratio * 255);
    }
}

void ParticleSystem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.blendMode = sf::BlendAdd;
    target.draw(vertices, states);
}

void ParticleSystem::resetParticle(std::size_t index, sf::Vector2f position) {
    Particle& p = particles[index];

    float angle = (std::rand() % 360) * 3.14159f / 180.f;
    float speed = (std::rand() % 300) + 15.f;

    p.position = position;
    p.velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    p.initialLifetime = sf::milliseconds((std::rand() % 1500) + 500);
    p.lifetime = p.initialLifetime;

    vertices[index].position = position;
    vertices[index].color = sf::Color::Yellow;
}