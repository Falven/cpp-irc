cmake_minimum_required(VERSION 3.2)

project(cpp-dapps)

set(cpp-dapps_VERSION_MAJOR 0)
set(cpp-dapps_VERSION_MINOR 1)
set(cpp-dapps_VERSION_PATCH 0)
set(
    cpp-dapps_VERSION_STRING
    ${cpp-dapps_VERSION_MAJOR}.${cpp-dapps_VERSION_MINOR}.${cpp-dapps_VERSION_PATCH}
)

include(GNUInstallDirs)

set(
    CMAKE_BUILD_TYPE
    "Debug"
    CACHE STRING "Statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel.."
)
set(
    BUILD_SHARED_LIBS OFF
    CACHE BOOL "Whether to build shared or static dapps libraries."
)
set(
    Boost_DEBUG OFF
    CACHE BOOL "Show boost debugging information."
)
set(
    Boost_USE_STATIC_LIBS ON
    CACHE BOOL "Whether to use shared or static boost libraries when building dapps."
)
set(
    Boost_USE_STATIC_RUNTIME OFF
    CACHE BOOL "If enabled, searches for boost libraries linked against a static C++ standard library ('s' ABI tag). Defaults to OFF."
)
set(
    Boost_USE_MULTITHREADED ON
    CACHE BOOL "Whether to link to multi-threaded boost libraries when building dapps."
)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
endif()

find_package(
    Boost 1.58.0
    REQUIRED system timer chrono
)
if (NOT Boost_FOUND)
    if(BUILD_SHARED_LIBS)
        message("Check to make sure you have built shared boost libraries.")
    else()
        message("Check to make sure you have built static boost libraries.")
    endif(BUILD_SHARED_LIBS)
endif()
if(BUILD_SHARED_LIBS)
    if (WIN32)
        # disable autolinking in boost
        add_definitions(-DBOOST_ALL_NO_LIB)
        # force all boost libraries to dynamic link (we already disabled autolinking, so I don't know why we need this, but we do!)
        add_definitions(-DBOOST_ALL_DYN_LINK)
    endif(WIN32)
endif(BUILD_SHARED_LIBS)
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DBOOST_NETWORK_DEBUG)
endif()

find_package(OpenSSL)
if (NOT OPENSSL_FOUND)
    if(BUILD_SHARED_LIBS)
        message("Check to make sure you have built shared OpenSSL libraries.")
    else()
        message("Check to make sure you have built static OpenSSL libraries.")
    endif(BUILD_SHARED_LIBS)
endif()
add_definitions(-DBOOST_NETWORK_ENABLE_HTTPS)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
    add_definitions(-DBOOST_NETWORK_DEBUG)
    if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU OR ${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    endif(${CMAKE_CXX_COMPILER_ID} MATCHES GNU OR ${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
endif()

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})

enable_testing()

add_subdirectory(libs/irc/client/src)
add_subdirectory(libs/irc/client/test)
add_subdirectory(libs/irc/client/example)
add_subdirectory(libs/containers/src)
add_subdirectory(libs/containers/test)
add_subdirectory(libs/containers/example)

install(
    DIRECTORY ${cpp-dapps_SOURCE_DIR}/dapps
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

include(CMakePackageConfigHelpers)
set(
    INCLUDE_INSTALL_DIR include/
    CACHE INTERNAL "Include file installation directory."
)
set(
    LIB_INSTALL_DIR lib/
    CACHE INTERNAL "Lib file installation directory."
)
set(
    SYSCONFIG_INSTALL_DIR etc/
    CACHE INTERNAL "Config file installation directory."
)
configure_package_config_file(
    cppdappsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cppdappsConfig.cmake
    INSTALL_DESTINATION cmake
    PATH_VARS INCLUDE_INSTALL_DIR SYSCONFIG_INSTALL_DIR
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cppdappsConfigVersion.cmake
    VERSION ${cpp-dapps_VERSION_STRING}
    COMPATIBILITY SameMajorVersion
)
install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/cppdappsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cppdappsConfigVersion.cmake
    DESTINATION
    cmake
)
