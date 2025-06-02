find_package(pybind11 2.9 REQUIRED)

pybind11_add_module(formo formo.cpp)

target_include_directories(
    formo
    PRIVATE
        ${CMAKE_BINARY_DIR}/include
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(formo PUBLIC libformo)

set(PYTHON_SITE lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages)

install(
    TARGETS formo
    COMPONENT python
    LIBRARY DESTINATION "${PYTHON_SITE}/formo"
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/formo/__init__.py
    DESTINATION ${PYTHON_SITE}/formo
    COMPONENT python
)
