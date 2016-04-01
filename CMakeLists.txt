cmake_minimum_required(VERSION 2.8.4)
project(Scripter)

set(CMAKE_CXX_FLAGS "-Wall -Wno-long-long -pedantic -std=c++11")

set(SOURCE_FILES    src/main.cpp
                    src/worder.h
                    src/worder.cpp)

add_executable(Scripter ${SOURCE_FILES})
