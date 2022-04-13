cmake_minimum_required(VERSION 3.8)
project(cpp_katas)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) OR BUILD_TESTING)
    # https://github.com/joakimkarlsson/igloo/issues/21
    # To avoid errors during compilation of igloo
    set(CMAKE_CXX_FLAGS "-Wno-error=deprecated-declarations")

    include_directories("${PROJECT_SOURCE_DIR}/extern/igloo")
    add_subdirectory(test)
endif()
