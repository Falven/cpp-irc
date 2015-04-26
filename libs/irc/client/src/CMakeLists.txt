include_directories(${CPP-DAPPS_SOURCE_DIR})

file(
    GLOB_RECURSE
    CPP-DAPPS_IRCLIB_CLIENT_HEADERS "${CPP-DAPPS_SOURCE_DIR}/dapps/irc/client/*.hpp"
)
file(
    GLOB
    CPP-DAPPS_IRCLIB_CLIENT_SRCS "*.cpp"
)

add_library(
    cpp-dapps-irclib-client
    ${CPP-DAPPS_IRCLIB_CLIENT_SRCS}
    ${CPP-DAPPS_IRCLIB_CLIENT_HEADERS}
)

set_target_properties(
    cpp-dapps-irclib-client
    PROPERTIES
    VERSION ${CPP-DAPPS_VERSION_STRING}
    PUBLIC_HEADER "${CPP-DAPPS_IRCLIB_CLIENT_HEADERS}"
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

source_group("Header Files" FILES ${CPP-DAPPS_IRCLIB_CLIENT_HEADERS})
