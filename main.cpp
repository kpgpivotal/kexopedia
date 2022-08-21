#include <iostream>
#include "kexopedia.hpp"
#include "itinerarymanager.hpp"
#include "expedia_hotels_api.h"

using namespace std;

void module_test();

int main(int argc, char** argv) {

    Kexopedia kapp{};

    //module_test();
    kapp.launch_app();
    
    return 0;
}


void module_test(){
    ItineraryManager itine_manager;

    itine_manager.book_hotel(7);
    itine_manager.list_my_itineraries(7);


}