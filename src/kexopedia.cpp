#include "kexopedia.hpp"
#include "uimanager.hpp"


Kexopedia::Kexopedia(){

}
int Kexopedia::launch_app(){
    UIManager ui_manager{};


    cout << "Starting Kexopedia ..." << endl;
    intialize();
    ui_manager.show_menu();
    return 1;
}


int Kexopedia::intialize() {
    return 1;
}