#include <iostream>
#include "kexopedia.hpp"
#include "paymentprocessor.hpp"

using namespace std;

void module_test();

int main(int argc, char** argv) {

    Kexopedia kapp{};

    //module_test();
    kapp.launch_app();
    
    return 0;
}


void module_test(){
    PaymentProcessor payment_processor{};
    int choice{};

    choice = payment_processor.get_payment_choice();
    cout << "\nUser choice : " << choice;
}