#include "usermanager.hpp"


UserManager::UserManager() {
    mUser_id_counter = 0;
    read_config_file();
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

bool UserManager::login(){
    long id{};
    User* pt_user{};
    string password{};

    if (0 == mUser_map.size()) {
        message("User list is empty.");
        return false;
    }

    id = get_input_long("Please enter user id");
    pt_user = get_user_from_id(id);
    if (nullptr == pt_user) {
        message("\nInvalid user id. Please try again.");
        return false;
    }
    
    password = get_input_string("Please enter password for user '" + pt_user->get_name() + "'");
    if ( true == pt_user->verify_password(password)) {
        
        if (pt_user->is_administrator()) {
            message("\nUser '"+ pt_user->get_name() + "' is  authenticated as an administrator!");
        }
        else {
             message("\nUser '"+ pt_user->get_name() + "' is authenticated!");
        }
        return true;
    }
    message("\nPassword verification failed. Try again.");
    return false;
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
    
	// iterator pointing to start of map
	//auto it = mUser_map.begin();
	
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
    new_user.setMFirstName(fname);
    new_user.setMLastName(lname);
    new_user.setMEmail(email);
    new_user.setMPassword(password);
    new_user.setMAddress(address);

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