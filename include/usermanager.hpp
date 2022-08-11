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

const string CONFIG_FILE_NAE = "kexopedia.json";
class UserManager{
    // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, User& UserManager);

    public:
        UserManager();
        ~UserManager();
        bool login();
        int signup();

    private:
        map<long, User> mUser_map;
        long mUser_id_counter;
        int read_config_file();
        User* get_user_from_id(long id);

    // function template serialize is responsible for serializing and 
    // deserializing Record objects to/from the specified Archive
    template <typename Archive>
    void serialize(Archive& archive, UserManager& record) {
        archive( cereal::make_nvp("mUser_list", record.mUser_map),
                 cereal::make_nvp("mUser_id_counter", record.mUser_id_counter));
    }

};

#endif // defined