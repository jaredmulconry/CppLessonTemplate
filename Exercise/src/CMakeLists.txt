#Exercise CMakeLists
cmake_minimum_required(VERSION 2.8)
project(Exercise)

set(EXERCISE_SOURCE main.cpp Heap.cpp)
set(EXERCISE_HEADERS Heap.hpp)

include_directories(AFTER "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(Exercise ${EXERCISE_SOURCE} ${EXERCISE_HEADERS})
install(TARGETS Exercise
		RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
