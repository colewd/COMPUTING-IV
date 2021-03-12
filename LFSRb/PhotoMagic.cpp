#include <iostream>

#include "SFML/Graphics.hpp"

#include "LFSR.hpp"


sf::Image transform(sf::Image& original, LFSR& lfsr);


int main(int argc, char* argv[]) {

  if(argc < 5) {

    std::cout << "Error: Not enough arguments." << std::endl;

    std::cout << "./PhotoMagic [input path] [output path] [seed] [tap]" << std::endl;

    return -1;

  }

  std::string inputPhoto = argv[1], outputPhoto = argv[2], seed = argv[3];

  int tap = std::atoi(argv[4]);

  LFSR lfsr(seed, tap);


  sf::Image image, newImage;

	if (!image.loadFromFile(inputPhoto))

		return -1;


  sf::Vector2u size = image.getSize();

  newImage =  transform(image,lfsr);


  sf::Texture texture, newTexture;

  texture.loadFromImage(image);

  newTexture.loadFromImage(newImage);


  sf::Sprite sprite, newSprite;

  sprite.setTexture(texture);

  newSprite.setTexture(newTexture);


  sf::RenderWindow sourceWindow(sf::VideoMode(size.x, size.y), "Source File");

  sourceWindow.setPosition(sf::Vector2i(0,0));


  sf::RenderWindow outputWindow(sf::VideoMode(size.x, size.y), "Output File");

  outputWindow.setPosition(sf::Vector2i(0+size.x,0));


  while (sourceWindow.isOpen() && outputWindow.isOpen())

	{

		sf::Event event;

		while (sourceWindow.pollEvent(event))

		{

			if (event.type == sf::Event::Closed)

				sourceWindow.close();

		}

    while (outputWindow.pollEvent(event))

    {

      if (event.type == sf::Event::Closed)

        outputWindow.close();

    }


		sourceWindow.clear(sf::Color::White);

		sourceWindow.draw(sprite);

		sourceWindow.display();


    outputWindow.clear(sf::Color::White);

    outputWindow.draw(newSprite);

    outputWindow.display();

	}

	if (!newImage.saveToFile(outputPhoto))

		return -1;


  return 0;

}


sf::Image transform(sf::Image& original, LFSR& lfsr) {

  sf::Image image = original;

  sf::Vector2u size = image.getSize();

  sf::Color p;

  for (unsigned int x = 0; x < size.x; x++) {

    for (unsigned int y = 0; y < size.y; y++) {

        p = image.getPixel(x, y);

        p.r = p.r xor lfsr.generate(8);

        p.g = p.g xor lfsr.generate(8);

        p.b = p.b xor lfsr.generate(8);

        image.setPixel(x, y, p);

    }

  }

  return image;

}
