#include <string>
#include <vector>

#pragma once
#ifndef COMMON_H
#define COMMON_H

// A Common header for different sections

std::string read_file(const char* filename);
bool argc_parse(int argc);
std::string join_vec(const std::vector<std::string>& elements, const std::string& separator);
bool is_number(char value);
bool is_alphanumeric(char value);
bool is_symbol(char value);
bool is_space(char value);

#endif
