cmake_minimum_required(VERSION 3.16)

add_library (kexopedia_lib kexopedia.cpp utils.cpp uimanager.cpp usermanager.cpp user.cpp menu.cpp)

target_include_directories(kexopedia_lib PUBLIC "../include" "/home/kishore/lib/cereal-1.3.2/include"   "/home/kishore/lib/fmt-9.0.0/include")

message("Library Kexopedia_lib created")