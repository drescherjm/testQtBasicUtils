cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 17)

include(CMake/SupportSwitchingQtVersionAsAFeature.cmake)

project(testQtBasicUtils)

find_package(QtBasicUtils REQUIRED)

