#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "MarkovModel.hpp"

MarkovModel::MarkovModel(std::string text, int k) {
  for (unsigned int i = 0; i < text.size(); ++i) {
    if (i < text.size() - (k-1)) {
      _kgrams[text.substr(i, k)] += 1;
    } else {
     _kgrams[text.substr(i) + text.substr(0, k-(text.size()-i))] += 1;
    }
  }

  _order = k;
  _text = text;

  // Build alphabet.
  for (unsigned int i = 0; i < text.size(); i++) {
    if (_alphabet.find(text[i]) == std::string::npos) {
      _alphabet += text[i];
    }
  }
}

MarkovModel::~MarkovModel() {
}

int MarkovModel::freq(std::string kgram) {
  if (kgram.size() != _order) {
    throw std::runtime_error("Kgram is not of length k.");
  }
  if (_order == 0) {
    return _text.length();
  }
  if (_kgrams.count(kgram) != 0) {
    return _kgrams[kgram];
  } else {
    return 0;
  }
}

int MarkovModel::freq(std::string kgram, char c) const {
  if (kgram.size() != _order) {
    throw std::runtime_error("Kgram is not of length k.");
  }

  if (_order == 0) {
    return std::count(_text.begin(), _text.end(), c);;
  }

  if (_kgrams.count(kgram) != 0) {
    std::size_t kgramFound = _text.find(kgram, 0);
    unsigned int charFound = 0, size = _text.size();
    while (kgramFound != std::string::npos) {
      if (_text[kgramFound + _order] == c) {
        charFound++;
      }
      kgramFound = _text.find(kgram, kgramFound + 1);
    }

    // Find any occurences of kgram from having a circular string.
    for (int i = _order; i > 0; i--) {
      std::string one = _text.substr(size - i);
      std::string two = _text.substr(0, _order - i);
      std::string wrappedGram = one + two;
      if (wrappedGram == kgram) {
        if (_text[_order - i] == c) {
          charFound++;
        }
      }
    }

    return charFound;

  } else {
    return 0;
  }
}

char MarkovModel::randk(std::string kgram) {
  if (kgram.size() < _order) {
    throw std::runtime_error("Kgram is not of length k.");
  }

  if (_kgrams.count(kgram) == 0) {
    throw std::runtime_error("There is no such kgram.");
  }

  std::vector<char> probVector;

  // prob = probability of each char appearing after kgram.
  // Insert char into vector prob amount of times.
  for (unsigned int i = 0; i <  _alphabet.size(); i++) {
    int prob = freq(kgram, _alphabet[i]);
    probVector.insert(probVector.end(), prob, _alphabet[i]);
  }

  // Choose random char in vector of possibilities.
  // Char with most occurences has better chance of being chosen.
  unsigned int seed = time(NULL);
  unsigned int* p_seed = &seed;
  size_t random = rand_r(p_seed) % probVector.size();

  return probVector[random];
}

std::string MarkovModel::gen(std::string kgram, int t) {
  if (kgram.size() != _order) {
    throw std::runtime_error("Kgram is not of length k.");
  }

  std::string result;
  result += kgram;

  for (int i = kgram.size(); i < t; i++) {
    result += randk(result.substr(result.size()-kgram.size()));
  }

  return result;
}

std::ostream& operator<<(std::ostream& os, const MarkovModel& m) {
  os << "TEXT: " << m._text << std::endl;
  os << "ALPHABET: " << m._alphabet << std::endl;
  os << "ORDER: " << m._order << "\n\nKGRAMS\n";
  std::map<std::string, int>::const_iterator it;
  for (it = m._kgrams.begin(); it != m._kgrams.end(); it++) {
    os << it->first << " " << it->second << std::endl;
  }
  for (it = m._kgrams.begin(); it != m._kgrams.end(); it++) {
    for (unsigned int i = 0; i <  m._alphabet.size(); i++) {
      int prob = m.freq(it->first, m._alphabet[i]);
      os << it->first << " next char: " <<  m._alphabet[i] << " - " << prob
          << "/" << it->second << "\n";
    }
  }
  return os;
}
