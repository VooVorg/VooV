#include <string>
#include "lexer.h"
#include "common.h"

std::vector<Token> Lexer::tokenize(std::string content) {
    this->content = content;
    this->column = 1;
    this->row = 1;
    this->position = 0;
    this->c_char = this->content[this->position];
    this->tokens = {};
    
    while (static_cast<std::string::size_type>(this->position) < content.length()) {
        this->process();
    }

    return this->tokens;
}
