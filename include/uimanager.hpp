#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "utils.hpp"
#include "usermanager.hpp"

const int EXIT_MENU_CHOICE = 0;


class UIManager {
    public:
        int show_menu();

    private:
        UserManager user_manager;
        int process_user_choice( int choice);
        int login();
        int signup();
        int administration();
};


#endif 