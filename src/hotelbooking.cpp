#include "hotelbooking.hpp"

ostream& operator<<(ostream& os, Hotel_Booking &obj) {
    os << obj.hotel << "\t" << obj.city  << "\t" << obj.from_date << "\t" << obj.to_date << endl;

    return os;
}

Hotel_Booking::Hotel_Booking(){}

Hotel_Booking::Hotel_Booking(string pcountry, string pcity, string pfrom_date,string pto_date,
            int pguests_count ): country(pcountry), city{pcity}, from_date{pfrom_date}, 
            to_date{pto_date}, guests_count{pguests_count} 
{

}

map<string, vector<HotelRoom>> Hotel_Booking::get_hotel_info_api(){
    map<string, vector<HotelRoom>> hotel_info_map{};
    HiltonHotelAPI hilton_api;
    MarriottHotelAPI marriot_api;

    vector<HotelRoom> hilton_rooms,marriot_rooms;
    hilton_rooms = hilton_api.SearchRooms("UAE", "Dubai", "31/09/2022", "01/10/2022", 2,1,1);
    if (hilton_rooms.size() >0) {
        hotel_info_map.insert(pair<string, vector<HotelRoom>>("Hilton", hilton_rooms));
    }

    // Marriot
    marriot_rooms = marriot_api.FindRooms("UAE", "Dubai", "31/09/2022", "01/10/2022", 2,1,1);
    if (marriot_rooms.size() >0) {
        hotel_info_map.insert(pair<string, vector<HotelRoom>>("Marriot", marriot_rooms));
    }

    
    return hotel_info_map;
}

void Hotel_Booking::set_guests_count(int guests_count){
    guests_count = guests_count;
}

void Hotel_Booking::set_hotel(string photel ){
    hotel = photel;
}