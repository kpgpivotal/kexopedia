#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "utils.hpp"

const int EXIT_MENU_CHOICE = 0;


class UIManager {
    public:
        int show_menu();

    private:
        int process_user_choice( int choice);
        int login();
        int signup();
};


#endif 