#include <iostream>

#include <SFML/Graphics.hpp>

#include "sierpinski.hpp"


using namespace sf;


int main(int argc, char* argv[]) {

  if(argv[1] == NULL || argv[2] == NULL) {

    std::cout << "Enter recursion depth as argument 1 and window height as argument 2." << std::endl;

    return -1;

  }


  int windowHeight = std::atoi(argv[2]);


  RenderWindow window(VideoMode(windowHeight, sqrt(3)*windowHeight/2),"Ps1 - Sierpinski's Triangle");

  Sierpinski triangle(std::atoi(argv[1]), windowHeight);


  while(window.isOpen()) {

    Event event;

    while(window.pollEvent(event)) {

      if(event.type == Event::Closed)

        window.close();

    }


    window.clear(Color::White);

    window.draw(triangle);

    window.display();

  }

  return 0;

}
