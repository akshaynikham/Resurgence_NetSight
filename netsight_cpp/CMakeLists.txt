cmake_minimum_required(VERSION 3.15)

project(Netsight_cpp)

add_executable(netsight src/main src/greeting.cpp src/ehterTypeDefinition.cpp src/parseEnumStatus.cpp src/parseEthernet.cpp)

target_include_directories(netsight PRIVATE include)