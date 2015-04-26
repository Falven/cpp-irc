include_directories(${CPP-DAPPS_SOURCE_DIR})

set(
    TESTS
    sort_test
    insertion_test
)
foreach(test ${TESTS})
    add_executable(
        cpp-dapps-containerslib-${test}
        ${test}.cpp
    )
    # add_dependencies(
    #     cpp-dapps-containerslib-${test}
    #     cpp-dapps-containerslib
    # )
    # target_link_libraries(
    #     cpp-dapps-containerslib-${test}
    #     # ${Boost_LIBRARIES}
    #     # ${CMAKE_THREAD_LIBS_INIT}
    #     cpp-dapps-containerslib
    # )
    # target_link_libraries(dapps-irclib-client-${test} ${OPENSSL_LIBRARIES})
    set_target_properties(
        cpp-dapps-containerslib-${test}
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DAPPS_BINARY_DIR}/tests
    )
    add_test(
        cpp-dapps-containerslib-${test}
        ${DAPPS_BINARY_DIR}/tests/cpp-dapps-containerslib-${test}
    )
endforeach()
