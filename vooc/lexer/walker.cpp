#include <string>
#include "lexer.h"
#include "common.h"
#include <iostream>

void Lexer::process() {
    if ( is_number(this->c_char) ) {
        this->tokens.push_back(
            this->numeric_lex()
        );
    }
    else if ( is_alphanumeric(this->c_char) ) {
        this->tokens.push_back(
            this->alnum_lex()
        );
    }

    else if ( is_symbol(this->c_char) ) {
        this->tokens.push_back(
            this->symbol_lex()
        );
    }

    else if ( this->c_char == '"') {
        this->tokens.push_back(
            this->string_lex()
        );
    }
    
    else if ( this->c_char == '\'') {
        this->tokens.push_back(
            this->char_lex()
        );
    }

    else if ( this->c_char == '`') {
        this->tokens.push_back(
            this->backstring_lex()
        );
    }

    else if ( is_space(this->c_char) ) {
        this->advance();
    }

    else if ( this->c_char == '\n') {
        this->row++;
        this->column=0;
        this->advance();
    }

    else {
        std::cout << "Unknown `" << this->c_char << "`" << std::endl;
        this->advance();
    }
}

void Lexer::advance() {
    this->position++;
    this->column++;
    this->c_char = this->content[this->position];
}
