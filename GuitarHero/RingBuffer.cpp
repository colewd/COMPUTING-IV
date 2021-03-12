#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("RB constructor: capacity must be > 0.");
  }
  this->capacity = capacity;
}

int RingBuffer::size() {
  return buffer.size();
}

bool RingBuffer::isEmpty() {
  return buffer.size() == 0;
}

bool RingBuffer::isFull() {
  return buffer.size() == capacity;
}

void RingBuffer::enqueue(int16_t x) {
  if (buffer.size() == capacity) {
    throw std::runtime_error("enqueue: can't enqueue to a full ring.");
  }
  buffer.push_back(x);
}

double RingBuffer::dequeue() {
  if (buffer.empty()) {
    throw std::runtime_error("dequeue: can't dequeue from an empty ring.");
  }
  int16_t front = buffer.front();
  buffer.pop_front();
  return front;
}

double RingBuffer::peek() {
  if (buffer.empty()) {
    throw std::runtime_error("peek: can't peek at an empty ring.");
  }
  return buffer.front();
}
