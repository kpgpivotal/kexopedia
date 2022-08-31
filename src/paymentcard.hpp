#ifndef INCLUDE_PAYMENT_CARD_H_
#define INCLUDE_PAYMENT_CARD_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>

using namespace std;

class PaymentCard {
   template<typename Archive>
   friend void serialize(Archive& archive, PaymentCard& record);

protected:
	string owner_name;
	string card_number;
	string expiry_date;
	int security_code;	
	string type;		// e.g. Visa or MasterCard
    
public:
	const string& get_card_number() const;
	void set_card_number(const string& cardNumber);
	const string& get_expiry_date() const;
	void set_expiry_date(const string& expiryDate);
	const string& get_owner_name() const;
	void set_owner_name(const string& ownerName);
	int get_security_code() const;
	void set_security_code(int securityCode);
	virtual string to_string() const;
	virtual PaymentCard* clone() const = 0;
	virtual ~PaymentCard();
};

template <typename Archive>
void serialize(Archive& archive, PaymentCard& record) {
   archive( cereal::make_nvp("owner_name", record.owner_name),
        cereal::make_nvp("card_number", record.card_number),
      cereal::make_nvp("expiry_date", record.expiry_date),
      cereal::make_nvp("security_code", record.security_code),
      cereal::make_nvp("type", record.type)
      );
}

class DebitCard: public PaymentCard {
protected:
	string billing_address;

public:
	const string& get_billingAddress() const;

	void set_billingAddress(const string& billingAddress);

	virtual PaymentCard* clone() const override {
		return new DebitCard(*this);
	}

	virtual string to_string() const;
};

class CreditCard: public PaymentCard {
protected:
	// Say we don't keep billing address
	// Although no attributes, but better have separate class to differentiate them if needed
public:
	virtual string to_string() const override;

	virtual PaymentCard* clone() const override {
		return new CreditCard(*this);
	}
};


#endif 