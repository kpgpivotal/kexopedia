#include "uimanager.hpp"

UIManager::UIManager(){
	the_ustatus = Not_logged;

}

int UIManager::show_menu(){
    int choice {};

	while (true) {
		choice = the_menu.show_menu(the_ustatus);

		if ( EXIT_MENU_CHOICE == choice) {
			message("\nThank you. Looking forward to your next visit.\n");
			break;
    	}

		process_user_choice( choice);
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

		case 3 : {
			administration();
			break;
		}

		case 9 : {
			logout();
			break;
		}

		case 10 : {
			list_users();
			break;
		}

		case 11 : {
			list_users();
			break;
		}

		case 12 : {
			list_users();
			break;
		}

		case 15 : {
			make_booking();
			break;
		}

		case 16 : {
			list_booking();
			break;
		}

  
		default : {
			message("Invalid input. Please try again");
		}
	}
	return 1;
}

int UIManager::logout(){
	bool is_yes{};
	is_yes = get_y_n_confirmation();
	if ( true == is_yes) {
		the_ustatus = Not_logged;
		message("User logged off.");
		return 1;
	}

	// No change in status
	return 0;
}

int UIManager::make_booking(){
	message("Make Booking");
	return 1;
}

int UIManager::list_booking(){
	message("List Booking");
	return 1;
}

int UIManager::list_users(){
	user_manager.list_users();
	return 1;
}

int UIManager::administration(){
	user_manager.administration();

	return 1;
}

int UIManager::login(){
	bool is_authenicated{};

    the_ustatus = user_manager.login();

    return 1;
}
        
int UIManager::signup(){
	User newuser{};

    user_manager.signup(newuser);

    return 1;
}
    