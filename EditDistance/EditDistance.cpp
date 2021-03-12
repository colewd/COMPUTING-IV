#include "EditDistance.hpp"

EditDistance::EditDistance(std::string one, std::string two) {
  this->n_string = one;
  this->m_string = two;
  this->n = n_string.size();
  this->m = m_string.size();

  opt = new int*[n+1];
  for (unsigned int i = 0; i <= n; i++) {
    opt[i] = new int[m + 1];
  }

  // Fill inner matrix with 0's
  for (unsigned int i = 0; i < m; i++) {
    for (unsigned int j = 0; j < n; j++) {
      opt[i][j] = 0;
    }
  }
  // Fill in corners of matrix
  for (unsigned int i = 0; i <= m; i++) {
    opt[n][i] = ((m-i)*2);
  }
  for (unsigned int j = 0; j <= n; j++) {
    opt[j][m] = ((n-j)*2);
  }
}

EditDistance::~EditDistance() {
  delete [] opt;
}

int EditDistance::penalty(char a, char b) {
  if (a == b) {
    return 0;
  }
  return 1;
}

int EditDistance::min(int a, int b, int c) {
  if (a <= b && a <= c) {
    return a;
  }
  if (b <= a && b <= c) {
    return b;
  }
  if(c <= a && c <= b) {
    return c;
  }
  return -1;
}

int EditDistance::optDistance() {
  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--) {
      int opt1 = opt[(i + 1)][(j + 1)] + penalty(n_string[i], m_string[j]);
      int opt2 = opt[(i + 1)][j] + 2;
      int opt3 = opt[i][(j+1)] + 2;
      opt[i][j] = min(opt1, opt2, opt3);
    }
  }
  return opt[0][0];
}

std::string EditDistance::alignment() {
  std::ostringstream alignment;
  unsigned int i = 0, j = 0, opt1, opt2, opt3;

  while (i < n || j < m) {


    // Ensure the strings have an i'th or j'th character.
    if(i < n_string.size() && j < m_string.size()) {
      opt1 = opt[(i+1)][(j+1)] + penalty(n_string[i], m_string[j]);
    } else {
      opt1 = -1;
    }
    if(i < n_string.size() && j <= m_string.size()) {
      opt2 = opt[(i + 1)][j] + 2;
    } else {
      opt2 = -1;
    }
    if(i <= n_string.size() && j < m_string.size()) {
      opt3 = opt[i][(j+1)] + 2;
    } else {
      opt3 = -1;
    }

    // Depending on the path to take, print the values to the stringstream.
    if (opt[i][j] == (int)opt2) {
      alignment << n_string[i] << " - 2";
      i++;
    }
    else if (opt[i][j] == (int)opt3) {
      alignment << "- " << m_string[j] << " 2";
      j++;
    }
    else if(opt[i][j] == (int)opt1){
      alignment << n_string[i] << " " << m_string[j] << " "
                << penalty(n_string[i], m_string[j]);
      i++;
      j++;
    }
    alignment << '\n';
  }

  return alignment.str();
}
