#include <iostream>
#include <string>
#include <cstdlib>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
  std::string input = "", line, kgram;
  unsigned int k = std::atoi(argv[1]);
  unsigned int t = std::atoi(argv[2]);

  while (getline(std::cin, line)) {
    input += line;
  }

  MarkovModel markov(input, k);
  kgram = input.substr(0, k);

  std::cout << markov << std::endl;
  std::cout << "\nGenerated Text: " << markov.gen(kgram, t) << "\n";

  return 0;
}
