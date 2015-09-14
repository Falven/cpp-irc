include_directories(${cpp-dapps_SOURCE_DIR})

file(GLOB_RECURSE cpp-dapps_CONTSLIB_HEADERS "${cpp-dapps_SOURCE_DIR}/dapps/containers/*.hpp")

add_library(cpp-dapps-containerslib INTERFACE)

target_include_directories(cpp-dapps-containerslib INTERFACE)

target_sources(cpp-dapps-containerslib INTERFACE ${cpp-dapps_CONTSLIB_HEADERS} ${cpp-dapps_SOURCE_DIR}/dapps/containers/sort.hpp)

# target_link_libraries(cpp-dapps-containerslib ${Boost_System_LIBRARY})
# target_link_libraries(cpp-dapps-containerslib ${OPENSSL_LIBRARIES})

add_custom_target(cpp-dapps-containerslib-src SOURCES ${cpp-dapps_CONTSLIB_HEADERS})
