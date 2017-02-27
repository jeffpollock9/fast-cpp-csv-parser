add_definitions(-DBOOST_TEST_DYN_LINK)

set(TESTS
    test_csv_reader
)

foreach(test ${TESTS})
    add_executable(${test} ${test}.cpp)
    target_link_libraries(${test} ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
    add_test(${test} ${test})
endforeach(test)

file(COPY data/ DESTINATION ${PROJECT_BINARY_DIR}/tests/data)
