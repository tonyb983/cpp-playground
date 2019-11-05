# Works with 3.11 and tested through 3.15
cmake_minimum_required(VERSION 3.11...3.15)

# Project name and a few useful settings. Other commands can pick up the results
project(ModernCMakeExample
        VERSION 0.1
        DESCRIPTION "An example project with CMake"
        LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()


# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# Accumulator library
# This is header only, so could be replaced with git submodules or FetchContent
set(BOOST_ROOT Z:\\Boost\\boost_1_71_0)
find_package(Boost REQUIRED)
# Adds Boost::boost

# Formatting library
FetchContent_Declare(
        fmtlib
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        6.0.0
)
FetchContent_MakeAvailable(fmtlib)
# Adds fmt::fmt

# JSON Library
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG 53c3eef
)
FetchContent_MakeAvailable(nlohmann_json)
# Adds nlohmann::json

# SQLite ORM
#FetchContent_Declare(
#        sqlite_orm
#        GIT_REPOSITORY https://github.com/fnc12/sqlite_orm.git
#        GIT_TAG de4e2bd
#)
#FetchContent_MakeAvailable(sqlite_orm)
add_subdirectory(include/sqlite_orm)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
