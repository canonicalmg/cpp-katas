file(GLOB_RECURSE SOURCES *.cpp)

add_executable(cpp_katas_test ${SOURCES})
add_test(NAME cpp_katas_test COMMAND cpp_katas_test)

target_link_libraries(cpp_katas_test PUBLIC cpp_katas_lib)
