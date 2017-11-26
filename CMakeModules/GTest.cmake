set(GOOGLETEST_ROOT external/googletest/googletest CACHE STRING "Google Test source root")
set(GOOGLEMOCK_ROOT external/googletest/googlemock CACHE STRING "Google Mock source root")

message(STATUS "GOOGLETEST_ROOT set to ${GOOGLETEST_ROOT}")
message(STATUS "GOOGLEMOCK_ROOT set to ${GOOGLEMOCK_ROOT}")

# gtest includes
include_directories(
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/include
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
)

# gtest sources
set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/src/gmock-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLEMOCK_ROOT}/src/gmock_main.cc
)

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

add_library(googletest ${GOOGLETEST_SOURCES})
