#ifndef INCLUDE_USER_HPP_
#define INCLUDE_USER_HPP_

#include <iostream>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>
#include <vector>

#include "utils.hpp"

using namespace std;
// Defining enum status
enum User_Status { Not_logged, Loggedin, Admin, Itinerary };

class User {
   // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, User& record);

    public:
        User();
        User(long id, string mFirstName, string mLastName, string mEmail, string password, string maddress);
        User(string firstName, string email);
        string get_name() const;
        string get_email() const;
        bool verify_password(string password) const;
        long getMid();
        void setMid(long mid);
        string get_firstName();
        void set_firstName(string mFirstName);
        string get_lastName();
        void set_lastName(string mLastName);
        void set_email(string mEmail);
        string get_password();
        void set_password(string mPassword);
        string get_address();
        void set_address(string mAddress);
        bool is_administrator() const;
        void make_administrator();

    private:
        long mid;
        string mFirstName;
        string mLastName;
        string mEmail;
        string mPassword;
        string mAddress;
        bool is_admin;
};

// function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, User& record) {
   archive( cereal::make_nvp("mid", record.mid),
        cereal::make_nvp("mFirstName", record.mFirstName),
      cereal::make_nvp("mLastName", record.mLastName),
      cereal::make_nvp("mEmail", record.mEmail),
      cereal::make_nvp("mPassword", record.mPassword),
      cereal::make_nvp("mAddress", record.mAddress),
      cereal::make_nvp("is_admin", record.is_admin));
}

#endif /* INCLUDE_User_HPP_ */