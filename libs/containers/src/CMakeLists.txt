include_directories(${cpp-dapps_SOURCE_DIR})

file(
    GLOB_RECURSE
    cpp-dapps_CONTSLIB_HEADERS "${cpp-dapps_SOURCE_DIR}/dapps/containers/*.hpp"
)
file(
    GLOB
    cpp-dapps_CONTSLIB_SRCS "*.cpp"
)

add_library(
    cpp-dapps-containerslib
    ${cpp-dapps_CONTSLIB_SRCS}
    ${cpp-dapps_CONTSLIB_HEADERS}
)

set_target_properties(
    cpp-dapps-containerslib
    PROPERTIES
    VERSION ${cpp-dapps_VERSION_STRING}
    PUBLIC_HEADER "${cpp-dapps_CONTSLIB_HEADERS}"
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

# target_link_libraries(cpp-dapps-containerslib ${Boost_System_LIBRARY})
# target_link_libraries(cpp-dapps-containerslib ${OPENSSL_LIBRARIES})

install(
    TARGETS cpp-dapps-containerslib
    EXPORT cppdappsTargets
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
    COMPONENT dev
)

source_group("Header Files" FILES ${cpp-dapps_CONTSLIB_HEADERS})
