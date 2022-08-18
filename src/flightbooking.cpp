
#include "flightbooking.hpp"

ostream & operator<< (ostream& os, Flight_Booking &obj){
    os << "Cities " << obj.from_city << " -  " << obj.to_city << " on " << obj.travel_date 
    << ". Passengers " << obj.passengers_count << endl;
    return os;
}
Flight_Booking::Flight_Booking(){

}

Flight_Booking::Flight_Booking(string city, string tcity, string date, int pcount, int the_flight)
    : from_city{city}, to_city{tcity}, travel_date{date}, passengers_count{pcount}, flight{the_flight} {

}

string Flight_Booking::get_from_city()
{
    return from_city;
}

void Flight_Booking::set_from_city(string from)
{
    from_city = from;
}

