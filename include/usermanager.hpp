#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include<vector>
#include <iterator>
#include <map>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/map.hpp>
#include <fmt/format.h>
#include <fstream>
#include "utils.hpp"
#include "user.hpp"
#include "menu.hpp"



const string CONFIG_FILE_NAE = "kexopedia.json";


class UserManager{
    public:
        UserManager();
        ~UserManager();
        User_Status  login();
        bool signup(User &new_user);
        bool administration();
        int list_users();

    private:
        Menu the_menu{};
        map<long, User> mUser_map;
        long mUser_id_counter;
        int read_config_file();
        User* get_user_from_id(long id);
      
};

#endif // defined