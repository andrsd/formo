if (${PROJECT_NAME} STREQUAL ${CMAKE_PROJECT_NAME})

# Code coverage

option(FORMO_CODE_COVERAGE "Builds targets with code coverage instrumentation" OFF)

if(FORMO_CODE_COVERAGE)

    set(COVERAGE_INFO ${PROJECT_BINARY_DIR}/coverage.info)
    mark_as_advanced(FORCE COVERAGE_INFO)
    set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES "${COVERAGE_INFO}")

    if(CMAKE_C_COMPILER_ID MATCHES "(Apple)?[Cc]lang" OR CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
        find_program(LLVM_COV_PATH NAMES llvm-cov)
        find_program(LLVM_PROFDATA_PATH NAMES llvm-profdata)
        mark_as_advanced(FORCE LLVM_COV_PATH LLVM_PROFDATA_PATH)

        set(CODE_COVERAGE_PROFRAWS
            ${CMAKE_BINARY_DIR}/test/formo-test.profraw
        )
        set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES "${CODE_COVERAGE_PROFRAWS}")

        set(EXCLUDE_REGEX
            --ignore-filename-regex=/contrib/
            --ignore-filename-regex=/include/fmt/*
            --ignore-filename-regex=/include/gtest/*
            --ignore-filename-regex=/include/gmock/*
            --ignore-filename-regex=test/*
        )

        set(CODE_COVERAGE_BINS
            --object=${PROJECT_BINARY_DIR}/test/formo-test
            --object=${PROJECT_BINARY_DIR}/libformo${CMAKE_SHARED_LIBRARY_SUFFIX}
        )

        set(MERGED_PROFDATA ${PROJECT_BINARY_DIR}/all-merged.profdata)

        add_custom_target(coverage DEPENDS ${COVERAGE_INFO})

        add_custom_command(
            OUTPUT
                ${COVERAGE_INFO}
            COMMAND
                ${LLVM_COV_PATH}
                export
                ${CODE_COVERAGE_BINS}
                -instr-profile=${MERGED_PROFDATA}
                -format="lcov"
                ${EXCLUDE_REGEX}
                > ${COVERAGE_INFO}
            DEPENDS
                ${MERGED_PROFDATA}
        )

        add_custom_command(
            OUTPUT
                ${MERGED_PROFDATA}
            COMMAND
                ${LLVM_PROFDATA_PATH}
                merge
                -sparse
                ${CODE_COVERAGE_PROFRAWS}
                -o ${MERGED_PROFDATA}
            DEPENDS
                ${CODE_COVERAGE_PROFRAWS}
        )

        add_custom_target(htmlcov
            DEPENDS ${PROJECT_BINARY_DIR}/htmlcov/index.html
            COMMENT "Open ${PROJECT_BINARY_DIR}/htmlcov/index.html in your browser to view the coverage report."
        )
        add_custom_command(
            OUTPUT
                ${PROJECT_BINARY_DIR}/htmlcov/index.html
            COMMAND
                ${LLVM_COV_PATH}
                show
                ${CODE_COVERAGE_BINS}
                -instr-profile=${MERGED_PROFDATA}
                -show-line-counts-or-regions
                -output-dir=${CMAKE_BINARY_DIR}/htmlcov
                -format="html"
                ${EXCLUDE_REGEX}
            DEPENDS
                ${COVERAGE_INFO}
        )

        function(target_code_coverage TARGET_NAME)
            target_compile_options(${TARGET_NAME} PRIVATE -fprofile-instr-generate -fcoverage-mapping)
            target_link_options(${TARGET_NAME} PRIVATE -fprofile-instr-generate -fcoverage-mapping)
        endfunction()

        function(add_test_with_coverage)
            # TODO: wrap add_test so it does this:
            #   add_test(${TEST_NAME} ARGS)
            #   set_tests_properties(${TEST_NAME} PROPERTIES ENVIRONMENT LLVM_PROFILE_FILE=${TEST_NAME}.profraw)
        endfunction()

    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
        set(GCOV "gcov" CACHE STRING "Path to gcov")

        find_program(GCOV_PATH NAMES ${GCOV})
        if (NOT GCOV_PATH)
            message(FATAL_ERROR "gcov not found!")
        endif()

        find_program(LCOV_PATH lcov)
        find_program(GENHTML_PATH genhtml)
        mark_as_advanced(FORCE
            GCOV
            GCOV_PATH
            LCOV_PATH
            GENHTML_PATH
        )

        set(EXCLUDE_REGEX
            --exclude=*/contrib/*
            --exclude=*/include/fmt/*
            --exclude=/usr/include/*
            --exclude=*/include/gtest/*
            --exclude=*/include/gmock/*
            --exclude=*/test/*
        )

        add_custom_target(coverage DEPENDS ${COVERAGE_INFO})

        add_custom_command(
            OUTPUT
                ${COVERAGE_INFO}
            COMMAND
                ${LCOV_PATH}
                --capture
                --gcov-tool ${GCOV_PATH}
                --directory ${PROJECT_BINARY_DIR}
                --output-file ${COVERAGE_INFO}
                --gcov-tool ${GCOV_PATH}
                ${EXCLUDE_REGEX}
        )

        add_custom_target(htmlcov
            DEPENDS ${PROJECT_BINARY_DIR}/htmlcov/index.html
            COMMENT "Open ${PROJECT_BINARY_DIR}/htmlcov/index.html in your browser to view the coverage report."
        )
        add_custom_command(
            OUTPUT
                ${PROJECT_BINARY_DIR}/htmlcov/index.html
            COMMAND
                ${GENHTML_PATH}
                --output-directory=${CMAKE_BINARY_DIR}/htmlcov
                ${COVERAGE_INFO}
            DEPENDS
                ${COVERAGE_INFO}
        )

        function(target_code_coverage TARGET_NAME)
            target_compile_options(${TARGET_NAME} PRIVATE -fprofile-arcs -ftest-coverage)
            target_link_options(${TARGET_NAME} PRIVATE -fprofile-arcs -ftest-coverage)
        endfunction()

        function(add_test_with_coverage)
        endfunction()

    else()
        message(STATUS, "Code coverage for your compiler (${CMAKE_C_COMPILER_ID}) is not supported.")
    endif()

else()

    function(target_code_coverage TARGET_NAME)
    endfunction()

    function(add_test_with_coverage)
    endfunction()

endif()

endif()
