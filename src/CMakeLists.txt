file(GLOB_RECURSE SOURCES *.cpp)

add_library(cpp_katas_lib ${SOURCES})

target_sources(cpp_katas_lib PUBLIC ${SOURCES})
target_include_directories(cpp_katas_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")
