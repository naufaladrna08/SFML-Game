#include <iostream>
#include <SFML/Graphics.hpp>

sf::Vector2f viewSize(800, 600);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "SFML");

sf::Shader shader;

sf::RectangleShape rect(sf::Vector2f(600, 400));
sf::Clock clck;

enum MOVEMENTS {
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NONE
};

/* Player */
sf::Texture text_player;
sf::Sprite spr_player;
int px = 800 / 2, py = 600 / 2;
float x, y, rot;
void movePlayer(int mvmt) {
  int speed = 2;

  if (mvmt == LEFT) {
    x = -speed;
  }
  if (mvmt == RIGHT) {
    x = speed;
    rot = 45;
    spr_player.rotate(45);
  }
  if (mvmt == UP) {
    y = -speed;
  }
  if (mvmt == DOWN) {
    y = speed;
  }
  if (mvmt == NONE) {
    x = 0;
    y = 0;
  }
}

void init() {
  window.setFramerateLimit(60);
  text_player.loadFromFile("assets/Player.png");

  spr_player.setTexture(text_player);
  spr_player.setPosition(px, py);
  spr_player.setOrigin(text_player.getSize().x / 2, text_player.getSize().y / 2);

  rect.setPosition(800 / 2, 600 / 2);
  rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
  
  shader.loadFromFile("basicShader.frag", sf::Shader::Fragment);
}

void draw() {
  window.clear(sf::Color(120, 120, 255, 255));

  window.draw(rect, &shader);
  window.draw(spr_player);
  window.display();
}

void update() {
  spr_player.move(x, y);

  sf::Time dt = clck.getElapsedTime();
  shader.setUniform("u_time", dt.asSeconds());
  shader.setUniform("u_resolution", sf::Glsl::Vec2(600, 400));
}

void input(sf::Event e) {
  while (window.pollEvent(e)) {
    if (e.key.code == sf::Keyboard::Escape) {
      window.close();
    }

    if (e.type == sf::Event::Closed) {
      window.close();
    }

    if (e.key.code == sf::Keyboard::Up) {
      movePlayer(UP);
    }
    if (e.key.code == sf::Keyboard::Down) {
      movePlayer(DOWN);
    }
    if (e.key.code == sf::Keyboard::Left) {
      movePlayer(LEFT);
    }
    if (e.key.code == sf::Keyboard::Right) {
      movePlayer(RIGHT);
    }

    if (e.type == sf::Event::KeyReleased) {
      movePlayer(NONE);
    }
    
  }
}

int main(int argc, char* argv[]) {
  init();
  sf::Event e;

  while (window.isOpen()) {
    update();
    input(e);
    
    draw();
  }

  return 0;
}