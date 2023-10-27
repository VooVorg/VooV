#include <string>
#include "parser.h"
#include "common.h"
#include "tokens.h"

#include <iostream>

void Parser::process() {
    switch (this->c_token.t_type) {
        case TokenType::IDENTIFIER: {
            if (this->c_token.t_value == "procedure") {
                this->parse_function();
            }
            else {
                this->advance();
            }
            break;
        }
        default: { this->advance(); break; }
    }
}

void Parser::advance() {
    this->position++;
    if ( (static_cast<std::string::size_type>(this->position) >= this->tokens.size() ) ) {
        return;
    }
    this->c_token=tokens[this->position];
    
    this->row = this->c_token.t_row;
    this->column = this->c_token.t_col_e;
}

std::string Parser::eatype(TokenType type) {
    if (this->c_token.t_type != type) {
        std::cout<< ("Not expected!  `") << this->c_token.t_value << "`" << std::endl;
        exit(1);
        return "";
    }
    std::string value = this->c_token.t_value;
    this->advance();
    return value;
}

bool Parser::eatid(std::string value) {
    if (this->c_token.t_value != value) {
        std::cout<< ("Not expected!  `") << this->c_token.t_value << "`" << std::endl;
        exit(1);
        this->advance();
        return false;
    }
    this->advance();
    return true;
}