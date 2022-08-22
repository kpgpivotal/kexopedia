#include "paymentprocessor.hpp"

PaymentProcessor::PaymentProcessor(){

}



int PaymentProcessor::get_payment_choice(){
    int choice{};

    list_payment_options();

    choice = get_selected_choice();
    return choice;
}


int PaymentProcessor::list_payment_options(){
    message("Select a payment choice");
    message("1: Debit card: Owner Nash George card number xx1234");
    message("2: Credit card: Master Card Owner Nash George card number xx15622");
    message("3: Credit card: Visa Owner Nash George card number xx15678\n");

    return 1;
}

int PaymentProcessor::get_selected_choice(){
    int choice{};

    choice = get_input_int("Enter number for payment optin (-1 to cancel)");
    return choice;
}
