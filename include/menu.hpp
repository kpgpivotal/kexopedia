#ifndef INCLUDE_MENU_H
#define INCLUDE_MENU_H

#include <iostream>
#include "user.hpp"

using namespace std;

class Menu{
    public:
        Menu();
        int show_menu( User_Status the_ustatus);

    private:
        User_Status the_ustatus;
        int show_login_menu();
        int show_user_menu();
        int show_admin_menu();
        
};

#endif