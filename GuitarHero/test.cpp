#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RB_Contructor) {
	// normal constructor
	BOOST_REQUIRE_NO_THROW(RingBuffer(100));

	// this should fail
	BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
	BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

// Tests:
// RingBuffer.enqueue();
// RingBuffer.dequeue();
BOOST_AUTO_TEST_CASE(RB_Enqueue_Dequeue) {
	RingBuffer rb(100);

	rb.enqueue(2);
	rb.enqueue(1);
	rb.enqueue(0);

	BOOST_REQUIRE(rb.dequeue() == 2);
	BOOST_REQUIRE(rb.dequeue() == 1);

	BOOST_REQUIRE_NO_THROW(rb.dequeue());
	BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}

// Tests:
// RingBuffer.isFull();
// RingBuffer.isEmpty();
// RingBuffer.size();
BOOST_AUTO_TEST_CASE(RB_isFull_isEmpty_Size) {
	RingBuffer rb(2);

	rb.enqueue(2);
	rb.enqueue(1);
  BOOST_REQUIRE(rb.isFull() == true);
  BOOST_REQUIRE(rb.isEmpty() == false);

  rb.dequeue();
  rb.dequeue();
  BOOST_REQUIRE(rb.isFull() == false);
  BOOST_REQUIRE(rb.isEmpty() == true);

  BOOST_REQUIRE(rb.size() == 0);
}
