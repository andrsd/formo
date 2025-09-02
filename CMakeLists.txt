cmake_minimum_required(VERSION 3.16)

project(formo VERSION 25.09.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)
include(CodeCoverage)

set(BuildValues "Release;Debug;RelWithDebInfo;MinSizeRel")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
endif()
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${BuildValues})
option(FORMO_BUILD_TESTS "Build tests" NO)

find_package(fmt 11 REQUIRED)
find_package(OpenCASCADE REQUIRED)
if (OpenCASCADE_FOUND)
    message(STATUS "Found OpenCASCADE: ${OpenCASCADE_LIBRARY_DIR} (version ${OpenCASCADE_VERSION})")
    if (OpenCASCADE_VERSION VERSION_LESS 7.9.0)
        message(FATAL_ERROR "OpenCASCADE version 7.9.0 or higher is required")
    endif()
endif()

# libformo

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)

add_library(libformo SHARED ${SRCS})
if(NOT MSVC)
    set_target_properties(libformo PROPERTIES OUTPUT_NAME formo)
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
    PUBLIC
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        fmt::fmt
)

configure_file(include/config.h.in include/formo/config.h)


# python
add_subdirectory(python)

# Tests

if(FORMO_BUILD_TESTS)
    set(FORMO_UNIT_TESTS_ROOT ${CMAKE_SOURCE_DIR}/test CACHE PATH "" FORCE)
    mark_as_advanced(FORCE FORMO_UNIT_TESTS_ROOT)

    enable_testing()
    add_subdirectory(test)
endif()

# install

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/formo-config.cmake.in formo-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/formo
    NO_SET_AND_CHECK_MACRO
)
write_basic_package_version_file(formo-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    TARGETS libformo
    EXPORT formoTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

install(
    EXPORT formoTargets
    FILE formo-targets.cmake
    NAMESPACE formo::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/formo
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/formo-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/formo-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/formo
)

#

add_subdirectory(docs)
