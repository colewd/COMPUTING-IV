#ifndef SIERPINSKI

#define SIERPINSKI


#include <SFML/Graphics.hpp>

#include <cmath>


class Sierpinski : public sf::Drawable {

private:

  sf::ConvexShape triangle;

  int _depth, _length;

public:

  Sierpinski(int depth, int length);

  Sierpinski(int depth, double x, double y, double length, sf::RenderTarget& target);

  void filledTriangle(double x, double y, double length, sf::RenderTarget& target);

  // Inherited from Drawable.

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
