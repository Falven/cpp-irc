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

if(WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else()
    set(DEF_INSTALL_CMAKE_DIR lib/cmake/dapps)
endif()
set(
    INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR}
    CACHE PATH "Installation directory for CMake files"
)

# Make relative cmake install path absolute (needed later on)
if(NOT IS_ABSOLUTE "${INSTALL_CMAKE_DIR}")
    set(INSTALL_CMAKE_DIR "${CMAKE_INSTALL_PREFIX}/${INSTALL_CMAKE_DIR}")
endif()

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
# set(
#     Boost_USE_STATIC_RUNTIME ON
#     CACHE BOOL "Whether to link statically to the C++ standard library and compiler runtime support libraries."
# )
set(
    Boost_USE_MULTITHREADED ON
    CACHE BOOL "Whether to link to multi-threaded boost libraries when building dapps."
)

find_package(
    Boost 1.58.0
    REQUIRED system timer chrono
)

# if(WIN32)
#     add_definitions(-DBOOST_ALL_NO_LIB)
# endif()

if (NOT Boost_FOUND)
    if(BUILD_SHARED_LIBS)
        message("Check to make sure you have built shared boost libraries.")
    else()
        message("Check to make sure you have built static boost libraries.")
    endif(BUILD_SHARED_LIBS)
endif()

# find_package(OpenSSL)
# add_definitions(-DBOOST_NETWORK_ENABLE_HTTPS)
find_package(Threads)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
    # add_definitions(-DBOOST_NETWORK_DEBUG)
    if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU OR ${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
    endif(${CMAKE_CXX_COMPILER_ID} MATCHES GNU OR ${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
endif()

# set up include-directories
# include_directories(${OPENSSL_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

enable_testing()

# Add sub-directories
add_subdirectory(libs/containers/src)
add_subdirectory(libs/containers/test)
add_subdirectory(libs/containers/example)
add_subdirectory(libs/irc/client/test)
add_subdirectory(libs/irc/client/example)
add_subdirectory(libs/irc/client/src)

# Add project include dirs to installation.
install(DIRECTORY cpp-dapps DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Add all targets to the build-tree export set
export(
    TARGETS cpp-dapps-irclib-client
    FILE "${PROJECT_BINARY_DIR}/cppdappsTargets.cmake"
)

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE cppdapps)

# Create the dappsConfig.cmake and dappsConfigVersion files
file(
    RELATIVE_PATH REL_INCLUDE_DIR
    "${INSTALL_CMAKE_DIR}"
    "${CMAKE_INSTALL_FULL_INCLUDEDIR}"
)
# ... for the build tree
set(
    CONF_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}"
)
configure_file(
    cppdappsConfig.cmake.in
    "${PROJECT_BINARY_DIR}/cppdappsConfig.cmake" @ONLY
)
# ... for the install tree
set(
    CONF_INCLUDE_DIRS
    "\${DAPPS_CMAKE_DIR}/${REL_INCLUDE_DIR}"
)
configure_file(
    cppdappsConfig.cmake.in
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/cppdappsConfig.cmake" @ONLY
)
# ... for both
configure_file(
    cppdappsConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/cppdappsConfigVersion.cmake" @ONLY
)

# Install the dappsConfig.cmake and dappsConfigVersion.cmake
install(
    FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/cppdappsConfig.cmake"
    "${PROJECT_BINARY_DIR}/cppdappsConfigVersion.cmake"
    DESTINATION "${INSTALL_CMAKE_DIR}"
    COMPONENT dev
)

# Install the export set for use with the install-tree
install(
    EXPORT cppdappsTargets
    DESTINATION "${INSTALL_CMAKE_DIR}"
    COMPONENT dev
)
