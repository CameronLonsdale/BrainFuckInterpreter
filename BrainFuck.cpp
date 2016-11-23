/*
 * BrainFuck.cpp
 * --------------------
 * By Cameron Lonsdale
 */

#include "BrainFuck.h"
#include <iostream>
#include <array>

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
                prog = bracketOpen(head, prog);
                break;
            case ']' :
                prog = bracketClosed(head, prog);
                break;
        }
        ++prog;
    }
}
