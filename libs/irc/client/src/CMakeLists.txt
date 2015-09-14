include_directories(${cpp-dapps_SOURCE_DIR})

file(GLOB_RECURSE cpp-dapps_IRCLIB_CLIENT_HEADERS "${cpp-dapps_SOURCE_DIR}/dapps/irc/client/*.hpp")

add_library(cpp-dapps-irclib INTERFACE)

target_include_directories(cpp-dapps-irclib INTERFACE)

target_sources(cpp-dapps-irclib INTERFACE ${cpp-dapps_IRCLIB_CLIENT_HEADERS})

target_link_libraries(cpp-dapps-irclib INTERFACE ${Boost_System_LIBRARY} ${OPENSSL_LIBRARIES})

add_custom_target(cpp-dapps-irclib-src SOURCES ${cpp-dapps_IRCLIB_CLIENT_HEADERS})
