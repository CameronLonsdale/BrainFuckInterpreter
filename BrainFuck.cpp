/*
 * BrainFuck.cpp
 * --------------------
 * By Cameron Lonsdale
 */

#include "BrainFuck.h"
#include <iostream>
#include <array>

// If the value at head is 0, jump to the matching ] character
// else, return current prog
//
const char* bracketOpen(const char& value, const char *prog) {
    int matches = 1;
    if (value == 0) {
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

// If the value at head is not 0, jump to previous matching [ character
// else, return current prog
//
const char *bracketClosed(const char& value, const char *prog) {
    if (value != 0) {
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

// Sequentially evaluate brainfuck commands
//
void BrainFuck::interpret(const char *prog) {
    std::array<char, BrainFuck::TAPE_SIZE> tape{};
    char *head = tape.data();

    while (*prog) {
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
                prog = bracketOpen(*head, prog);
                break;
            case ']':
                prog = bracketClosed(*head, prog);
                break;
        }
        ++prog;
    }
}
