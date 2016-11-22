#include "getfucked.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Slurp files contents into a string
std::string slurp(std::ifstream& in) {
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage ./getfucked <brainfuckfile>" << std::endl;
        return EXIT_FAILURE;
    }

    // Slurp source code into a string
    std::string instructions{};
    std::ifstream source(argv[1]);
    if (source.is_open()) { instructions = slurp(source); }
}
