#include "menu.hpp"

Menu::Menu() {
    the_ustatus = Not_logged;
}


int Menu::show_menu(User_Status the_ustatus){
    int choice{};

    switch ( the_ustatus)
    {
    case Not_logged : {
        choice = show_login_menu();
        break;
    }
    case Admin : {
        choice = show_admin_menu();
        break;
    }

    default:
        break;
    }
    return choice;
}

int Menu::show_login_menu(){
    int choice{};

    message("\n\tKexopedia Menu");
    print_line();
    message("1: Login");
    message("2: Sign Up");
    message("0: Exit");
    print_line();
    choice  = get_input_int("\nPlease enter your choice: ");
    clear_console();

    return choice ;
}

int Menu::show_user_menu(){
    return 1;
}

int Menu::show_admin_menu(){
    int choice{};

    message("\n\tKexopedia Menu");
    print_line();
    message("10: List users");
    message("0: Exit");
    print_line();
    choice  = get_input_int("\nPlease enter your choice: ");
    clear_console();

    return choice ;
}
