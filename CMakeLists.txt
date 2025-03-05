cmake_minimum_required(VERSION 3.10)

# Project Name
project("ParticleDynamics")

# Set MinGW path
set(CMAKE_CXX_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/gcc.exe")

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Google Test
set(GTEST_INCLUDE_DIR "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/include")
set(GTEST_LIBRARY "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/libgtest.a")
set(GTEST_MAIN_LIBRARY "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/libgtest_main.a")
enable_testing()

# get MyMath library
# set(MyMath_DIR "C:/Users/eloyd/OneDrive/Documenten/gitlabDirectories/cpp/vectorclass/build")
find_package(MyMath 1.0.0 REQUIRED)
set(nlohmann_json_DIR "C:/Users/eloyd/OneDrive/Documenten/gitlabDirectories/cpp/json/build")
find_package(nlohmann_json 3.11.3 REQUIRED)
# set(httplib_DIR "C:/Users/eloyd/OneDrive/Documenten/gitlabDirectories/cpp/cpp-httplib/build")
set(HTTPLIB_DIR "C:/Program Files (x86)/httplib/include")
# set(HTTPLIB_INCLUDE_DIR "C:/Program Files (x86)/httplib/include")
find_package(httplib)


# Source Files
include_directories(include
                    src)
                    
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

find_package(GTest REQUIRED)

# # Add Google Test executable
add_executable(tests ${TEST_SOURCES}
                server "server.cpp")

target_link_libraries(tests
                    GTest::gtest_main 
                    MyMath::MyMath
                    nlohmann_json::nlohmann_json
                    httplib::httplib)

include(GoogleTest)
gtest_discover_tests(tests)
