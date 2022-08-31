
#ifndef INCLUDE_PAYMENT_PROCESSOR_H
#define INCLUDE_PAYMENT_PROCESSOR_H

#include <iostream>
#include <boost/lexical_cast.hpp>
#include "user.hpp"
#include "utils.hpp"
#include "paymentcard.hpp"


using namespace std;

class PayPalCreditCard {
public:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;
};

class PayPalOnlinePaymentAPI {
public:
	void SetCardInfo(const PayPalCreditCard* const card) {
	}
	bool MakePayment(double money) {
		
		message("$" + boost::lexical_cast<string>(money) + " spent on your card. Thanks for using PayPal servce.");
		return true;
	}
};

class StripeUserInfo {
public:
	string name;
	string address;
};

class StripeCardInfo {
public:
	string id;
	string expiry_date;
};

class StripePaymentAPI {
public:
	bool static WithDrawMoney(StripeUserInfo user, StripeCardInfo card, double money) {
		return true;
	}
};

class SquarePaymentAPI {
public:
	bool static WithDrawMoney(double amount) {
		message("$" + to_string(amount) + " spent on your card. Thanks for using PayPal servce.");
		
		return true;
	}
};

////////////////////////////////

class IPayment {
public:
	virtual void SetUserInfo(string name, string address) = 0;
	virtual void SetCardInfo(string id, string expiry_date, int ccv) = 0;
	virtual bool MakePayment(double money) = 0;
	virtual ~IPayment() {
	}
};

class PayPalPayment: public IPayment {
private:
	PayPalOnlinePaymentAPI paypal;
	PayPalCreditCard card;
public:
	virtual void SetUserInfo(string name, string address) {
		card.name = name;
		card.address = address;
	}
	virtual void SetCardInfo(string id, string expiry_date, int ccv) {
		card.id = id;
		card.expiry_date = expiry_date;
		card.ccv = ccv;
	}
	virtual bool MakePayment(double money) {
		paypal.SetCardInfo(&card);
		return paypal.MakePayment(money);
	}
};

class StripePayment: public IPayment {
private:
	StripeCardInfo card;
	StripeUserInfo user;
public:
	virtual void SetUserInfo(string name, string address) {
		user.name = name;
		user.address = address;
	}
	virtual void SetCardInfo(string id, string expiry_date, int ccv) {
		card.id = id;
		card.expiry_date = expiry_date;
	}
	virtual bool MakePayment(double money) {
		return StripePaymentAPI::WithDrawMoney(user, card, money);
	}
};

class SquarePayment: public IPayment {
private:
	string name;
	string address;
	string id;
	string expiry_date;
	int ccv;

public:
	virtual void SetUserInfo(string name_, string address_) {
		name = name_;
		address = address_;
	}
	virtual void SetCardInfo(string id_, string expiry_date_, int ccv_) {
		id = id_;
		expiry_date = expiry_date_;
		ccv = ccv_;
	}
	virtual bool MakePayment(double money) {

		return SquarePaymentAPI::WithDrawMoney(money);
	}
};

class PaymentFactory {
public:
	static IPayment* GetPaymentHelper() {
		if (true)
			return new SquarePayment();
		else if (true)
			return new PayPalPayment();
		else
			return new StripePayment();
	}
};


class PaymentProcessor{
    public:
        PaymentProcessor();
		~PaymentProcessor();
        int get_payment_choice();
		bool charge_cost(int choice,  double cost);

    private:
        int list_payment_options();
        int get_selected_choice();
		IPayment* payment_helper;
		PaymentCard* payment_card;


};

#endif
