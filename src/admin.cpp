#include "admin.hpp"

Admin::Admin(){
    is_admin = false;
}

Admin::Admin(long id, string mFirstName, string mLastName, string mEmail,
     string password, string maddress) : User (id, mFirstName, mLastName, mEmail,
     password,maddress ){
        is_admin = false;
     }


bool Admin::is_admin() const{

}

// function template serialize is responsible for serializing and 
// deserializing Record objects to/from the specified Archive
template <typename Archive>
void serialize(Archive& archive, Admin& record) {
   archive( cereal::make_nvp("mid", record.mid),
        cereal::make_nvp("mFirstName", record.mFirstName),
      cereal::make_nvp("mLastName", record.mLastName),
      cereal::make_nvp("mEmail", record.mEmail),
      cereal::make_nvp("mPassword", record.mPassword),
      cereal::make_nvp("mAddress", record.mAddress));
}