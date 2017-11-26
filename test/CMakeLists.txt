file(GLOB TEST_SRC *.cpp)
add_executable(unit_tests ${TEST_SRC})

target_link_libraries(unit_tests turtle googletest)

if(NOT MSVC)
    target_link_libraries(unit_tests pthread)
endif()

add_test(unit unit_tests)

message(STATUS "Coverage start")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    if(CMAKE_COMPILER_IS_GNUCXX)
        include(CodeCoverage)
        set(COVERAGE_EXCLUDES '/usr/include/*'
                              '/usr/lib/*'
                              '/usr/local/lib/*'
                              '${PROJECT_SOURCE_DIR}/test/*'
                              '${PROJECT_SOURCE_DIR}/external/*'
        )
        setup_target_for_coverage(NAME "${PROJECT_NAME}_coverage"
                                  EXECUTABLE ctest
                                  DEPENDENCIES unit_tests
        )
        target_link_libraries(unit_tests gcov)
        target_compile_options(unit_tests PRIVATE "-fprofile-arcs" "-ftest-coverage")
        message(STATUS "Coverage set up.")
    endif()
endif()
