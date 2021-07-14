#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#ifdef GAME_DEBUG
  #include <iostream>
#endif

class Player {
  public:
    Player();
    ~Player();

    void init(std::string textureName, sf::Vector2f position);
    void update();
    sf::Sprite getSprite();

    float mx, my;

  private:
    sf::Texture m_Texture;
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;

    float m_Velocity;
};

#endif