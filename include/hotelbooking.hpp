#ifndef INCLUDE_Hotel_Booking_HPP_
#define INCLUDE_Hotel_Booking_HPP_

#include <iostream>
#include <string>
#include <map>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>

#include "expedia_hotels_api.h"


using namespace std;

class Hotel {
    template<typename Archive>
    friend void serialize(Archive& archive, Hotel& record);
    friend ostream& operator<<(ostream& os, Hotel &obj);
    public:
        Hotel();
        Hotel(string country, string city, string from_date,string to_date,
            int guests_count );
        map<string, vector<HotelRoom>> get_hotel_info_api();
        void set_guests_count(int guests_count);
        void set_hotel(string hotel );
        void set_cost(double cost);
        double get_cost();

        
    private:
        string country;
        string city;
        string from_date;
        string to_date;
        int guests_count;
        string hotel;
        double cost;
};

template <typename Archive>
void serialize(Archive& archive, Hotel& record) {
   archive( cereal::make_nvp("country", record.country),
        cereal::make_nvp("city", record.city),
      cereal::make_nvp("from_date", record.from_date),
      cereal::make_nvp("to_date", record.to_date),
      cereal::make_nvp("guests_count", record.guests_count),
      cereal::make_nvp("hotel", record.hotel),
      cereal::make_nvp("cost", record.cost));
}



#endif