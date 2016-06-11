cmake_minimum_required (VERSION 2.6)
project (camera_device)
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

find_package( OpenCV REQUIRED )

add_executable (camera_device src/main.cpp)
target_link_libraries (camera_device tiobj ${OpenCV_LIBS})

install(TARGETS camera_device DESTINATION bin)
