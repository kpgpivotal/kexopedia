#include "expedia_flights_api.h"

FlightInfo::FlightInfo(string the_from, string the_to,double pprice, string date, string date_time_to)
	 : from{the_from}, to{the_to}, price{pprice}, date_time_from{date}, date_time_to{date_time_to}
	{

}

ostream& operator<< (ostream& os, FlightInfo& obj){
	cout << obj.date_time_from << "\t" << obj.from << "\t" << obj.to << "\t" <<  obj.date_time_to << "\t$" << obj.price;
	return os;
}

ostream& operator<< (ostream& os, AirCanadaOnlineAPI& obj) {
	cout << obj.date_time_from << "\t" << obj.from << "\t" << obj.to << "\t" <<  obj.date_time_to << "\t$" << obj.price;
	return os;
}

FlightsAPI::FlightsAPI(){

}


vector<FlightInfo> FlightsAPI::GetFlights(string from, string to , string travel_date){
	vector<FlightInfo> flights;

	flights.push_back(FlightInfo(from, to,  1000.0, travel_date, travel_date));
	flights.push_back(FlightInfo(from, to,1200.1,  travel_date, travel_date));
	flights.push_back(FlightInfo(from, to,1500.90,  travel_date, travel_date));

	return flights;
}

AirCanadaOnlineAPI::AirCanadaOnlineAPI(){}


vector<FlightInfo> AirCanadaOnlineAPI::GetFlights(string from, string to , string travel_date){
	vector<FlightInfo> flights;

	flights.push_back(FlightInfo(from, to,1250.1,  travel_date, travel_date));
	flights.push_back(FlightInfo(from, to,1300.90,  travel_date, travel_date));

	return flights;
}