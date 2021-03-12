
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

int main (){
 sf::RenderWindow window(sf::VideoMode(800,600), "SFML works!");
 window.setFramerateLimit(10);
 // sf::CircleShape shape(100.f);
 // shape.setFillColor(sf::Color::Green);

 sf::Texture texture;
 if(!texture.loadFromFile("sprite.png"))
 {
 return EXIT_FAILURE;
 }

 sf::Sprite sprite(texture);
 sprite.setTexture(texture);
 sprite.setPosition(0,0);
 //sprite.setRotation(90);

 while(window.isOpen())
 {
 sf::Event event;
 while(window.pollEvent(event))
 {
 if(event.type==sf::Event::Closed)
 window.close();
 }
 window.clear();
 // window.draw(shape);
 window.draw(sprite);
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
 {
   //sprite.rotate(15);
 sprite.move(0,-10);
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
 {
   //sprite.rotate(15);
 sprite.move(0,10);
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
 {
   //sprite.rotate(15);
 sprite.move(-10,0);
 }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
 {
   //sprite.rotate(15);
 sprite.move(10,0);
 }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
 {
 sprite.rotate(45);
 }
 window.display();
 }
 return 0;
 }
