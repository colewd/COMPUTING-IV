/*
  Credits: Prof Fred Martin
  test file for GuitarString class

  compile with
  g++ -c GStest.cpp -lboost_unit_test_framework
  g++ GStest.o GuitarString.o RingBuffer.o -o GStest -lboost_unit_test_framework
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <vector>
#include <exception>
#include <stdexcept>

#include "GuitarString.hpp"

BOOST_AUTO_TEST_CASE(GS) {
  double init[] = {0,2000,4000,-10000};
  BOOST_REQUIRE_NO_THROW(GuitarString gs(init, sizeof(init)/sizeof(*init)));
  GuitarString gs(init, sizeof(init)/sizeof(*init));

  // GS is 0 2000 4000 -10000
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 0);

  gs.tic();
  // it's now 2000 4000 -10000 996  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 2000);

  gs.tic();
  // it's now 4000 -10000 996 2988
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 4000);

  gs.tic();
  // it's now -10000 996 2988 -2988
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == -10000);

  gs.tic();
  // it's now 996 2988 -2988 -4483
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 996);

  gs.tic();
  // it's now 2988 -2988 -4483 1984
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 2988);

  gs.tic();
  // it's now -2988 -4483 1984 0
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == -2988);

  // a few more times
  gs.tic();
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == -4483);
  gs.tic();
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 1984);
  gs.tic();
  std::cout << "Sample is: " << gs.sample() << "\n";
  BOOST_REQUIRE(gs.sample() == 0);
}
