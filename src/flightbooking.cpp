
#include "flightbooking.hpp"


Flight::Flight(){
    cost =0.0;
}

void Flight::set_passengers_count(int count){
    passengers_count = count;
}

void Flight::set_airlines(string the_airlines ){
    airlines = the_airlines;
  
}

void Flight::set_cost(double pcost){
    cost = pcost;
}

double Flight::get_cost(){
    return cost;
}


map<string, vector<FlightInfo>> Flight::get_flight_info_api(){
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

Flight::Flight(string city, string tcity, string date)
    : from_city{city}, to_city{tcity}, travel_date{date}, passengers_count{0} {

}

string Flight::get_from_city()
{
    return from_city;
}

void Flight::set_from_city(string from)
{
    from_city = from;
}


void Flight::set_flight(int  flight){
    flight_number = flight;
}

ostream & operator<< (ostream& os, Flight &obj){
    os << obj.airlines << " - " << obj.from_city << " " << obj.to_city << " on " << obj.travel_date 
    << ",Passengers " << obj.passengers_count << " Cost $" << obj.cost << endl;
    return os;
}



FlightCost::FlightCost(string pname, FlightInfo pflight_info) : flight_name{pname}, flight_info{pflight_info} {

}

FlightCost::FlightCost()  {
    flight_name = "";
}
       

double FlightCost::get_cost(){
    
    return flight_info.price;
}

string FlightCost::get_flight_name() const{
    return flight_name;
}