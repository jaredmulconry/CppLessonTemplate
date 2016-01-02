#Exercise CMakeLists
cmake_minimum_required(VERSION 3.2)
project(Exercise)

add_executable(Exercise main.cpp)
install(TARGETS Exercise
		RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)