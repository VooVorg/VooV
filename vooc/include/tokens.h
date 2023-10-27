#include <string>


#pragma once
#ifndef TOKENS_H
#define TOKENS_H

enum TokenType {
    INTEGER,
    FLOAT,
    IDENTIFIER,

    EQUAL,
    PLUS,
    MINUS,
    MULT,
    DIV,

    GREATER,
    SMALLER,
    NOT,

    COLON,
    SEMICOLON,
    L_BRACE,
    R_BRACE,
    L_BRACKET,
    R_BRACKET,
    L_PAREN,
    R_PAREN,

    COMMA,
    STRING,
    CHAR,
    
    BACKTICK_STRING,
};

struct Token {
    std::string  t_value;
    TokenType    t_type;
    int          t_col_s;
    int          t_col_e;
    int          t_row;
};

#endif
