#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <string_view>
#include <bits/stdc++.h>



using namespace std;
using namespace std::literals;

const int INPUT_RETRY_COUNT = 10;
void print_line();
void message(string message);
void error_message(string message);
int get_input_int(string prompt);
void clear_console();
string capitalize_first_letter(string text);
bool is_valid_email(string email);
string get_input_email(string prompt);
string get_input_string(string prompt);
bool isChar(char c);
bool isDigit(const char c);
long get_input_long(string prompt);



#endif