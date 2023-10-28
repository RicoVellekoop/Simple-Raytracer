cmake_minimum_required(VERSION 3.0)

project(simple-raytracer)

set(CMAKE_CXX_STANDARD 17)

# Add your source files here.
set(SOURCES
    src/main.cpp
    src/vec3d.cpp
    src/object.cpp
    src/sphere.cpp
    src/floor.cpp
    src/scene.cpp
    src/ray.cpp
    src/rayscanner.cpp
    src/image.cpp
    src/command_line_interface.cpp
    )

# Add your header files here.
set(HEADERS
    include/vec3d.h
    include/object.h
    include/sphere.h
    include/floor.h
    include/scene.h
    include/ray.h
    include/rayscanner.h
    include/image.h
    include/command_line_interface.h
    )

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