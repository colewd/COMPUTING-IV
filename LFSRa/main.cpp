#include <iostream>
#include "LFSR.hpp"

int main(int argc, char* argv[]) {

    std::string seed = "01010";

    std::cout << "Stepping 10 times for seed " << seed << std::endl;

    LFSR lfsr(seed, 2);

    for(unsigned int i=0; i<seed.size()-1; i++) {
        int bit = lfsr.step();
        std::cout << lfsr << " " << bit << std::endl;
    }

    std::cout << "\nGenerating 8 steps, 10 times for " << seed << std::endl;

    LFSR lfsr2(seed, 2);

    for (int i = 0; i < 10; i++) {
        int r = lfsr2.generate(5);
        std::cout << lfsr2 << " " <<  r << std::endl;
    }

    return 0;
}
