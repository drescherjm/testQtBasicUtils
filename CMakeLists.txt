cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0074 NEW)

set(CMAKE_CXX_STANDARD 17)
include(CMake/SupportSwitchingQtVersionAsAFeature.cmake)

#########################################################################################

project(testQtBasicUtils)

option (BUILD_TESTING 				"Build Tests" ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (${PROJECT_NAME}_VERSION_MAJOR 3)
set (${PROJECT_NAME}_VERSION_MINOR 0)
set (${PROJECT_NAME}_VERSION_PATCH 0)
set (${PROJECT_NAME}_VERSION_PATCH_CLEAN ${${PROJECT_NAME}_VERSION_PATCH})
set (${PROJECT_NAME}_VERSION_STRING "${${PROJECT_NAME}_VERSION_MAJOR}.${${PROJECT_NAME}_VERSION_MINOR}.${${PROJECT_NAME}_VERSION_PATCH}")

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all libraries.")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for building all executables.")

#########################################################################################

include(GNUInstallDirs)
include(CMake/SupportQt56.cmake)
include(CMake/SupportQxt.cmake)

if (DEFINED VCPKG_TARGET_TRIPLET)
	find_package(cmake-modules REQUIRED)
	LIST(APPEND CMAKE_MODULE_PATH ${cmake-modules_MODULE_DIR})
	LIST(APPEND CMAKE_MODULE_PATH ${cmake-modules_SCRIPTS_DIR})
else(DEFINED VCPKG_TARGET_TRIPLET)
	LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake/External/Modules)
	LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake/External/Scripts)
endif(DEFINED VCPKG_TARGET_TRIPLET)

include(HelperMacros)
include(SetupProject)
include(NamingConvention)
include(GetCompilerVersion)
include(SupportQt)

#########################################################################################

include(CMake/SetupProjectDependencies.cmake)

#########################################################################################

if (BUILD_TESTING)
	enable_testing()
endif()

add_subdirectory(Utilities)
