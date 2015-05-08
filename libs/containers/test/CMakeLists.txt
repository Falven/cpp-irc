include(${PROJECT_SOURCE_DIR}/cmake/GenerateTests.cmake)

include_directories(${cpp-dapps_SOURCE_DIR})

generate_tests("cpp-dapps-containerslib")
