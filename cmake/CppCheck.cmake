file(GLOB_RECURSE TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

add_custom_target(
        cppcheck
        COMMAND cppcheck
        --enable=all
        --std=c++11
        --verbose
        --quiet
        -I${PROJECT_SOURCE_DIR}/include
	${TEST_SRC_FILES}
)
