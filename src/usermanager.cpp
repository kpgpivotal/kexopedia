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
            archive(mUser_list); // deserialize records
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
    message("login");
    
    return 1;
}
        
int UserManager::signup() {
    string fname{}, lname{}, email{}, address{};

	fname = get_input_string("Please enter first name ");
    lname = get_input_string("Please enter last name ");
	email = get_input_email("Please enter email ");
    address = get_input_string("Please enter address ");
	//name = "Anil";
	//email = "anil@email.com";
	User new_user{mUser_id_counter++, fname, lname, email, address};
	mUser_list.push_back(new_user);
    message("New user added.");

    return 1;
}

UserManager::~UserManager() {
    try {
        if (std::ofstream output{CONFIG_FILE_NAE}) {
            cereal::JSONOutputArchive archive{output};
            archive(cereal::make_nvp("user_list", mUser_list),
            cereal::make_nvp("mUser_id_counter", mUser_id_counter)
            ); // serialize records 
        }
    }
    catch(...){
        error_message("Unable to write configuration file.");
    }

}