project(formo-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SRCS CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SRCS})
target_code_coverage(${PROJECT_NAME})
add_compile_definitions("FORMO_UNIT_TESTS_ROOT=\"${FORMO_UNIT_TESTS_ROOT}\"")

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/contrib
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
        libformo
        gtest_main
        gmock_main
)

add_test(
    NAME formo-test
    COMMAND ${PROJECT_NAME}
)
set_tests_properties(${PROJECT_NAME}
    PROPERTIES
        LABELS unit-tests
)

if(FORMO_CODE_COVERAGE)
    set_tests_properties(
        ${PROJECT_NAME}
        PROPERTIES
            ENVIRONMENT LLVM_PROFILE_FILE=${PROJECT_NAME}.profraw
    )
endif()
