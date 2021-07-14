#include "Enemy.h"

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::init(std::string textureName, sf::Vector2f position, float speed) {
  m_Speed = speed;
  
  /* Load texture */
  m_Texture.loadFromFile(textureName.c_str());
  
  /* Create Sprite */
  m_Sprite.setTexture(m_Texture);
  m_Sprite.setPosition(position);
  m_Sprite.setOrigin(m_Texture.getSize().x / 2, m_Texture.getSize().y / 2);
}

void Enemy::update(float dt) {
  m_Sprite.move(m_Speed * dt, 0);
}

sf::Sprite Enemy::getSprite() {
  return m_Sprite;
}