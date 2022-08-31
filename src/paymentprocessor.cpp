#include "paymentprocessor.hpp"

PaymentProcessor::PaymentProcessor(){
    payment_helper = PaymentFactory::GetPaymentHelper();
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
    //CreditCard* creditCard = make_shared<CreditCard>;
    CreditCard* creditCard = new CreditCard;
    creditCard->SetOwnerName("Nash George");
    creditCard->SetCardNumber("22-11-03-44");
    creditCard->SetExpiryDate("11/25");
    creditCard->SetSecurityCode(117);

    payment_card = creditCard;

    return choice;
}

PaymentProcessor::~PaymentProcessor(){
    if (payment_helper != nullptr) {
        delete payment_helper;
        payment_helper = nullptr;
	}

    if (payment_card != nullptr) {
        delete payment_card;
        payment_card = nullptr;
	}
}

bool PaymentProcessor::charge_cost(int choice, double cost){
    payment_helper = PaymentFactory::GetPaymentHelper();

    	CreditCard* creditCard = nullptr;
		DebitCard* debitCard = nullptr;

		if ((creditCard = dynamic_cast<CreditCard*>(payment_card)))
			payment_helper->SetUserInfo(payment_card->GetOwnerName(), "");
		else if ((debitCard = dynamic_cast<DebitCard*>(payment_card))) {
			payment_helper->SetUserInfo(payment_card->GetOwnerName(), debitCard->GetBillingAddress());
		}
		payment_helper->SetCardInfo(payment_card->GetCardNumber(), payment_card->GetExpiryDate(), payment_card->GetSecurityCode());

		bool payment_status = payment_helper->MakePayment(cost);

		if (!payment_status)
			return false;	// Don't reserve this flight

		return true;
}


