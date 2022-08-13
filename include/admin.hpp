#ifndef INCLUDE_ADMIN_HPP_
#define INCLUDE_ADMIN_HPP_

#include <iostream>
#include <string>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>
#include <vector>

#include "utils.hpp"
#include "user.hpp"

using namespace std;

class Admin : public User {
   // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, Admin& record);

    public:
        Admin();
        Admin(long id, string mFirstName, string mLastName, string mEmail, string password, string maddress);
        bool is_admin() const;

    private:
        bool is_admin;

};

#endif