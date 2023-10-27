#include <string>
#include <vector>
#include "tokens.h"
#include "ast.h"
#include "parser.h"

void Parser::parse_semiexpression() {
    while (this->c_token.t_type != TokenType::SEMICOLON) {
        this->advance();
    }
}  