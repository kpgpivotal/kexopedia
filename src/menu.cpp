#include "menu.hpp"

Menu::Menu() {
    current_status = Not_logged;
}


int Menu::show_menu(User_Status current_status){
    int choice{};

    switch ( current_status)
    {
        case Not_logged : {
            choice = show_login_menu();
            break;
        }
        case Admin : {
            choice = show_admin_menu();
            break;
        }
        case Loggedin : {
            choice = show_user_menu();
            break;
        }

        case Itinerary : {
            choice = show_itinerary_menu();
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
     int choice{};

    message("\n\tKexopedia Menu");
    print_line();
    message("15: View Profile");
    message("16: Make Itinerary");
    message("17: List My Itineraries");
    message("9: Logout");
    print_line();
    choice  = get_input_int("\nPlease enter your choice: ");
    clear_console();

    return choice ;
}

int Menu::show_itinerary_menu(){
     int choice{};

    message("\n\tKexopedia Menu");
    print_line();
    message("21: Add Hotel");
    message("22: Add Flight");
    message("23: Done");
    message("24: Cancel");
    print_line();
    choice  = get_input_int("\nPlease enter your choice: ");
    clear_console();

    return choice ;
}
int Menu::show_admin_menu(){
    int choice{};

    message("\n\tKexopedia Menu");
    print_line();
    message("10: List users");
    message("9: Logout");
    print_line();
    choice  = get_input_int("\nPlease enter your choice: ");
    clear_console();

    return choice ;
}
