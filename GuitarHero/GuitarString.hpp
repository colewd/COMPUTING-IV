#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include <math.h>
#include <SFML/Audio/SoundBuffer.hpp>
#include <cstdlib>
#include "RingBuffer.hpp"

class GuitarString {
 private:
  RingBuffer* buffer;
  int bufferCapacity, ticCount;
 public:
  // create a guitar string of the given frequency, using a sampling rate of
  // 44,100
  explicit GuitarString(double frequency);
  // create a guitar string whose size and initial values are given by the array
  GuitarString(double init[], int capacity);
  // destructor
  ~GuitarString();
  // pluck the guitar string by replacing the buffer with white noise
  void pluck();
  // advance the simulation one time step
  void tic();
  // return the current sample
  double sample();
  // return number of times tic was called so far
  int time();
};

#endif
