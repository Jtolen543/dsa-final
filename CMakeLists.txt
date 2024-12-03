cmake_minimum_required(VERSION 3.28)
project(dsa_final)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Define the executable
add_executable(dsa_final src/main.cpp
        lib/lib.cpp
        lib/lib.h
        test/test.cpp
        test/test.h)

# Link ws2_32 for HTTP functionality on Windows
target_link_libraries(dsa_final PRIVATE ws2_32)
