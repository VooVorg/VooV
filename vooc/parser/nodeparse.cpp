#include <string>
#include <vector>
#include "parser.h"
#include "common.h"
#include "tokens.h"

#include <iostream>

void Parser::parse_function() {
    this->advance();
    std::string name = this->eatype(TokenType::IDENTIFIER);
    std::vector<std::vector<std::string>> parameters;
    this->eatype(TokenType::L_BRACKET);

    std::string ptype = "";
    std::string pname = "";
    while (this->c_token.t_type != TokenType::R_BRACKET) {
        ptype = this->eatype(TokenType::IDENTIFIER);
        pname = this->eatype(TokenType::IDENTIFIER);
        if ( this->c_token.t_type == TokenType::COMMA ) { parameters.push_back({ptype, pname}); this->advance(); }
    }
    this->advance();
    if (ptype != "" && pname != "") { parameters.push_back({ptype, pname}); }

    this->eatype(TokenType::MINUS);
    this->eatype(TokenType::GREATER);
    std::string type = this->eatype(TokenType::IDENTIFIER);

    std::vector<std::string> operations;

    if (this->c_token.t_type == TokenType::SEMICOLON) {
        this->advance();
    } else {
        this->eatype(TokenType::L_BRACE);
        int braceCount = 1;
        while (braceCount > 0) {
            if (this->c_token.t_type == TokenType::L_BRACE) {
                braceCount++;
            } else if (this->c_token.t_type == TokenType::R_BRACE) {
                braceCount--;
            }
            if (braceCount > 0) {
                operations.push_back(this->c_token.t_value);
            }
            this->advance();
        }
    }

    std::cout << type << " " << name << " (";
    for (std::vector<std::string> param : parameters) {
        std::cout << param[0] << " " << param[1] << ", ";
    }
    std::cout << ") " << std::endl;
    std::cout << join_vec(operations, "") << std::endl;
}
