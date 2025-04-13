cmake_minimum_required(VERSION 3.8)
project(M3OEP-cwalsh31-jkhoward)

set(CMAKE_CXX_STANDARD 14)

add_executable(M3OEP-cwalsh31 main.cpp movie.cpp Movie.h
        person.cpp
        writer.cpp
        director.cpp
        cast.cpp)
add_executable(Movie_Testing movie_testing.cpp movie.cpp Movie.h
        person.cpp
        writer.cpp
        director.cpp
        cast.cpp)
