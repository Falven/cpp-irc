include_directories(${cpp-irc_SOURCE_DIR})

file(GLOB_RECURSE cpp-irclib_CLIENT_HEADERS "${cpp-irc_SOURCE_DIR}/irc/*.hpp")
install(FILES ${cpp-irclib_CLIENT_HEADERS} DESTINATION include)

add_library(cpp-irclib INTERFACE)
target_sources(cpp-irclib INTERFACE ${cpp-irclib_CLIENT_HEADERS})
target_link_libraries(cpp-irclib INTERFACE ${Boost_LIBRARIES})

add_custom_target(cpp-irclib-src SOURCES ${cpp-irclib_CLIENT_HEADERS})