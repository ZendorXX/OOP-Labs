cmake_minimum_required(VERSION 3.10)

project(lab_1) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(main main.cpp) 
add_executable(gtests test.cpp)

target_link_libraries(gtests ${GTEST_LIBRARIES}${CMAKE_THREAD_LIBS_INIT})
    
enable_testing()

add_test(gtests gtests)