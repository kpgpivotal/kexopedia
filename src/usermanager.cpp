#include "usermanager.hpp"


UserManager::UserManager() {
    mUser_id_counter = 0;
    read_config_file();
    active_user_id = 0;
}

int UserManager::list_users(){
    message("\tList of users");
 	
	// Iterating over the map till map end.
    std::for_each(mUser_map.begin(), mUser_map.end(),
        [](std::pair<long, User> key_value)
        {
            cout << key_value.first << " " << key_value.second.get_name() << endl;
    
        });

    cout << endl;
    return 1;
}

int UserManager::read_config_file(){
    try {
        // deserialize
        // deserialize JSON from text file into vector of Records
        if (std::ifstream input{CONFIG_FILE_NAE}) {
            cereal::JSONInputArchive archive{input};
            archive(mUser_map); // deserialize records
            archive(mUser_id_counter);

            std::cout << "\nDeserialized records\n";
        }
    }
    catch(...){
        error_message("Unable to read configuration file");
    }

    return 1;
}

User_Status  UserManager::login(){
    long id{};
    User* pt_user{nullptr};
    string password{};

    if (0 == mUser_map.size()) {
        message("User list is empty.");
        return  Not_logged;
    }

    id = get_input_long("Please enter user id");
    pt_user = get_user_from_id(id);
    if (nullptr == pt_user) {
        message("\nInvalid user id. Please try again.");
        return  Not_logged;
    }
    
    active_user_id = id;
    password = get_input_string("Please enter password for user '" + pt_user->get_name() + "'");
    if ( true == pt_user->verify_password(password)) {
        
        if (pt_user->is_administrator()) {
            message("\nUser '"+ pt_user->get_name() + "' is  authenticated as an administrator!");
            return Admin;
        }
        else {
            message("\nUser '"+ pt_user->get_name() + "' is authenticated!");
            return Logged;
        }
        
    }
    message("\nPassword verification failed. Try again.");
    return  Not_logged;
}

string UserManager::get_active_user_profile(){
    string profile{};
    User* pt_user{nullptr};

    if (0 == active_user_id){
        return "No active user found.";
    }

    auto itr = mUser_map.find(active_user_id);
    if (itr != mUser_map.end()) {
        pt_user = &(itr->second);
          profile.append("Name    : ");
        profile.append( pt_user->get_name());
        profile.append("\nEmail   : ");
        profile.append( pt_user->get_email());
        profile.append("\nAddress : ");
        profile.append( pt_user->get_address());
        profile.append("\n");

    }

    return profile;
}

User* UserManager::get_user_from_id(long id){
    User* pt_user{nullptr};
    auto itr = mUser_map.find(id);
    if (itr != mUser_map.end()) {
        pt_user = &(itr->second);
    }
    return pt_user;
}


bool UserManager::administration(){
    message("\tList of users");
 	
	// Iterating over the map till map end.
    std::for_each(mUser_map.begin(), mUser_map.end(),
        [](std::pair<long, User> key_value)
        {
            cout << key_value.first << " " << key_value.second.get_name() << endl;
    
        });

    cout << endl;
    return true;
}
        
bool UserManager::signup(User &new_user) {
    string fname{}, lname{}, email{},password{},  address{};

	fname = get_input_string("Please enter first name ");
    lname = get_input_string("Please enter last name ");
	email = get_input_email("Please enter email ");
    password = get_input_string("Please enter password ");
    address = get_input_string("Please enter address ");
	
    ++mUser_id_counter;
    new_user.setMid(mUser_id_counter);
    new_user.set_firstName(fname);
    new_user.set_lastName(lname);
    new_user.set_email(email);
    new_user.set_password(password);
    new_user.set_address(address);

    mUser_map.insert(pair<long, User>(mUser_id_counter, new_user));
    message("New user '" + fname + "' is added.");

    return true;
}

UserManager::~UserManager() {
    try {
        if (std::ofstream output{CONFIG_FILE_NAE}) {
            cereal::JSONOutputArchive archive{output};
            archive(cereal::make_nvp("user_list", mUser_map),
            cereal::make_nvp("mUser_id_counter", mUser_id_counter)
            ); // serialize records 
        }
    }
    catch(...){
        error_message("Unable to write configuration file.");
    }

}