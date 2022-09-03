#ifndef EXPEDIA_FLIGHTS_API_H_
#define EXPEDIA_FLIGHTS_API_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FlightInfo {
	friend ostream& operator<< (ostream& os, FlightInfo& obj);
public:
	FlightInfo();
	FlightInfo(string from, string to, double price, string date_time_from, string date_time_to);
	string from;
	string to;
	double price;
	string date_time_from;
	string date_time_to;
};



class CustomerInfo{

};
class FlightsAPI {
	
	public:
		FlightsAPI();
	  	vector<FlightInfo> GetFlights(string from, string to, string travel_date);
		bool ReserveFlight(const CustomerInfo &info, const FlightInfo& flight);
};



class AirCanadaCustomerInfo : public CustomerInfo {

};

class AirCanadaFlight : public FlightInfo{
public:
	double price;
	string date_time_from;
	string date_time_to;
};

class AirCanadaOnlineAPI : public FlightsAPI {
	public:
		friend ostream& operator<< (ostream& os, AirCanadaOnlineAPI& obj);
	public:
		AirCanadaOnlineAPI();
		vector<FlightInfo> GetFlights(string from, string to , string travel_date);
		string from;
		string to;
		double price;
		string date_time_from;
		string date_time_to;

		static bool ReserveFlight(const AirCanadaFlight& flight, const AirCanadaCustomerInfo &info) {
			return true;
		}
};

/*

class EmiratesFlight : public FlightInfo {
public:
	double cost;
	string datetime_from;
	string datetime_to;
};

class EmiratesCustomerInfo : public CustomerInfo {  

};

class EmiratesOnlineAPI : public FlightsAPI {
public:
	EmiratesOnlineAPI();
	void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
	}
	void SetPassengersInfo(int infants, int childern, int adults) {
	}
	vector<FlightInfo> GetAvailableFlights() const {
		vector<FlightInfo> flights;

		flights.push_back( { 300, "10-01-2022", "10-02-2022" });
		flights.push_back( { 320, "12-01-2022", "10-02-2022" });
		return flights;
	}

	static bool ReserveFlight(const EmiratesCustomerInfo &info, const EmiratesFlight& flight) {
		return false;
	}
};

*/

#endif /* EXPEDIA_FLIGHTS_API_H_ */
