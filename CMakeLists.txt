cmake_minimum_required(VERSION 3.16)

project(formo VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(FetchContent)
include(CodeCoverage)

set(BuildValues "Release;Debug;RelWithDebInfo;MinSizeRel")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${BuildValues})
option(FORMO_BUILD_TESTS "Build tests" NO)

find_package(fmt 9.0 REQUIRED)
find_package(OpenCASCADE REQUIRED)
if(OpenCASCADE_FOUND)
    message(STATUS "Found OpenCASCADE: ${OpenCASCADE_LIBRARY_DIR} (version ${OpenCASCADE_VERSION})")
    if(OpenCASCADE_VERSION VERSION_LESS 7.7.0)
    endif()
endif()

# libformo

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)

add_library(libformo SHARED ${SRCS})
if(NOT MSVC)
    set_target_properties(${NAME} PROPERTIES OUTPUT_NAME formo)
endif()

target_code_coverage(libformo)

set_target_properties(
    libformo
    PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_include_directories(
    libformo
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${OpenCASCADE_INCLUDE_DIR}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(
    libformo
    PRIVATE
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        fmt::fmt
)

configure_file(include/config.h.in include/formo/config.h)


# python
add_subdirectory(python)

if(FORMO_BUILD_TESTS)
    fetchcontent_declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    mark_as_advanced(FORCE BUILD_GMOCK INSTALL_GTEST
        FETCHCONTENT_SOURCE_DIR_GOOGLETEST FETCHCONTENT_UPDATES_DISCONNECTED_GOOGLETEST
    )

    fetchcontent_makeavailable(googletest)
    mark_as_advanced(FORCE
        FETCHCONTENT_BASE_DIR FETCHCONTENT_QUIET
        FETCHCONTENT_FULLY_DISCONNECTED FETCHCONTENT_UPDATES_DISCONNECTED
    )
endif()

# Tests

if(FORMO_BUILD_TESTS)
    set(FORMO_UNIT_TESTS_ROOT ${CMAKE_SOURCE_DIR}/test CACHE PATH "" FORCE)
    mark_as_advanced(FORCE FORMO_UNIT_TESTS_ROOT)

    enable_testing()
    add_subdirectory(test)
endif()
