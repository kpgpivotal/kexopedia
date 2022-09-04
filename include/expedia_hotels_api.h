#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HotelRoom {
	friend ostream& operator<< (ostream& os, HotelRoom& obj);
public:
	string name;
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class HiltonRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};



class HiltonHotelAPI {
	public:
		vector<HotelRoom> SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms);

};

class MarriottFoundRoom {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
};

class MarriottHotelAPI {
public:
	vector<HotelRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, 
	int adults, int children);
	
};

#endif /* EXPEDIA_HOTELS_API_H_ */
