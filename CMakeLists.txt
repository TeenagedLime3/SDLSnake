cmake_minimum_required(VERSION 3.29)
project(SDLSnake)

include_directories("C:/Users/acsel/Documents/Programming/C++/Libs/SDL2-2.30.6/include")

set(CMAKE_CXX_STANDARD 20)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
add_executable(SDLSnake main.cpp
        Snake.cpp
        Snake.h
        Direction.h
        Food.cpp
        Food.h
)
target_link_libraries(SDLSnake "C:/Users/acsel/Documents/Programming/C++/Libs/SDL2-2.30.6/lib/x64/SDL2.lib")