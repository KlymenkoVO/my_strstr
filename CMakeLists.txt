cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT_NAME "Turtle")
project(${PROJECT_NAME})

enable_language(C CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

if(CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
    endif()

    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")

    SET(ENABLE_CXX11 "-std=c++11")

    EXECUTE_PROCESS(COMMAND "${CMAKE_CXX_COMPILER} -dumpversion" OUTPUT_VARIABLE GCC_VERSION)
    if (GCC_VERSION VERSION_LESS 4.7)
        SET(ENABLE_CXX11 "-std=c++0x")
    endif()
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ENABLE_CXX11} -fprofile-arcs -ftest-coverage")
elseif(MSVC)
    set(CMAKE_CXX_FLAGS "/W4 /Wp64")
    set(CMAKE_CXX_FLAGS_DEBUG "/DEBUG /Od")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
endif()

# Generic output
message(STATUS "Host processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Current build type flags: ${CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}}")

include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(
    turtle
    src/Turtle.cpp
    src/Painter.cpp
)
set_property(TARGET turtle PROPERTY CXX_STANDARD 11)
set_property(TARGET turtle PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(turtle)

# Testing
if(BUILD_TESTING) 
  include(CTest)
  include(GTest)
  enable_testing()
  
  add_subdirectory(test)
endif(BUILD_TESTING)
