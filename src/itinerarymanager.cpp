
#include "itinerarymanager.hpp"

ItineraryManager::~ItineraryManager(){
   
}

int ItineraryManager::book_flight(long uid){
    string fcity{},tocity{}, date{}; 
    int pcount{}, the_flight{};


    fcity = get_input_string("Enter from ");
    tocity = get_input_string("Enter to ");
    date = get_input_string("Enter travel date");
    pcount = get_input_int("Enter number of passengers");
    // show flights list
    Flight flight{fcity,tocity, date};
    flight = get_flight_bookings(flight);
    flight.set_passengers_count(pcount);
    block_flight(uid, flight);

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
        vector<Flight> flight_vector = it->second ; 
        message("\tFlight Bookings");
        for (auto& it : flight_vector) {
            cout << it;
        }
    }
    return 1;
}

int ItineraryManager::reserve_booking(long uid ){

    auto it = block_hotel_map.find(uid);  
    if ( it != block_hotel_map.end() ) { 
        vector<Hotel> hotel_vector = it->second ; 
        for (auto& it : hotel_vector) {
            add_hotel_to_map(uid,  it);
        }        
    }

    block_hotel_map.clear();

    auto itf = block_flight_map.find(uid);  
    if ( itf != block_flight_map.end() ) { 
        vector<Flight> flight_vector = itf->second ; 
        for (auto& itf : flight_vector) {
            add_flight_to_map(uid,  itf);
        }        
    }

    block_flight_map.clear();

    return 1;
    
}

int ItineraryManager::list_my_hotel_itineraries(long uid){

     if (0 == hotel_booking_map.size()) {
        message("No hotel booking found.");

        return 0;
    }

    auto it = hotel_booking_map.find(uid);  
    if ( it != hotel_booking_map.end() ) {  
        vector<Hotel> hotel_vector = it->second ; 
        message("\n\tHotel Bookings");
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

int ItineraryManager::block_hotel(long uid, Hotel& hotel_booking){
vector<Hotel> hotel_vector{};

    auto it = block_hotel_map.find(uid);  
    if ( it != block_hotel_map.end() ) {  
        hotel_vector = it->second ; 
        hotel_vector.push_back(hotel_booking);
        block_hotel_map.erase(uid);
        // insert updated node
        block_hotel_map.insert(pair<long, vector<Hotel> >(uid, hotel_vector));
        return 1;
    }
    
    hotel_vector.push_back(hotel_booking);
    block_hotel_map.insert(pair<long, vector<Hotel> >(uid, hotel_vector));

    return 1;
}



int ItineraryManager::add_hotel_to_map(long uid, Hotel& hotel_booking){
vector<Hotel> hotel_vector{};

    auto it = hotel_booking_map.find(uid);  
    if ( it != hotel_booking_map.end() ) {  
        hotel_vector = it->second ; 
        hotel_vector.push_back(hotel_booking);
        hotel_booking_map.erase(uid);
        // insert updated node
        hotel_booking_map.insert(pair<long, vector<Hotel> >(uid, hotel_vector));
        return 1;
    }
    
    hotel_vector.push_back(hotel_booking);
    hotel_booking_map.insert(pair<long, vector<Hotel> >(uid, hotel_vector));

    return 1;
}

int ItineraryManager::block_flight(long uid, Flight& flbook){
    vector<Flight> flight_vector{};

    auto it = block_flight_map.find(uid);  
    if ( it != block_flight_map.end() ) {  
        flight_vector = it->second ; 
        flight_vector.push_back(flbook);
        block_flight_map.erase(uid);
        // insert updated node
        block_flight_map.insert(pair<long, vector<Flight>>(uid, flight_vector));
        return 1;
    }

    
    flight_vector.push_back(flbook);
    block_flight_map.insert(pair<long, vector<Flight>>(uid, flight_vector));

    return 1;
}

int ItineraryManager::add_flight_to_map(long uid, Flight& flbook){
    vector<Flight> flight_vector{};

    auto it = flight_booking_map.find(uid);  
    if ( it != flight_booking_map.end() ) {  
        flight_vector = it->second ; 
        flight_vector.push_back(flbook);
        flight_booking_map.erase(uid);
        // insert updated node
        flight_booking_map.insert(pair<long, vector<Flight>>(uid, flight_vector));
        return 1;
    }

    
    flight_vector.push_back(flbook);
    flight_booking_map.insert(pair<long, vector<Flight>>(uid, flight_vector));

    return 1;
}

int ItineraryManager::book_hotel(long uid){
    string country{}, city{}, from_date{},to_date{},hotel_name{};
    int guests_count{}, hotel_num{};

    country = get_input_string("Enter country ");
    city = get_input_string("Enter city ");
    from_date = get_input_string("Enter from date");
    to_date = get_input_string("Enter to date");
    guests_count = get_input_int("Enter number of guests");
    // show hotel room list
    Hotel hotel{country,city, from_date, to_date, guests_count};
 
    hotel = get_hotel_bookings(hotel);

    if (-1 == hotel_num){
        return 0;
    }


    block_hotel(uid, hotel);

    message("Blocked the hotel. Reservation will be complete once you confirm and pay.");
    
    return 1;
}

Hotel  ItineraryManager::get_hotel_bookings(Hotel hotel){
    int hotel_number{}, hotel_choice{};
    string hotel_name{};
    vector<HotelRoom> api_hotel_vec{};
    map<int, HotelRoom > hotel_selection_map;
    HotelRoom selected_hotel{};
    

    map<string, vector<HotelRoom>> hotel_map = hotel.get_hotel_info_api( );
    for (auto item = hotel_map.begin(); item != hotel_map.end(); item++) {
        cout << endl << item->first << endl;
        api_hotel_vec = item->second;
        for ( HotelRoom hotel_info : api_hotel_vec) {
            cout << ++hotel_number << " " << hotel_info << endl; 
            hotel_selection_map.insert(make_pair(hotel_number, hotel_info));
        }
        cout << endl;
    }

    cout << endl;

    hotel_choice = get_input_int("Choose your hotel by number (-1 to cancel)");
    if (-1 != hotel_choice){
        hotel_selection_map.find(hotel_choice);
 
        map<int, HotelRoom>::iterator it = hotel_selection_map.find(hotel_choice);
        if (it != hotel_selection_map.end())
        {
            selected_hotel = it->second;   
        }
    }
    
    hotel_name = selected_hotel.name;
    hotel.set_hotel(hotel_name);
    hotel.set_cost(selected_hotel.price_per_night);

    return hotel;
}


Flight  ItineraryManager::get_flight_bookings(Flight flight){
    int flight_sequence_number{}, flight_choice{};
    string airlines{};
    vector<FlightInfo> api_flight_vec{};
    map<int, FlightCost > airlines_map;
    FlightCost flight_cost{};

    map<string, vector<FlightInfo>> flight_map = flight.get_flight_info_api( );
    for (auto item = flight_map.begin(); item != flight_map.end(); item++) {
        cout << item->first << endl;
        api_flight_vec = item->second;
        for ( FlightInfo flight : api_flight_vec) {
            cout << ++flight_sequence_number << " " << flight << endl; 
            airlines_map.insert(make_pair(flight_sequence_number, FlightCost(item->first, flight)));
        }
        cout << endl;
    }

    cout << endl;

    flight_choice = get_input_int("Choose your flight by number (-1 to cancel)");
    if (-1 != flight_choice){
            map<int, FlightCost>::iterator it = airlines_map.find(flight_choice);
        if (it != airlines_map.end())
        {
            flight_cost = it->second;   
        }
    }
    
    flight.set_airlines(flight_cost.get_flight_name());
    flight.set_flight(flight_choice);
    flight.set_cost(flight_cost.get_cost());

    return flight;
}

bool ItineraryManager::is_bookings_tobe_paid(){

    if ( (block_hotel_map.size() > 0)  || ( block_flight_map.size()> 0 ) ) {
        return true;
    }

    return false;
}

int  ItineraryManager::clear_bookings(){
    block_hotel_map.clear();
    block_flight_map.clear();

    return 1;
}

double ItineraryManager::get_itinerary_cost(long uid){
    double total_cost{};

    map<int, vector<Flight>>::iterator it = block_flight_map.find(uid);
    if (it != block_flight_map.end())
    {
        vector<Flight> flight_vec = it->second;  
        for ( Flight flight : flight_vec) {
            total_cost += flight.get_cost();
        }

    }

    cout << "Flight cost " << total_cost << endl;

    map<int, vector<Hotel>>::iterator ith = block_hotel_map.find(uid);
    if (ith != block_hotel_map.end())
    {
        vector<Hotel> hotel_vec = ith->second;  
        for ( Hotel hotel : hotel_vec) {
            total_cost += hotel.get_cost();
        }

    }

    cout << "Total cost " << total_cost << endl;
    return total_cost;
}