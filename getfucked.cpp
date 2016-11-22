#include "getfucked.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>

// Slurp files contents into a string
std::string slurp(std::ifstream& in) {
    std::stringstream sstr;
    sstr << in.rdbuf();
    return sstr.str();
}

void bracketOpen() {
    return;
}

void bracketClosed() {
    return;
}

void interpret(std::string& instructions) {
    int head{0};
    std::array<char, TAPE_SIZE> tape{};

    for (auto instr = instructions.cbegin(); instr != instructions.cend(); ++instr) {
        //std::cout << *instr << std::endl;
        switch (*instr) {
            case '>' : 
                ++head; 
                break;
            case '<' :
                --head; 
                break;
            case '+' : 
                ++tape[head]; 
                break;
            case '-' : 
                --tape[head];
                break;
            case '.' : 
                std::cout << tape[head];
                break;
            case ',' : 
                std::cin >> tape[head];
                break;
            case '[' :
                bracketOpen();
                break;
            case ']' :
                bracketClosed();
                break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage ./getfucked <brainfuckfile>" << std::endl;
        return EXIT_FAILURE;
    }

    // Slurp source code into a string
    std::string instr{};
    std::ifstream source(argv[1]);
    if (source.is_open()) { instr = slurp(source); }

    interpret(instr);
}
