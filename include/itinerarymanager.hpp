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

using namespace std;

class ItineraryManager {
    // declare serialize as a friend for direct access to private data
   template<typename Archive>
   friend void serialize(Archive& archive, ItineraryManager& record);

    public:
    ~ItineraryManager();
    int book_flight(int uid);
    int book_hotel(int uid);
    string get_flight_bookings(int uid);
    

    private:
    map<int, vector<Flight_Booking> > flight_booking_map;
    int add_flight_to_map(long uid, Flight_Booking& flbook);
   
};

template <typename Archive>
void serialize(Archive& archive, ItineraryManager& record) {
   archive( cereal::make_nvp("flight_booking_map", record.flight_booking_map));
}
#endif