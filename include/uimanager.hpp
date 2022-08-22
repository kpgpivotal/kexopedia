#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <iterator>
#include <map>
#include <vector>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/map.hpp>
#include <fmt/format.h>
#include <fstream>
#include "utils.hpp"
#include "usermanager.hpp"
#include "user.hpp"
#include "itinerarymanager.hpp"
#include "paymentprocessor.hpp"

const int EXIT_MENU_CHOICE = 0;
const string CONFIG_FILE_NAME = "kexopediaui.json";
class UIManager {
    public:
        UIManager();
        ~UIManager();
        int show_menu();

    private:
        UserManager user_manager;
        ItineraryManager itinerary_manager;
        Menu the_menu;
        User_Status current_status;
        vector<int> not_logged_vector;
        vector<int> logged_vector;
        vector<int> admin_vector;
        vector<int> itinerary_vector;
        map<User_Status, vector<int> > valid_choice_map;
        int process_user_choice( int choice);
        int login();
        int signup();
        int administration();
        int list_users();
        int make_itinerary();
        int list_booking();
        int logout();
        int read_config_file();
        bool is_valid_choice(int choice);
        int init_choice_map();
        int view_profile();
        int list_my_itineraries();
        int add_flight();
        int add_hotel();
        int itinerary_ok();
        int itinerary_cancel();


};


#endif 