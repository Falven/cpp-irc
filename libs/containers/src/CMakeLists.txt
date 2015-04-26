include_directories(${CPP-DAPPS_SOURCE_DIR})

file(
    GLOB_RECURSE
    CPP-DAPPS_CONTSLIB_HEADERS "${CPP-DAPPS_SOURCE_DIR}/dapps/containers/*.hpp"
)
file(
    GLOB
    CPP-DAPPS_CONTSLIB_SRCS "*.cpp"
)

add_library(
    cpp-dapps-containerslib
    ${CPP-DAPPS_CONTSLIB_SRCS}
    ${CPP-DAPPS_CONTSLIB_HEADERS}
)

set_target_properties(
    cpp-dapps-containerslib
    PROPERTIES
    VERSION ${CPP-DAPPS_VERSION_STRING}
    PUBLIC_HEADER "${CPP-DAPPS_CONTSLIB_HEADERS}"
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# target_link_libraries(dapps-irclib-client ${Boost_System_LIBRARY})
# target_link_libraries(dapps-irclib-client ${OPENSSL_LIBRARIES})

install(
    TARGETS cpp-dapps-containerslib
    EXPORT cppdappsTargets
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    COMPONENT dev
)

source_group("Header Files" FILES ${CPP-DAPPS_CONTSLIB_HEADERS})
