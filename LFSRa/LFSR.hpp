#ifndef LFSR_H
#define LFSR_H

#include <iostream>

class LFSR {
private:
    std::string _seed;
    unsigned int _tap, _length;
public:
    LFSR(std::string seed, int tap);
    int step();
    int generate(int k);
    friend std::ostream& operator<<(std::ostream& os, const LFSR& l) {
        os << l._seed;
        return os;
    }
};

#endif
