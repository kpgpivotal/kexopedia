
#include "flightbooking.hpp"


Flight_Booking::Flight_Booking(){

}

void Flight_Booking::set_passengers_count(int count){
    passengers_count = count;
}

void Flight_Booking::set_airlines(string the_airlines ){
    airlines = the_airlines;
}

map<string, vector<FlightInfo>> Flight_Booking::get_flight_info_api(){
    map<string, vector<FlightInfo>> flight_info_map{};
    FlightsAPI flights_api;
    AirCanadaOnlineAPI air_canda_flights_api;

    vector<FlightInfo>  emirates_flights = flights_api.GetFlights( from_city,  to_city,travel_date);
    if (emirates_flights.size() >0) {
        flight_info_map.insert(pair<string, vector<FlightInfo>>("Emirates", emirates_flights));
    }

    // Air Canada
    
    vector<FlightInfo>  air_canda_flights = air_canda_flights_api.GetFlights( from_city,  to_city,travel_date);
    if (air_canda_flights.size() >0) {
        flight_info_map.insert(pair<string, vector<FlightInfo>>("Air Canada", air_canda_flights));
    }

    
    return flight_info_map;
}

Flight_Booking::Flight_Booking(string city, string tcity, string date)
    : from_city{city}, to_city{tcity}, travel_date{date}, passengers_count{0} {

}

string Flight_Booking::get_from_city()
{
    return from_city;
}

void Flight_Booking::set_from_city(string from)
{
    from_city = from;
}

ostream & operator<< (ostream& os, Flight_Booking &obj){
    os << obj.from_city << " -  " << obj.to_city << " on " << obj.travel_date 
    << ". Passengers " << obj.passengers_count << endl;
    return os;
}