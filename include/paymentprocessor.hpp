
#ifndef INCLUDE_PAYMENT_PROCESSOR_H
#define INCLUDE_PAYMENT_PROCESSOR_H

#include <iostream>
#include "user.hpp"
#include "utils.hpp"

using namespace std;

class PaymentProcessor{
    public:
        PaymentProcessor();
        int get_payment_choice();

    private:
        int list_payment_options();
        int get_selected_choice();


};

#endif