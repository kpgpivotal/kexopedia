# set minimum cmake version
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# project name and language
project(kexopedia LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(${PROJECT_NAME}  main.cpp)

target_link_libraries(${PROJECT_NAME}
	PRIVATE  kexopedia_lib /home/kishore/lib/fmt-9.0.0/lib/libfmt.a  )
