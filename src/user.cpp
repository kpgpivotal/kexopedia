#include "user.hpp"
#include "utils.hpp"

User::User() : mFirstName{""},mLastName{""},mAddress{""} , mEmail{""},mPassword{}, is_admin{false} {}
User::User(long id, string firstName, string lastName, string email, string password, string address)
    :  mid{id}, mEmail{email}  , mPassword{password} , is_admin{false}{

    mFirstName = capitalize_first_letter(firstName);
    mLastName = capitalize_first_letter(lastName);
    mAddress = capitalize_first_letter(address);

}

User::User(string firstName, string email) : mEmail{email} {
    mFirstName = capitalize_first_letter(firstName);
}

string  User::get_name() const{
    return mFirstName + " " + mLastName;
}

string User::get_email() const{
    return mEmail;
}

bool User::verify_password(string password) const{
     
    if ( mPassword.compare(password) == 0 ) {
        return true;
    }

    return false;
}


long User::getMid()
{
    return mid;
}


void User::setMid(long id)
{
    mid = id;
}


string User::getMFirstName()
{
    return mFirstName;
}


void User::setMFirstName(string firstName)
{
    mFirstName = firstName;
}


string User::getMLastName()
{
    return mLastName;
}


void User::setMLastName(string lastName)
{
    mLastName = lastName;
}




void User::setMEmail(string email)
{
    mEmail = email;
}


string User::getMPassword()
{
    return mPassword;
}


void User::setMPassword(string password)
{
    mPassword = password;
}


string User::getMAddress()
{
    return mAddress;
}


void User::setMAddress(string address)
{
    mAddress = address;
}

bool User::is_administrator() const{
    return is_admin;
}

void User::make_administrator(){
    is_admin = true;
}
