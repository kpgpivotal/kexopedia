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

		case 10 : {
			list_users();
			break;
		}

  
		default : {
			message("Invalid input. Please try again");
		}
	}
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
    