#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <SFML/Graphics.hpp>

#ifdef GAME_DEBUG
  #include <iostream>
#endif

class Enemy {
  public:
    Enemy();
    ~Enemy();

    void init(std::string textureName, sf::Vector2f position, float speed);
    void update(float dt);
    sf::Sprite getSprite();

  private:
    sf::Texture m_Texture;
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;

    float m_Speed;
};

#endif