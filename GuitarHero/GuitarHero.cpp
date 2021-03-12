#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 440.0
#define SPS 44100

std::vector<sf::Int16> makeSamplesFromString(GuitarString& gs) {
  std::vector<sf::Int16> samples;
  gs.pluck();
  int duration = 8;  // seconds
  for (int i= 0; i < SPS * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }
  return samples;
}

int main() {
  sf::Texture texture;
  texture.loadFromFile("piano.png");
  sf::Sprite sprite;
  sprite.setTexture(texture);
  int x = sprite.getLocalBounds().width;
  int y = sprite.getLocalBounds().height;

  sf::RenderWindow window(sf::VideoMode(x, y), "GuitarHero");
  window.setKeyRepeatEnabled(false);

  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  std::vector<sf::Int16> stringSample;
  std::vector<std::vector<sf::Int16> > samples(keyboard.size());
  std::vector<sf::SoundBuffer> buffers(keyboard.size());
  std::vector<sf::Sound> sounds(keyboard.size());
  double frequency;

  for (int i = 0; i < keyboard.size(); i++) {
    frequency = CONCERT_A * pow(2, (i-24)/12.0);
    GuitarString gs = GuitarString(frequency);
    stringSample = makeSamplesFromString(gs);
    samples[i] = stringSample;
    if (!buffers[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, SPS))
      throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
    sounds[i].setBuffer(buffers[i]);
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::TextEntered) {
        sounds[keyboard.find(static_cast<char>(event.text.unicode))].play();
      }
    }
      window.clear();
      window.draw(sprite);
      window.display();
  }
  return 0;
}
