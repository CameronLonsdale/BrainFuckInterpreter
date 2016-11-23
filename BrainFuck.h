/*
 * BrainFuck.h
 * --------------------
 * By Cameron Lonsdale
 */

#ifndef BRAINFUCK_H
#define BRAINFUCK_H

namespace BrainFuck {
    static const int TAPE_SIZE = 30000;
    void interpret(const char *prog);
}

#endif /* BRAINFUCK_H */
