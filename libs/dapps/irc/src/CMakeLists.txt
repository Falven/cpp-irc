include(${CMAKE_TOOLS_DIR}/GenerateSourceGroups.cmake)

include_directories(${cpp-irc_SOURCE_DIR})

file(GLOB_RECURSE cpp-irclib_HEADERS "${cpp-irc_SOURCE_DIR}/dapps/*.hpp")

install(FILES ${cpp-irclib_HEADERS} DESTINATION include)

add_library(cpp-irclib INTERFACE)
target_sources(cpp-irclib INTERFACE ${cpp-irclib_HEADERS})
target_link_libraries(cpp-irclib INTERFACE ${Boost_LIBRARIES})

add_custom_target(cpp-irclib-src SOURCES ${cpp-irclib_HEADERS})

GenerateSourceGroups(dapps)