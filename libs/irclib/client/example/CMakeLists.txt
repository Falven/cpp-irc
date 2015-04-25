# include_directories(${CPP-IRCLIB_SOURCE_DIR})
# if(OPENSSL_FOUND)
#   include_directories(${OPENSSL_INCLUDE_DIR})
# endif(OPENSSL_FOUND)

# add_executable(nickname_abnf_test nickname_abnf_test.cpp)
# add_dependencies(nickname_abnf_test cppirclib-client)

# set(
#   BOOST_CLIENT_LIBS
#   ${Boost_SYSTEM_LIBRARY}
#   ${Boost_PROGRAM_OPTIONS_LIBRARY}
#   ${Boost_THREAD_LIBRARY}
#   ${Boost_DATE_TIME_LIBRARY}
#   ${Boost_REGEX_LIBRARY}
#   ${Boost_FILESYSTEM_LIBRARY}
#   ${Boost_CHRONO_LIBRARY}
# )

# set(
#   BOOST_SERVER_LIBS
#   ${Boost_SYSTEM_LIBRARY}
#   ${Boost_PROGRAM_OPTIONS_LIBRARY}
#   ${Boost_THREAD_LIBRARY}
#   ${Boost_DATE_TIME_LIBRARY}
#   ${Boost_REGEX_LIBRARY}
#   ${Boost_FILESYSTEM_LIBRARY}
#   ${Boost_CHRONO_LIBRARY}
# )

# target_link_libraries(
#   nickname_abnf_test
#   ${BOOST_CLIENT_LIBS}
#   ${CMAKE_THREAD_LIBS_INIT}
#   cppirclib-client
# )

# if(OPENSSL_FOUND)
#   target_link_libraries(nickname_abnf_test ${OPENSSL_LIBRARIES})
# endif(OPENSSL_FOUND)

# if(${CMAKE_CXX_COMPILER_ID} MATCHES GNU AND ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
#   target_link_libraries(nickname_abnf_test ws2_32)
# endif()

# if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#   target_link_libraries(nickname_abnf_test rt)
# endif()

# set_target_properties(nickname_abnf_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CPP-IRCLIB_BINARY_DIR}/example)
