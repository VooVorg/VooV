#include <string>
#include "parser.h"
#include "common.h"
#include "tokens.h"
#include "ast.h"

#include <iostream>

//Variable* var = dynamic_cast<Variable*>(exp)

/*void test_assign() {
    Program myProgram;

    Function sumFunction("sum", "int");
    sumFunction.parameters = {{"int", "a"}, {"int", "b"}};
    sumFunction.body = new Block({
        (new Subtraction(new Variable("a"), new Variable("b"))),
        (new Return(new Addition(new Variable("a"), new Variable("b"))))
    });

    FunctionCall sum_call(
        "sum", {new IntConstant(42), new IntConstant(50)}
    );

    Function mainFunction("main", "void", {},
        {&sum_call}
    );

    myProgram.functions = {sumFunction, mainFunction};

    for (Function fun : myProgram.functions) {
        std::cout << fun.type << " " << fun.name << std::endl;
        fun.iterateExpressions([](Expression* exp) {
            parse_exp(exp, 1);
        });
    }
}*/

void Parser::parse(std::vector<Token> tokens) {
    this->tokens = tokens;
    this->position = 0;
    this->c_token = tokens[this->position];

    while ( (static_cast<std::string::size_type>(this->position) < tokens.size() ) ) {
        this->process();
    }
}