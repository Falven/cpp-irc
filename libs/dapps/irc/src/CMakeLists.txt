include_directories(${cpp-irc_SOURCE_DIR})

file(GLOB cpp-irclib_IRC_HEADERS "${cpp-irc_SOURCE_DIR}/dapps/irc/*.hpp")
file(GLOB cpp-irclib_MESSAGES_HEADERS "${cpp-irc_SOURCE_DIR}/dapps/irc/messages/*.hpp")

install(FILES ${cpp-irclib_CLIENT_HEADERS} DESTINATION include)

add_library(cpp-irclib INTERFACE)
target_sources(cpp-irclib INTERFACE ${cpp-irclib_IRC_HEADERS} ${cpp-irclib_MESSAGES_HEADERS})
target_link_libraries(cpp-irclib INTERFACE ${Boost_LIBRARIES})

add_custom_target(cpp-irclib-src SOURCES ${cpp-irclib_IRC_HEADERS} ${cpp-irclib_MESSAGES_HEADERS})
source_group("dapps\\irc" FILES ${cpp-irclib_IRC_HEADERS})
source_group("dapps\\irc\\messages" FILES ${cpp-irclib_MESSAGES_HEADERS})