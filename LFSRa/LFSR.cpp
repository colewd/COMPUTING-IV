#include "LFSR.hpp"

// constructor to create LFSR with the given initial seed and tap
LFSR::LFSR(std::string seed, int tap) {
    _seed = seed;
    _tap = tap;
    _length = (int)_seed.size()-1;
}

// simulate one step and return the new bit as 0 or 1
int LFSR::step() {
    char first_bit, last_bit = _seed.at(0);
    char tap_bit = _seed.at(_length-_tap);
    
    std::string seed = _seed;
    
    for(int i = _length; i >= 1; i--) {
        _seed.at(i-1) = seed.at(i); // Move each bit to the left
    }
    (last_bit xor tap_bit) ? first_bit = '1' : first_bit = '0';
    _seed.at(_length) = first_bit;
    
    return (last_bit xor tap_bit);
}

// simulate k steps and return k-bit integer
int LFSR::generate(int k) {
    int res = 0;
    for(int i = 0; i < k; i++) {
        res = 2*res + step();
    }
    return res;
}
