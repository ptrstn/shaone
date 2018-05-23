cmake_minimum_required(VERSION 3.10)
project(shaone)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(inc)

set(SOURCE_FILES)
add_executable(shaone main.cc ${SOURCE_FILES})

set(CATCH_INCLUDE_DIR test/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

enable_testing()
set(TEST_SOURCES test/tests-main.cc test/tests-example.cc)
add_executable(tests ${TEST_SOURCES} ${SOURCE_FILES})
target_link_libraries(tests Catch)
add_test(Tester tests)