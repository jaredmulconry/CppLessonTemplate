#Root CMakeLists
cmake_minimum_required(VERSION 2.8)
project(Exercise)

#Sets common build flags
if("\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES MSVC)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "/W4 /WX /sdl /nologo /EHsc")
	#add_compile_options(/W4 /WX /sdl /nologo /EHsc)
	
elseif("\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES GNU OR "\"${CMAKE_CXX_COMPILER_ID}\"" MATCHES Clang)
	set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++1y -pthread -Wall -Wextra -Werror")
	#add_compile_options(-std=c++1y -pthread -Wall -Wextra -Werror)
	
endif()

#Verifies that chosen build environment supports the necessary features
add_subdirectory(EnvTest EnvTest/bin EXCLUDE_FROM_ALL)

add_subdirectory(Exercise/src Exercise/bin)
