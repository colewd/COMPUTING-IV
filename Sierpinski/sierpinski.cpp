#include "sierpinski.hpp"


using namespace sf;


Sierpinski::Sierpinski(int depth, int length) {

  _depth = depth;

  _length = length;

  triangle = ConvexShape(3);

  triangle.setFillColor(Color::Red);

  triangle.setPoint(0,Vector2f(0,sqrt(3)*length/2));

  triangle.setPoint(1,Vector2f(length,sqrt(3)*length/2));

  triangle.setPoint(2,Vector2f(length/2,0));

}


// Recursively call constructor three times to generate the next order Sierpinski

// triangles above, left and right of current triangle.

Sierpinski::Sierpinski(int depth, double x, double y, double length, RenderTarget& target) {

  if(depth==0) { return; }

  filledTriangle(x, y, length, target);

  Sierpinski(depth-1, x, y-(sqrt(3)*length/2), length/2, target); // Above triangle

  Sierpinski(depth-1, x-length/2, y, length/2, target); // Left triangle

  Sierpinski(depth-1, x + length/2, y, length/2, target); // Right triangle

}


// Given the bottom vertex point (x,y), draw equilateral triangle.

void Sierpinski::filledTriangle(double x, double y, double length, RenderTarget& target) {

  triangle = ConvexShape(3);

  triangle.setFillColor(Color::Black);

  triangle.setPoint(0,Vector2f(x, y));

  triangle.setPoint(1,Vector2f(x+length/2, y-(sqrt(3)*length/2)));

  triangle.setPoint(2,Vector2f(x-length/2, y-(sqrt(3)*length/2)));

  target.draw(triangle);

}


// Implementing the Drawable class.

// When drawing the base triangle, start creating the smaller

// colored triangles recursively.

void Sierpinski::draw(RenderTarget& target, RenderStates states) const {

  target.draw(triangle);

  Sierpinski(_depth, _length/2, sqrt(3)*_length/2, _length/2, target);

}
