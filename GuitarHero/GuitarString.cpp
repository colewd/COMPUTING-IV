#include "GuitarString.hpp"

GuitarString::GuitarString(double frequency) {
  bufferCapacity = ceil(44100/frequency);
  buffer = new RingBuffer(bufferCapacity);
  for (int i = 0; i < bufferCapacity; i++) {
    buffer->enqueue(0);
  }
}

GuitarString::GuitarString(double init[], int capacity) {
  bufferCapacity = capacity;
  buffer = new RingBuffer(bufferCapacity);
  for (int i = 0; i < bufferCapacity; i++) {
    buffer->enqueue(init[i]);
  }
}

GuitarString::~GuitarString() {
  delete buffer;
  buffer = NULL;
}

void GuitarString::pluck() {
  if (!buffer->isEmpty()) {
    delete buffer;
    buffer = NULL;
    buffer = new RingBuffer(bufferCapacity);
  }
  unsigned int rand = 0xffff;
  for (int i = 0; i < bufferCapacity; i++) {
    buffer->enqueue((int16_t)(rand_r(&rand)));  // Velocity
  }
}

void GuitarString::tic() {
  double front = buffer->dequeue();
  double second = buffer->peek();
  buffer->enqueue(((front+second)/2) * 0.996);
  ticCount++;
}

double GuitarString::sample() {
  return buffer->peek();
}

int GuitarString::time() {
  return ticCount;
}
