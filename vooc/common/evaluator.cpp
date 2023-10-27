#include <string>
#include <ctype.h>

bool is_number(char value) {
    return isdigit(value);
}

bool is_alphanumeric(char value) {
    return isalnum(value);
}

bool is_symbol(char value) {
    switch (value) {
        case '=' : { return true; }
        case '+' : { return true; }
        case '-' : { return true; }
        case '*' : { return true; }
        case '/' : { return true; }
        case '>' : { return true; }
        case '<' : { return true; }
        case ':' : { return true; }
        case ';' : { return true; }
        case '{' : { return true; }
        case '}' : { return true; }
        case '[' : { return true; }
        case ']' : { return true; }
        case '(' : { return true; }
        case ')' : { return true; }
        case ',' : { return true; }
        case '!' : { return true; }
        default  : { return false;}
    }
}

bool is_space(char value) {
    return isspace(value);
}