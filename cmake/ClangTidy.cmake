file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

find_program(CLANG_TIDY_PROG "${CLANG_TIDY}")

if (CLANG_TIDY_PROG)
    set(CLANG_TIDY_BIN ${CLANG_TIDY_PROG})
else ()
    set(CLANG_TIDY_BIN "/usr/bin/clang-tidy")
endif ()

add_custom_target(clang_tidy COMMAND
    ${CLANG_TIDY_BIN} -p . -header-filter=.* ${SRC_FILES})

add_custom_target(clang_tidy_fix COMMAND
    ${CLANG_TIDY_BIN} -p . -header-filter=.* -fix -fix-errors ${SRC_FILES} && make clang_format)
