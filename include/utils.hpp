#ifndef UTILS_H
#define UTILS_H

#define pragma
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

const int INPUT_RETRY_COUNT = 3;
void print_line();
void message(string message);
int get_input_int(string prompt);
void clear_console();

#endif