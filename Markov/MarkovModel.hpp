#ifndef MARKOV_MODEL_H
#define MARKOV_MODEL_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <cstdlib>

class MarkovModel {
 private:
  std::map <std::string, int> _kgrams;
  std::string _alphabet, _text;
  unsigned int _order;

 public:
  // Create a Markov model of order k from given text.
  // Assume that text has length of atleast k.
  MarkovModel(std::string text, int k);
  ~MarkovModel();
  // Order k of Markov model.
  inline int order() { return _order; }
  // Number of occurences of kgram in text.
  // Throws exception if kgram is not of length k.
  int freq(std::string kgram);
  // Number of times that character c follows kgram.
  // If order == 0, return number of times c appears.
  // Throws exception if kgram is not of length k.
  int freq(std::string kgram, char c) const;
  // Returns a random character following given kgram.
  // Throws exception if kgram is not of length k.
  // Throws exception if there's no such kgram.
  char randk(std::string kgram);
  // Generate a string of length t characters by simulating a trajectory
  // through the corresponding Markov chain. The first k characters of the
  // newly generated string should be the argument kgram.
  // Assume that t is atleast the length of k.
  // Throws exception if kgram is not of length k.
  std::string gen(std::string kgram, int t);
  friend std::ostream& operator<<(std::ostream& os, const MarkovModel& m);
};

#endif
