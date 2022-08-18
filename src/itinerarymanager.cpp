
#include "itinerarymanager.hpp"

ItineraryManager::~ItineraryManager(){
    try {
        if (std::ofstream output{"itinerary.json"}) {
            cereal::JSONOutputArchive archive{output};
            archive(cereal::make_nvp("flight_booking_map", flight_booking_map)); // serialize records 
        }
    }
    catch(...){
        error_message("Unable to write configuration file.");
    }
}

int ItineraryManager::book_flight(int uid){
    string fcity{},tocity{}, date{}; 
    int pcount{}, the_flight{};
    

    fcity = get_input_string("Enter from ");
    tocity = get_input_string("Enter to ");
    tocity = get_input_string("Enter travel date");
    pcount = get_input_int("Enter number of passengers");
    // show flights list
    the_flight = get_input_int("Choose your flight by number (-1 to cancel)");
    if (-1 == the_flight){
        return 0;
    }

    Flight_Booking flight{fcity,tocity, date, pcount, the_flight};
    
    add_flight_to_map(uid, flight);

    message("Booked flight");
    

    return 1;
}

int ItineraryManager::add_flight_to_map(long uid, Flight_Booking& flbook){
    vector<Flight_Booking> flight_vector{};
/*
    if (0 == flight_booking_map.size()) {
        message(">>>>>>flight_booking_map.size is zero ");
        flight_vector.push_back(flbook);
        flight_booking_map.insert(pair<long, vector<Flight_Booking>>(uid, flight_vector));
        return 1; 
    }
*/
    auto it = flight_booking_map.find(uid);  
    if ( it != flight_booking_map.end() ) {  
        flight_vector = it->second ; 
        flight_vector.push_back(flbook);
        flight_booking_map.erase(uid);
        // insert updated node
        flight_booking_map.insert(pair<long, vector<Flight_Booking>>(uid, flight_vector));
        return 1;
    }

    
    flight_vector.push_back(flbook);
    flight_booking_map.insert(pair<long, vector<Flight_Booking>>(uid, flight_vector));

    return 1;
}

int ItineraryManager::book_hotel(int uid){
    message("book_hotel");
    

    return 1;
}

string ItineraryManager::get_flight_bookings(int uid){
   message("get_flight_bookings");

    return "get_flight_bookings";
}


