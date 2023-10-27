#include <string>
#include <vector>
#include <functional>

// [AST] Mod

#pragma once
#ifndef AST_H
#define AST_H

struct Variable;
struct Constant;
struct FunctionCall;
struct Program;

// Base class for expressions
struct Expression {
    virtual ~Expression() {};
};

struct Loop : public Expression {
    virtual ~Loop() {};
};

struct Conditional : public Expression {
    virtual ~Conditional() {};
};

struct Keyword : public Expression {
    virtual ~Keyword() {};
}; 

// Derived classes for different types of expressions
struct Variable : public Expression {
    std::string name;
    Variable(const std::string& varName="") : name(varName) {}
};

// Base class for constants
struct Constant : public Expression {
    virtual ~Constant() {};
};

struct Operation : public Expression {
    char op;  // Operator (e.g., +, -, *, /)
    virtual ~Operation() {}
};

struct If : public Conditional {
    Expression* condition;
    Expression* body;
};

struct Elseif : public Conditional {
    Expression* condition;
    Expression* body;
};

struct Else : public Conditional {
    Expression* body;
};

struct For : public Loop {
    Expression* condition;
    Expression* body;
};

struct While : public Loop {
    Expression* condition;
    Expression* body;
};

struct Return : public Keyword {
    Expression* exp;
    Return(Expression* expression=nullptr) : exp(expression) {}
};

struct Continue : public Keyword {};

struct Break : public Keyword {};

struct IntConstant : public Constant {
    int value;
    IntConstant(int val=0) : value(val) {}
};

struct FloatConstant : public Constant {
    float value;
    FloatConstant(float val = 0.00f) : value(val) {}
};

struct StringConstant : public Constant {
    std::string value;
    StringConstant(std::string val = "") : value(val) {}
};

struct FunctionCall : public Expression {
    std::string functionName;
    std::vector<Expression*> arguments;
    FunctionCall(std::string fun_name = "", const std::vector<Expression*>& fun_args = {})
        : functionName(fun_name), arguments(fun_args) {}
};

struct Block : public Expression {
    std::vector<Expression*> expressions;
    Block(std::vector<Expression*> exps = {}) : expressions(exps) {}
};

struct BinaryOperation : public Operation {
    Expression* left;
    Expression* right;
};

struct UnaryOperation : public Operation {
    Expression* operand;
};

struct Addition : public BinaryOperation {
    Addition(Expression* left, Expression* right) {
        this->op = '+';
        this->left = left;
        this->right = right;
    }
};

struct Subtraction : public BinaryOperation {
    Subtraction(Expression* left, Expression* right) {
        this->op = '-';
        this->left = left;
        this->right = right;
    }
};

struct Negation : public UnaryOperation {
    Negation(Expression* operand) {
        this->op = '-';
        this->operand = operand;
    }
};

struct Not : public UnaryOperation {
    Not(Expression* operand) {
        this->op = '!';
        this->operand = operand;
    }
};

struct Equal : public BinaryOperation {
    Equal(Expression* left, Expression* right) {
        this->op = '=';
        this->left = left;
        this->right = right;
    }
};

struct Function {
    std::string name;
    std::string type;
    std::vector<std::vector<std::string>> parameters;
    Expression* body;  // This can be a single expression or a block of expressions
     Function(
        std::string f_name = "",
        std::string f_type = "",
        std::vector<std::vector<std::string>> f_params = {},
        Expression* f_body = nullptr
    ) : name(f_name), type(f_type), parameters(f_params), body(f_body) {}

    void iterateExpressions(std::function<void(Expression*)> callback) {
        if (body) {
            if (auto block = dynamic_cast<Block*>(body)) {
                for (Expression* exp : block->expressions) {
                    callback(exp);
                }
            } else {
                callback(body);
            }
        }
    }
};

struct Program {
    std::vector<Function> functions;
};

#endif
