#include "utils.hpp"

void message(string message){
    cout <<  message << endl;
}


void print_line() {
    cout << "-----------------------------------------" << endl;
}


int get_input_int(string prompt){
    string input{};
    int int_val{-1};
  
    cout <<  prompt << " : " ;
    std::getline(std::cin, input);
    try{ 
        int_val = stol(input);
    }
    catch (...){}

    return int_val;
}

void clear_console() {
    system("clear");
}