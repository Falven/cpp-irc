# This function will automatically generate test executables from sources.
# generate_tests(library linked-libraries...)
function(generate_lib_tests library)
    file(GLOB test_srcs "*.cpp")
    foreach(test_src ${test_srcs})
        get_filename_component(test_name "${test_src}" NAME_WE)
        set(exec_name ${library}-${test_name} CACHE INTERNAL "The test's executable name.")
        add_executable(${exec_name} ${test_src})
        add_dependencies(${exec_name} ${library})
        target_link_libraries(${exec_name} ${ARGV})
        add_test(NAME ${test_name} COMMAND ${exec_name})
    endforeach()
endfunction()
