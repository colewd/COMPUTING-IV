#include <iostream>
#include <SFML/System.hpp>
#include "EditDistance.hpp"

int main(int argc, char* argv[]) {
  sf::Clock clock;
  sf::Time t;
  std::string a, b;

  getline(std::cin, a);
  getline(std::cin, b);

  if(a.empty() || b.empty()) {
    std::cout << "Enter two DNA sequences." << std::endl;
    return -1;
  }

  EditDistance editDistance(a, b);

  std::cout << "Edit distance = " << editDistance.optDistance() << std::endl;
  std::cout << editDistance.alignment() << std::endl;

  t = clock.getElapsedTime();
  std::cout << "Execution time is " << t.asSeconds() << " seconds\n";

  return 0;
}
