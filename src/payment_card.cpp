#include "paymentcard.hpp"

const string& PaymentCard::get_card_number() const {
		return card_number;
}

void PaymentCard::set_card_number(const string& cardNumber) {
    card_number = cardNumber;
}

const string& PaymentCard::get_expiry_date() const {
    return expiry_date;
}

void PaymentCard::set_expiry_date(const string& expiryDate) {
    expiry_date = expiryDate;
}

const string& PaymentCard::get_owner_name() const {
    return owner_name;
}

void PaymentCard::set_owner_name(const string& ownerName) {
    owner_name = ownerName;
}

int PaymentCard::get_security_code() const {
    return security_code;
}

void PaymentCard::set_security_code(int securityCode) {
    security_code = securityCode;
}

string PaymentCard::to_string() const {
    ostringstream oss;
    oss << "Owner: " << owner_name << " Card number: " << card_number << " Expiry date: " << expiry_date;
    // security_code shouldn't be displayed! for security reasons.
    return oss.str();
}



 PaymentCard::~PaymentCard() {

}



const string& DebitCard::get_billingAddress() const {
    return billing_address;
}

void DebitCard::set_billingAddress(const string& billingAddress) {
    billing_address = billingAddress;
}

/*
PaymentCard* DebitCard::clone() const  {
    return new DebitCard(*this);
}
*/

string DebitCard::to_string() const {
    ostringstream oss;
    oss << "[Debit Card]: " << PaymentCard::to_string() << " Billing Address: " << billing_address;
    return oss.str();
}



string CreditCard::to_string() const  {
    ostringstream oss;
    oss << "[Credit Card]: " << PaymentCard::to_string();
    return oss.str();
}

/*
PaymentCard* CreditCard::clone() const  {
    return new CreditCard(*this);
}
*/
