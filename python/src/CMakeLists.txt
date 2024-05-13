find_package(pybind11 2.9 REQUIRED)

pybind11_add_module(formo formo.cpp)

target_include_directories(
        formo
    PRIVATE
        ${CMAKE_BINARY_DIR}/include
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(formo PUBLIC libformo)

install(
    TARGETS formo
    COMPONENT python
    LIBRARY DESTINATION "lib/python${Python3_VERSION_MAJOR}.${Python3_VERSION_MINOR}/site-packages/formo"
)
