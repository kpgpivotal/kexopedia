cmake_minimum_required(VERSION 3.16)

add_library (kexopedia_lib kexopedia.cpp )

target_include_directories(kexopedia_lib PUBLIC "../include" )

message("Library kexopedia_lib created")