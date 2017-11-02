cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDART 11)
include(cmake/HunterGate.cmake)

HunterGate(URL "https://github.com/TalkedDevotee/hunter/archive/v0.19.137.1.tar.gz" SHA1 "c73c56fb3af2b888652d1b3cab682cc08a55f972")
project(demo)

hunter_add_package(print)
find_package(print)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/sources/demo.cpp)
target_link_libraries(demo print)

install(TARGETS demo RUNTIME DESTINATION bin)
