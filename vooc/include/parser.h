#include <string>
#include <vector>
#include "tokens.h"
#include "ast.h"

// [Parser] Mod

#pragma once
#ifndef PARSER_H
#define PARSER_H

class Parser {
    public:
        int column; // Current column
        int row;    // Current row

        void parse(std::vector<Token> tokens);

    private:
        void process();
        void advance();
        std::string eatype(TokenType type);
        bool eatid(std::string value);

        void parse_function();

        void parse_semiexpression();
        void parse_addition();
        void parse_subtraction();

        int position;               // Current position
        Token c_token;              // Current Token
        std::vector<Token> tokens;  // All the tokens
};

#endif