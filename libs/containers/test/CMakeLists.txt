include(${PROJECT_SOURCE_DIR}/cmake/GenerateLibTests.cmake)

include_directories(${cpp-dapps_SOURCE_DIR})

generate_lib_tests("cpp-dapps-containerslib" ${Boost_LIBRARIES})
