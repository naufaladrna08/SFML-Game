#include "Player.h"

Player::Player() {

}

Player::~Player() {
  
}

void Player::init(std::string textureName, sf::Vector2f position) {
  m_Position = position;

  /* Load texture */
  m_Texture.loadFromFile(textureName.c_str());

  /* Create a Sprite */
  m_Sprite.setTexture(m_Texture);
  m_Sprite.setPosition(m_Position);
  m_Sprite.setOrigin(m_Texture.getSize().x / 2, m_Texture.getSize().y / 2);
}

void Player::update() { 
  m_Sprite.setPosition(x, y);
}

sf::Sprite Player::getSprite() {
  return m_Sprite;
}