#Root CMakeLists
cmake_minimum_required(VERSION 2.8)
project(Exercise)
if(POLICY CMP0056)
	cmake_policy(SET CMP0056 NEW)
endif(POLICY CMP0056)

add_custom_target(CheckCMakeDependencyChange ALL COMMAND ${CMAKE_COMMAND} ${CMAKE_CURRENT_SOURCE_DIR})

#Sets common build flags
if("\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES MSVC)
	if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
	if(NOT CMAKE_CXX_FLAGS MATCHES "/WX")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX")
	endif()
	if(CMAKE_CXX_FLAGS MATCHES "/sdl-?")
		string(REGEX REPLACE "/sdl-" "/sdl" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /sdl")
	endif()
	if(NOT CMAKE_CXX_FLAGS MATCHES "/analyze")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /analyze")
	endif()
	
elseif("\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES GNU OR "\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES Clang)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall -Wextra -pedantic -Werror ")
	
endif()

#Verifies that chosen build environment supports the necessary features
add_subdirectory(EnvTest EnvTest/bin EXCLUDE_FROM_ALL)

add_subdirectory(Exercise/src Exercise/bin)
