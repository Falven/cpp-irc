include_directories(${cpp-dapps_SOURCE_DIR})

set(
    TESTS
    nickname_abnf_test
)
foreach(test ${TESTS})
    add_executable(
        cpp-dapps-irclib-client-${test}
        ${test}.cpp
    )
    add_dependencies(
        cpp-dapps-irclib-client-${test}
        cpp-dapps-irclib-client
    )
    target_link_libraries(
        cpp-dapps-irclib-client-${test}
        # ${Boost_LIBRARIES}
        # ${CMAKE_THREAD_LIBS_INIT}
        cpp-dapps-irclib-client
    )
    # target_link_libraries(dapps-irclib-client-${test} ${OPENSSL_LIBRARIES})
    set_target_properties(
        cpp-dapps-irclib-client-${test}
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DAPPS_BINARY_DIR}/tests
    )
    add_test(
        cpp-dapps-irclib-client-${test}
        ${DAPPS_BINARY_DIR}/tests/cpp-dapps-irclib-client-${test}
    )
endforeach()
