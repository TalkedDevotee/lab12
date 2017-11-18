cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDART 11)
include(cmake/HunterGate.cmake)

HunterGate(URL "https://github.com/TalkedDevotee/hunter/archive/v0.19.137.1.tar.gz" SHA1 "c73c56fb3af2b888652d1b3cab682cc08a55f972")
project(cget)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(cget ${CMAKE_CURRENT_SOURCE_DIR}/cget.cpp)
target_link_libraries(cget CURL::libcurl)

install(TARGETS cget RUNTIME DESTINATION bin)
