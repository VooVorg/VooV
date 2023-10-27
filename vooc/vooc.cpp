#include <stdio.h>
#include <string>
#include "common.h"
#include "lexer.h"
#include "parser.h"
#include "tokens.h"

#include <iostream>

void routine(int argc, char** argv) {
	std::string fileContent = read_file(argv[1]);
	std::cout << fileContent << std::endl;

	Lexer* lexer = new Lexer();
	Parser* parser = new Parser();

	std::vector<Token> tokens = lexer->tokenize(fileContent);

	parser->parse(tokens);
}

int main(int argc, char** argv) {
	if (!argc_parse(argc)) { return -1; };
	routine(argc, argv);
	return 0;
}