#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>
#include <iostream>
#include <deque>
#include <stdexcept>

class RingBuffer {
 private:
  std::deque<int16_t> buffer;
  int capacity;
 public:
  // create an empty ring buffer, with given max capacity
  explicit RingBuffer(int capacity);
  // return number of items currently in the buffer
  int size();
  // is the buffer empty (size equals zero)?
  bool isEmpty();
  // is the buffer full  (size equals capacity)?
  bool isFull();
  // add item x to the end
  void enqueue(int16_t x);
  // delete and return item from the front
  double dequeue();
  // return (but do not delete) item from the front
  double peek();
};

#endif
