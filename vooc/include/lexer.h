#include <string>
#include <vector>
#include "tokens.h"

// [Lexer] Mod

#pragma once
#ifndef LEXER_H
#define LEXER_H

class Lexer {
    public:
        int column; // Current column
        int row;    // Current row

        std::vector<Token> tokenize(std::string content);

    private:
        void process();
        void advance();

        Token numeric_lex();
        Token alnum_lex();
        Token symbol_lex();
        Token string_lex();
        Token char_lex();
        Token backstring_lex();

        std::string content;        // Entire source
        int position;               // Current position
        char c_char;                // Current character
        std::vector<Token> tokens;  // All the tokens
};

#endif