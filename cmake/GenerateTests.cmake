# This function will automatically generate test executables from sources.
function(generate_tests test_prefix)
    file(
        GLOB
        test_srcs
        "*.cpp"
    )
    foreach(test_src ${test_srcs})
        get_filename_component(test "${test_src}" NAME_WE)
        list(APPEND tests ${test})
    endforeach()
    foreach(test ${tests})
        add_executable(
            ${test_prefix}-${test}
            ${test}.cpp
        )
        add_dependencies(
            ${test_prefix}-${test}
            ${test_prefix}
        )
        target_link_libraries(
            ${test_prefix}-${test}
            ${Boost_LIBRARIES}
            ${test_prefix}
        )
        set_target_properties(
            ${test_prefix}-${test}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DAPPS_BINARY_DIR}/tests
        )
        add_test(
            ${test_prefix}-${test}
            ${DAPPS_BINARY_DIR}/tests/${test_prefix}-${test}
        )
    endforeach()
endfunction(generate_tests)
