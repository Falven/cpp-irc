include(${CMAKE_TOOLS_DIR}/GenerateLibTests.cmake)

include_directories(${cpp-irc_SOURCE_DIR})

generate_lib_tests("cpp-irclib" ${Boost_LIBRARIES})