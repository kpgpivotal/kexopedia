
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
    flight = get_flight_bookings(flight);

    flight.set_passengers_count(pcount);
    add_flight_to_map(uid, flight);

    message("Booked flight");
    
    return 1;
}

int ItineraryManager::list_my_flight_itineraries(long uid){

     if (0 == flight_booking_map.size()) {
        message("No flight booking found.");

        return 0;
    }

    auto it = flight_booking_map.find(uid);  
    if ( it != flight_booking_map.end() ) {  
        vector<Flight_Booking> flight_vector = it->second ; 
        message("\tFlight Bookings");
        for (auto& it : flight_vector) {
            cout << it;
        }
    }
    return 1;
}

int ItineraryManager::list_my_hotel_itineraries(long uid){

     if (0 == hotel_booking_map.size()) {
        message("No hotel booking found.");

        return 0;
    }

    auto it = hotel_booking_map.find(uid);  
    if ( it != hotel_booking_map.end() ) {  
        vector<Hotel_Booking> hotel_vector = it->second ; 
        message("\tHotel Bookings");
        for (auto& it : hotel_vector) {
            cout << it;
        }
    }
    return 1;
}

int ItineraryManager::list_my_itineraries(long uid){

    list_my_flight_itineraries( uid);
    list_my_hotel_itineraries( uid);
    cout << endl;
    return 1;
}

int ItineraryManager::add_hotel_to_map(long uid, Hotel_Booking& hotel_booking){
vector<Hotel_Booking> hotel_vector{};

    auto it = hotel_booking_map.find(uid);  
    if ( it != hotel_booking_map.end() ) {  
        hotel_vector = it->second ; 
        hotel_vector.push_back(hotel_booking);
        hotel_booking_map.erase(uid);
        // insert updated node
        hotel_booking_map.insert(pair<long, vector<Hotel_Booking> >(uid, hotel_vector));
        return 1;
    }
    
    hotel_vector.push_back(hotel_booking);
    hotel_booking_map.insert(pair<long, vector<Hotel_Booking> >(uid, hotel_vector));

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
    string country{}, city{}, from_date{},to_date{},hotel_name{};
    int guests_count{}, hotel_num{};

    country = get_input_string("Enter country ");
    city = get_input_string("Enter city ");
    from_date = get_input_string("Enter from date");
    to_date = get_input_string("Enter to date");
    guests_count = get_input_int("Enter number of guests");
    // show hotel room list
    Hotel_Booking hotel{country,city, from_date, to_date, guests_count};
 
    hotel = get_hotel_bookings(hotel);

    if (-1 == hotel_num){
        return 0;
    }


    add_hotel_to_map(uid, hotel);

    message("Booked your hotel!");
    
    return 1;
}

Hotel_Booking  ItineraryManager::get_hotel_bookings(Hotel_Booking hotel){
    int hotel_number{}, hotel_choice{};
    string hotel_name{};
    vector<HotelRoom> api_hotel_vec{};
    map<int, string > hotel_selection_map;
    

    map<string, vector<HotelRoom>> hotel_map = hotel.get_hotel_info_api( );
    for (auto item = hotel_map.begin(); item != hotel_map.end(); item++) {
        cout << endl << item->first << endl;
        api_hotel_vec = item->second;
        for ( HotelRoom hotel_info : api_hotel_vec) {
            cout << ++hotel_number << " " << hotel_info << endl; 
            hotel_selection_map.insert(make_pair(hotel_number, item->first));
        }
        cout << endl;
    }

    cout << endl;

    hotel_choice = get_input_int("Choose your hotel by number (-1 to cancel)");
    if (-1 != hotel_choice){
        hotel_selection_map.find(hotel_choice);
 
        map<int, string>::iterator it = hotel_selection_map.find(hotel_choice);
        if (it != hotel_selection_map.end())
        {
            hotel_name = it->second;   
        }
    }
    
    hotel.set_hotel(hotel_name);

    return hotel;
}


Flight_Booking  ItineraryManager::get_flight_bookings(Flight_Booking flight){
    int flight_number{}, flight_choice{};
    string airlines{};
    vector<FlightInfo> api_flight_vec{};
    map<int, string > airlines_map;

    map<string, vector<FlightInfo>> flight_vec = flight.get_flight_info_api( );
    for (auto item = flight_vec.begin(); item != flight_vec.end(); item++) {
        cout << item->first << endl;
        api_flight_vec = item->second;
        for ( FlightInfo flight : api_flight_vec) {
            cout << ++flight_number << " " << flight << endl; 
            airlines_map.insert(make_pair(flight_number, item->first));
        }
        cout << endl;
    }

    cout << endl;

    flight_choice = get_input_int("Choose your flight by number (-1 to cancel)");
    if (-1 != flight_choice){
        airlines_map.find(flight_choice);
 
        map<int, string>::iterator it = airlines_map.find(flight_choice);
        if (it != airlines_map.end())
        {
            airlines = it->second;   
        }
    }
    
    flight.set_airlines(airlines);
    flight.set_flight(flight_choice);

    
    return flight;
}


