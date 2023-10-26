cmake_minimum_required(VERSION 3.0)

project(simple-raytracer)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(simple-raytracer ${SOURCES})

set_target_properties( simple-raytracer
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add additional include directories if needed
target_include_directories(simple-raytracer PRIVATE include)


# If you have tests, define them here.
# add_test(TestName command_to_run_test)

# This section is not necessary if you're not using CPack for packaging.
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)