#include "uimanager.hpp"


int UIManager::show_menu(){
    int choice{};

    while (true) {
        message("\n\tKexopedia Menu");
        print_line();
        message("1: Login");
        message("2: Sign Up");
        message("0: Exit");
        print_line();
        choice  = get_input_int("\nPlease enter your choice: ");
        clear_console();

        if ( EXIT_MENU_CHOICE == choice) {
			message("\nThank you. Looking forward to your next visit.\n");
			break;
		}

		process_user_choice(choice);
    }

    return 1;
}


int UIManager::process_user_choice(int choice){

    switch ( choice ) {
		case 1 : {
			login();
			break;
		}

		case 2 : {
			signup();
			break;
		}
        /*
		case 3 : {
			borrowers_info();
			break;
		}

		case 4 : {
			print_library_by_id();
			break;
		}

		case 5 : {
			print_library_by_bookname();
			break;
		}

		case 6 : {
			add_user();
			break;
		}

		case 7 : {
			borrow_book();
			break;
		}

		case 8 : {
			return_book();
			break;
		}

		case 9 : {
			print_members();
			break;
		}
*/
		default : {
			message("Invalid input. Please try again");
		}
	}
	return 1;
}

int UIManager::login(){
    message("login");

    return 1;
}
        
int UIManager::signup(){
    message("signup");

    return 1;
}
    