
#include "expedia_hotels_api.h"


vector<HotelRoom> HiltonHotelAPI::SearchRooms(string country, string city, string from_date, string to_date, int adults, int children, int needed_rooms) {
		vector<HotelRoom> rooms;

		rooms.push_back( { "Interior View", 6, 200.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "City View", 3, 300.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Deluxe View", 8, 500.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}

vector<HotelRoom> MarriottHotelAPI::FindRooms(string from_date, string to_date, string country, string city, int needed_rooms, int adults, int children) {
		vector<HotelRoom> rooms;

		rooms.push_back( { "City View", 8, 320.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Interior View", 8, 220.0, "29-01-2022", "10-02-2022" });
		rooms.push_back( { "Private View", 5, 600.0, "29-01-2022", "10-02-2022" });

		return rooms;
	}

ostream& operator<< (ostream& os, HotelRoom& obj){
	cout << obj.room_type << "\t" << obj.available << "\t$" << obj.price_per_night << "\t" <<  obj.date_from << "\t" << obj.date_to;
	return os;
}


