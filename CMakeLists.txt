
cmake_minimum_required(VERSION 2.8)
project(application)

list(APPEND SRC_INC_DIR source)
list(APPEND SRC_FILES source/main.cpp)
list(APPEND SRC_FILES source/player.cpp)
list(APPEND SRC_FILES source/dealer.cpp)
list(APPEND SRC_FILES source/roulette.cpp)
list(APPEND SRC_FILES source/colorbet.cpp)
list(APPEND SRC_FILES source/outcome.cpp)
list(APPEND SRC_FILES source/bet.cpp)

include_directories(${SRC_INC_DIR})

set(CMAKE_CXX_FLAGS "-g")

# Main executable built
add_executable("roulette" ${SRC_FILES})
