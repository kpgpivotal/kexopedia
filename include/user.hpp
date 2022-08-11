#ifndef INCLUDE_USER_HPP_
#define INCLUDE_USer_HPP_

#include <iostream>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>
#include <vector>

#include "utils.hpp"

using namespace std;

class User {
   // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, User& record);

    public:
        User();
        User(long id, string mFirstName, string mLastName, string mEmail, string maddress);
        User(string firstName, string email);
        string getName() const;
        string getEmail() const;
        

    private:
        long mid;
        string mFirstName;
        string mLastName;
        string mEmail;
        string mAddress;
};

// function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, User& record) {
   archive( cereal::make_nvp("mid", record.mid),
        cereal::make_nvp("mFirstName", record.mFirstName),
      cereal::make_nvp("mLastName", record.mLastName),
      cereal::make_nvp("mEmail", record.mEmail),
      cereal::make_nvp("mAddress", record.mAddress));
}

#endif /* INCLUDE_User_HPP_ */