cmake_minimum_required(VERSION 3.9.2)
project(shaone)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(inc)

set(SOURCE_FILES inc/Word.h src/Word.cpp inc/SHA1_Hash.h src/SHA1_Hash.cpp inc/MessageSchedule.h src/MessageSchedule.cpp inc/MessageBlock.h src/MessageBlock.cpp)
add_executable(shaone main.cc ${SOURCE_FILES})

set(CATCH_INCLUDE_DIR test/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

enable_testing()
set(TEST_SOURCES test/tests-main.cc test/tests-word.cc)
add_executable(tests ${TEST_SOURCES} ${SOURCE_FILES})
target_link_libraries(tests Catch)
add_test(Tester tests)