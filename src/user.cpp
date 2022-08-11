#include "user.hpp"
#include "utils.hpp"

User::User() : mFirstName{""},mLastName{""},mAddress{""} , mEmail{""} {}
User::User(long id, string firstName, string lastName, string email, string address)
    :  mid{id}, mEmail{email}  {

    mFirstName = capitalize_first_letter(firstName);
    mLastName = capitalize_first_letter(lastName);
    mAddress = capitalize_first_letter(address);

}

User::User(string firstName, string email) : mEmail{email} {
    mFirstName = capitalize_first_letter(firstName);
}

string  User::getName() const{
    return mFirstName + " " + mLastName;
}

string User::getEmail() const{
    return mEmail;
}