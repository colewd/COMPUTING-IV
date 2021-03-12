#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE LFSR
#include <boost/test/unit_test.hpp>

// TEST: default seed, 5 bits
BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
    
    std::cout << "Test case: Five Bits Tap At Two" << std::endl;
    
    LFSR l("00111", 2);
    
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    
    LFSR l2("00111", 2);
    
    BOOST_REQUIRE(l2.generate(8) == 198);
}

// TEST: the shortest seed, 2 bits.
BOOST_AUTO_TEST_CASE(twoBitsTapAtOne) {
    
    std::cout << "Test case: Two Bits Tap At Zero" << std::endl;
    
    LFSR l("01", 0); // 11 10 01
    
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    
    LFSR l2("01", 0);
    
    BOOST_REQUIRE(l2.generate(3) == 5);
}

// TEST: the longest seed, 32 bits.
BOOST_AUTO_TEST_CASE(thirtyTwoBitsTapAtFifteen) {
    
    std::cout << "Test case: Thirty-Two Bits Tap At Fifteen" << std::endl;
    
    LFSR l("01101110101011010010011101100110", 8);
    
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    
    LFSR l2("01101110101011010010011101100110", 8);
    
    BOOST_REQUIRE(l2.generate(5) == 27);
}
