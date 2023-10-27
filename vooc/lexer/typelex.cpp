#include <string>
#include "lexer.h"
#include "common.h"

Token Lexer::numeric_lex() {
    std::string value;
    int col_s = this->column;
    int row = this->row;
    TokenType type = TokenType::INTEGER;

    while ( is_number(this->c_char) || this->c_char == '.') {
        if (this->c_char == '.') {type = TokenType::FLOAT;}

        value.push_back(this->c_char);
        this->advance();
    }
    return Token {
        value,             // t_value
        type,              // t_type
        col_s,             // t_col_s
        (this->column-1),  // t_col_e
        row                // t_row
    };
}

Token Lexer::alnum_lex() {
    std::string value;
    int col_s = this->column;
    int row = this->row;
    TokenType type = TokenType::IDENTIFIER;

    while ( is_alphanumeric(this->c_char) || this->c_char == '.') {
        value.push_back(this->c_char);
        this->advance();
    }
    return Token {
        value,             // t_value
        type,              // t_type
        col_s,             // t_col_s
        (this->column-1),  // t_col_e
        row                // t_row
    };
}

Token Lexer::symbol_lex() {
    std::string value(1, this->c_char);
    int col_s = this->column;
    int col_e = this->column;
    int row = this->row;
    TokenType type = TokenType::IDENTIFIER;
    
    switch (this->c_char) {
        case '=' : { type=TokenType::EQUAL; break; }
        case '+' : { type=TokenType::PLUS; break; }
        case '-' : { type=TokenType::MINUS; break; }
        case '*' : { type=TokenType::MULT; break; }
        case '/' : { type=TokenType::DIV; break; }
        case '>' : { type=TokenType::GREATER; break; }
        case '<' : { type=TokenType::SMALLER; break; }
        case ':' : { type=TokenType::COLON; break; }
        case ';' : { type=TokenType::SEMICOLON; break; }
        case '{' : { type=TokenType::L_BRACE; break; }
        case '}' : { type=TokenType::R_BRACE; break; }
        case '[' : { type=TokenType::L_BRACKET; break; }
        case ']' : { type=TokenType::R_BRACKET; break; }
        case '(' : { type=TokenType::L_PAREN; break; }
        case ')' : { type=TokenType::R_PAREN; break; }
        //case '`' : { type=TokenType::BACKTICK; break; }
        case ',' : { type=TokenType::COMMA; break; }
        case '!' : { type=TokenType::NOT; break; }
        //case '\'' :{ type=TokenType::QUOTE; break; }
        //case '"' : { type=TokenType::DQUOTE; break; }
    }

    this->advance();

    return Token {
        value,
        type,
        col_s,
        col_e,
        row
    };
}

Token Lexer::string_lex() {
    std::string value(1, this->c_char);
    int col_s = this->column;
    int col_e;
    int row = this->row;
    TokenType type = TokenType::STRING;
    char to_find = this->c_char;

    this->advance();
    while (this->c_char != to_find) {
        value.push_back(this->c_char);
        this->advance();
    }
    value.push_back(this->c_char);
    col_e = this->column;
    this->advance();
    

    return Token {
        value,
        type,
        col_s,
        col_e,
        row
    };
}
Token Lexer::char_lex() {
    std::string value(1, this->c_char);
    int col_s = this->column;
    int col_e;
    int row = this->row;
    TokenType type = TokenType::CHAR;
    char to_find = this->c_char;

    this->advance();
    while (this->c_char != to_find) {
        value.push_back(this->c_char);
        this->advance();
    }
    value.push_back(this->c_char);
    col_e = this->column;
    this->advance();
    

    return Token {
        value,
        type,
        col_s,
        col_e,
        row
    };
}
Token Lexer::backstring_lex() {
    std::string value(1, this->c_char);
    int col_s = this->column;
    int col_e;
    int row = this->row;
    TokenType type = TokenType::BACKTICK_STRING;
    char to_find = this->c_char;

    this->advance();
    while (this->c_char != to_find) {
        value.push_back(this->c_char);
        this->advance();
    }
    value.push_back(this->c_char);
    col_e = this->column;
    this->advance();
    

    return Token {
        value,
        type,
        col_s,
        col_e,
        row
    };
}