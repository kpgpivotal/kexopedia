#ifndef INCLUDE_ITINERARY_MGR_HPP_
#define INCLUDE_ITINERARY_MGR_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/map.hpp>
#include <fmt/format.h>

#include "utils.hpp"
#include "user.hpp"
#include "flightbooking.hpp"
#include "hotelbooking.hpp"


using namespace std;

class ItineraryManager {
    // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, ItineraryManager& record);

    public:
    ~ItineraryManager();
    int book_flight(int uid);
    int book_hotel(int uid);
    Flight_Booking get_flight_bookings(Flight_Booking flight);
    Hotel_Booking  get_hotel_bookings(Hotel_Booking hotel);
    int list_my_itineraries(long uid);
    //int reserve_booking();
    int reserve_booking(long uid );
    int clear_bookings();
    bool is_bookings_tobe_paid();

    private:
    map<int, vector<Flight_Booking> > flight_booking_map;
    map<int, vector<Flight_Booking> > block_flight_map;
    int add_flight_to_map(long uid, Flight_Booking& flbook);
    map<int, vector<Hotel_Booking> > hotel_booking_map;
    map<int, vector<Hotel_Booking> > block_hotel_map;
    int add_hotel_to_map(long uid, Hotel_Booking& hotel_booking);
    int list_my_flight_itineraries(long uid);
    int list_my_hotel_itineraries(long uid);
    int block_hotel(long uid, Hotel_Booking& hotel_booking);
    int block_flight(long uid, Flight_Booking& flbook);
    
};

template <typename Archive>
void serialize(Archive& archive, ItineraryManager& record) {
   archive( cereal::make_nvp("flight_booking_map", record.flight_booking_map)),
   archive( cereal::make_nvp("hotel_booking_map", record.hotel_booking_map)),
   archive( cereal::make_nvp("block_hotel_map", record.block_hotel_map)),
   archive( cereal::make_nvp("block_flight_map", record.block_flight_map));
}


#endif