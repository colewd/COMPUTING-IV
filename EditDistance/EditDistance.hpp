#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <iostream>
#include <sstream>
#include <string>

class EditDistance {
 private:
   std::string n_string, m_string;
   unsigned int n, m;
   int** opt;    // opt[i][j] = opt[i * b.length() + j];
 public:
   EditDistance(std::string a, std::string b);
   ~EditDistance();
   // Returns the penalty for aligning char a and b.
   static int penalty(char a, char b);
   // Returns the min of 3 integers.
   static int min(int a, int b, int c);
   // Populates the matrix with the two strings, returns the optimal distance.
   int optDistance();
   // Traces the matrix, returns a string to display the actual alignment.
   std::string alignment();
};

#endif
