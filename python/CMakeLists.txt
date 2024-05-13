find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_program(PYTHON "python" REQUIRED)

configure_file(setup.py.in setup.py)
install(CODE "execute_process(COMMAND ${PYTHON} -m pip install ${CMAKE_CURRENT_BINARY_DIR})")

add_subdirectory(src)

if (FORMO_BUILD_TESTS)
    find_program(PYTEST "pytest" REQUIRED)
    enable_testing()
    add_test(
        NAME python-tests
        COMMAND ${PYTEST} ${CMAKE_CURRENT_SOURCE_DIR}
    )
    set_tests_properties(python-tests PROPERTIES ENVIRONMENT "PYTHONPATH=${CMAKE_CURRENT_BINARY_DIR}/src:$ENV{PYTHONPATH}")
endif()
