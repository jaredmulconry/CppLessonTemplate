#Exercise CMakeLists
cmake_minimum_required(VERSION 2.8)
project(Exercise)

add_executable(Exercise main.cpp)
install(TARGETS Exercise
		RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
