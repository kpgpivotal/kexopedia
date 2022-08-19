
#include "itinerarymanager.hpp"

ItineraryManager::~ItineraryManager(){
   
}

int ItineraryManager::book_flight(int uid){
    string fcity{},tocity{}, date{}; 
    int pcount{}, the_flight{};


    fcity = get_input_string("Enter from ");
    tocity = get_input_string("Enter to ");
    date = get_input_string("Enter travel date");
    pcount = get_input_int("Enter number of passengers");
    // show flights list
    Flight_Booking flight{fcity,tocity, date};
    get_flight_bookings(flight);

    the_flight = get_input_int("Choose your flight by number (-1 to cancel)");
    if (-1 == the_flight){
        return 0;
    }

    flight.set_passengers_count(pcount);
    add_flight_to_map(uid, flight);

    message("Booked flight");
    
    return 1;
}

int ItineraryManager::list_my_itineraries(long uid){

    if (0 == flight_booking_map.size()) {
        message("No itineraries found.");

        return 0;
    }

    auto it = flight_booking_map.find(uid);  
    if ( it != flight_booking_map.end() ) {  
        vector<Flight_Booking> flight_vector = it->second ; 
        message("\tItineraries");
        for (auto& it : flight_vector) {
            cout << it;
        }
    }

    cout << endl;

    return 1;
}

int ItineraryManager::add_flight_to_map(long uid, Flight_Booking& flbook){
    vector<Flight_Booking> flight_vector{};

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

void  ItineraryManager::get_flight_bookings(Flight_Booking flight){
    int flight_number{};
    vector<FlightInfo> api_flight_vec{};

    map<string, vector<FlightInfo>> flight_vec = flight.get_flight_info_api( );
    for (auto item = flight_vec.begin(); item != flight_vec.end(); item++) {
        cout << item->first << endl;
        api_flight_vec = item->second;
        for ( FlightInfo flight : api_flight_vec) {
            cout << ++flight_number << " " << flight << endl; 
        }
        cout << endl;
    }

    cout << endl;
}


