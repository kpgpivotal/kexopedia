#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "utils.hpp"
#include "usermanager.hpp"
#include "user.hpp"

const int EXIT_MENU_CHOICE = 0;


class UIManager {
    public:
        UIManager();
        int show_menu();

    private:
        UserManager user_manager;
        Menu the_menu;
        User_Status the_ustatus;
        int process_user_choice( int choice);
        int login();
        int signup();
        int administration();
        int list_users();
};


#endif 