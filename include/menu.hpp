#ifndef INCLUDE_MENU_H
#define INCLUDE_MENU_H

#include <iostream>
#include "user.hpp"

using namespace std;

class Menu{
    public:
        Menu();
        int show_menu( User_Status current_status);

    private:
        User_Status current_status;
        int show_login_menu();
        int show_user_menu();
        int show_admin_menu();
        int show_itinerary_menu();
        
};

#endif