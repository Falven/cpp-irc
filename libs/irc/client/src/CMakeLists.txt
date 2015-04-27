include_directories(${cpp-dapps_SOURCE_DIR})

file(
    GLOB_RECURSE
    cpp-dapps_IRCLIB_CLIENT_HEADERS "${cpp-dapps_SOURCE_DIR}/dapps/irc/client/*.hpp"
)
file(
    GLOB
    cpp-dapps_IRCLIB_CLIENT_SRCS "*.cpp"
)

add_library(
    cpp-dapps-irclib-client
    ${cpp-dapps_IRCLIB_CLIENT_SRCS}
    ${cpp-dapps_IRCLIB_CLIENT_HEADERS}
)

set_target_properties(
    cpp-dapps-irclib-client
    PROPERTIES
    VERSION ${cpp-dapps_VERSION_STRING}
    PUBLIC_HEADER "${cpp-dapps_IRCLIB_CLIENT_HEADERS}"
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# target_link_libraries(dapps-irclib-client ${Boost_System_LIBRARY})
# target_link_libraries(dapps-irclib-client ${OPENSSL_LIBRARIES})

install(
    TARGETS cpp-dapps-irclib-client
    EXPORT cppdappsTargets
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    COMPONENT dev
)

source_group("Header Files" FILES ${cpp-dapps_IRCLIB_CLIENT_HEADERS})
