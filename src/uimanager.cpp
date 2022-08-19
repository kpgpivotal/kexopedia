#include "uimanager.hpp"

UIManager::UIManager()
{
	current_status = Not_logged;
	read_config_file();
	if (0 == valid_choice_map.size())
	{
		// choice map is not initialized using json file. use defualt values
		init_choice_map();
	}
	else
	{
		message("Choice map initialized using json file.");
	}
}

int UIManager::init_choice_map()
{
	not_logged_vector = {1, 2, 0};
	logged_vector = {15, 16, 17, 9};
	admin_vector = {10, 9};
	itinerary_vector = {21, 22, 23, 24};
	valid_choice_map.insert(pair<User_Status, vector<int>>(Not_logged, not_logged_vector));
	valid_choice_map.insert(pair<User_Status, vector<int>>(Loggedin, logged_vector));
	valid_choice_map.insert(pair<User_Status, vector<int>>(Admin, admin_vector));
	valid_choice_map.insert(pair<User_Status, vector<int>>(Itinerary, itinerary_vector));
	message("Choice map initialized using default values.");

	return 1;
}

UIManager::~UIManager()
{
	try
	{
		if (std::ofstream output{CONFIG_FILE_NAME})
		{
			cereal::JSONOutputArchive archive{output};
			archive(
				cereal::make_nvp("valid_choice_map", valid_choice_map), cereal::make_nvp("itinerary_manager", itinerary_manager)); // serialize records
		}
	}
	catch (...)
	{
		error_message("Unable to write configuration file.");
	}
}

int UIManager::read_config_file()
{
	try
	{

		// deserialize
		// deserialize JSON from text file into vector of Records
		if (std::ifstream input{CONFIG_FILE_NAME})
		{
			cereal::JSONInputArchive archive{input};
			// archive(user_manager); // deserialize records
			archive(valid_choice_map);
			archive(itinerary_manager);

			std::cout << "\nDeserialized records\n";
		}
	}
	catch (...)
	{
		error_message("Unable to read configuration file");
	}

	return 1;
}

int UIManager::show_menu()
{
	int choice{};
	int ret_val{};
	while (true)
	{
		choice = the_menu.show_menu(current_status);

		if (false == is_valid_choice(choice))
		{
			continue;
		}
		ret_val = process_user_choice(choice);
		if (EXIT_MENU_CHOICE == ret_val)
		{
			break;
		}
	}

	return 1;
}

bool UIManager::is_valid_choice(int choice)
{
	bool result_value{};
	vector<int> choice_vector{};

	auto it = valid_choice_map.find(current_status);
	if (it == valid_choice_map.end())
	{
		message("Invalid choice!");
		return false;
	}

	choice_vector = it->second;
	auto itv = find(choice_vector.begin(), choice_vector.end(), choice);
	if (itv == choice_vector.end())
	{
		message("Invalid choice!");
		return false;
	}

	return true;
}

int UIManager::process_user_choice(int choice)
{
	int retval = 0;
	if (false == is_valid_choice(choice))
	{
		message("Invalid input. Please try again");
		return 0;
	}

	switch (choice)
	{

	case EXIT_MENU_CHOICE:
	{
		// exit option
		bool is_yes{};
		is_yes = get_y_n_confirmation();
		if (is_yes)
		{
			message("\nThank you. Looking forward to your next visit.\n");
			return EXIT_MENU_CHOICE;
		}
		//
		break;
	}

	case 1:
	{
		login();
		break;
	}

	case 2:
	{
		signup();
		break;
	}

	case 3:
	{
		administration();
		break;
	}

	case 9:
	{
		logout();
		break;
	}

	case 10:
	{
		list_users();
		break;
	}

	case 11:
	{
		list_users();
		break;
	}

	case 15:
	{
		view_profile();
		break;
	}

	case 16:
	{
		make_itinerary();
		break;
	}

	case 17:
	{
		list_my_itineraries();
		break;
	}

	case 21:
	{
		add_hotel();
		break;
	}

	case 22:
	{
		add_flight();
		break;
	}

	case 23:
	{
		itinerary_ok();
		break;
	}
	case 24:
	{
		itinerary_cancel();
		break;
	}

	default:
	{
		message("Invalid input. Please try again");
	}
	}
	return 1;
}

int UIManager::list_my_itineraries()
{
	itinerary_manager.list_my_itineraries(user_manager.get_active_user_id());
	return 1;
}

int UIManager::view_profile()
{
	string profile{};

	profile = user_manager.get_active_user_profile();
	if (0 == profile.size())
	{
		message("Unable to generate active user profile.");
		return 0;
	}
	message("\tProfile");
	message(profile);
	return 1;
}

int UIManager::logout()
{
	bool is_yes{};

	current_status = Not_logged;
	message("User logged off.");
	return 1;
	/*
		is_yes = get_y_n_confirmation();
		if ( true == is_yes) {
			current_status = Not_logged;
			message("User logged off.");
			return 1;
		}

		// No change in status
		return 0;
	*/
}

int UIManager::make_itinerary()
{
	current_status = Itinerary;
	return 1;
}

int UIManager::list_users()
{
	user_manager.list_users();
	return 1;
}

int UIManager::administration()
{
	user_manager.administration();

	return 1;
}

int UIManager::login()
{
	bool is_authenicated{};

	current_status = user_manager.login();

	return 1;
}

int UIManager::signup()
{
	User newuser{};

	user_manager.signup(newuser);

	return 1;
}

int UIManager::add_flight()
{
	itinerary_manager.book_flight(user_manager.get_active_user_id());
	return 1;
}

int UIManager::add_hotel()
{
	itinerary_manager.book_hotel(user_manager.get_active_user_id());
	return 1;
}

int UIManager::itinerary_ok()
{
	message("Itinerary updated.");
	current_status = Loggedin;
	return 1;
}

int UIManager::itinerary_cancel()
{
	message("itinerary_ok");
	current_status = Loggedin;
	return 1;
}
