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

const char* bracketOpen(char *head, const char *prog) {
    int matches = 1;
    if (*head == 0) {
        while (matches != 0) {
            ++prog;
            if (*prog == '[') {
                ++matches;
            } else if (*prog == ']') {
                --matches;
            }
        }
    }
    return prog;
}

const char *bracketClosed(char *head, const char *prog) {
    if (*head != 0) {
        int matches = 1;
        while (matches != 0) {
            --prog;
            if (*prog == '[') {
                --matches;
            } else if (*prog == ']') {
                ++matches;
            }
        }
    }
    return prog;
}

void interpret(std::string& instructions) {
    std::array<char, TAPE_SIZE> tape{};
    char *head = tape.data();
    const char *prog = instructions.c_str();

    while (*prog) {
        //std::cout << *prog << std::endl;
        switch (*prog) {
            case '>':
                ++head; 
                break;
            case '<':
                --head; 
                break;
            case '+': 
                ++(*head); 
                break;
            case '-': 
                --(*head);
                break;
            case '.': 
                std::cout << *head;
                break;
            case ',': 
                std::cin >> *head;
                break;
            case '[':
                prog = bracketOpen(head, prog);
                break;
            case ']' :
                prog = bracketClosed(head, prog);
                break;
        }
        ++prog;
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
