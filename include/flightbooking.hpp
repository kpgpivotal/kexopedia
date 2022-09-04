#ifndef INCLUDE_FLIGHT_BOOKING_HPP_
#define INCLUDE_FLIGHT_BOOKING_HPP_

#include <iostream>
#include <string>
#include <map>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <fmt/format.h>
#include <fstream>
#include "expedia_flights_api.h"

using namespace std;

class Flight {
    template<typename Archive>
    friend void serialize(Archive& archive, Flight& record);
    friend ostream& operator<<(ostream& os, Flight &obj);
    public:
        Flight();
        Flight(string from_city, string to_city, string date);
        string get_from_city();
        void set_from_city(string from);
        map<string, vector<FlightInfo>> get_flight_info_api();
        void set_passengers_count(int passengers_count);
        void set_airlines(string airlines );
        void set_flight(int  flight);
        void set_cost(double cost);
        double get_cost();

        
    private:
        string from_city;
        string to_city;
        string travel_date;
        int passengers_count;
        int flight_number;
        string airlines;
        double cost;
};

template <typename Archive>
void serialize(Archive& archive, Flight& record) {
   archive( cereal::make_nvp("from_city", record.from_city),
        cereal::make_nvp("to_city", record.to_city),
      cereal::make_nvp("travel_date", record.travel_date),
      cereal::make_nvp("passengers_count", record.passengers_count),
      cereal::make_nvp("flight", record.flight_number),
      cereal::make_nvp("airlines", record.airlines),
      cereal::make_nvp("cost", record.cost));
};

class FlightCost {
    public:
        FlightCost();
        FlightCost(string flight_name, FlightInfo flight_info);
        double get_cost();
        string get_flight_name() const;

    private:
        string flight_name;
        FlightInfo flight_info;

};

#endif