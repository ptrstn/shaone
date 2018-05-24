cmake_minimum_required(VERSION 3.9.2)
project(shaone)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(inc)

set(INCLUDE_FILES inc/Word.h   inc/Stage.h   inc/MerkleDamgardConstruction.h   inc/SHA1.h   inc/SHA1_Hash.h   inc/MessageSchedule.h   inc/MessageBlock.h)
set(SOURCE_FILES  ${INCLUDE_FILES} src/Word.cpp src/MerkleDamgardConstruction.cpp src/SHA1.cpp src/SHA1_Hash.cpp src/MessageSchedule.cpp src/MessageBlock.cpp )
add_executable(shaone main.cc ${SOURCE_FILES})

set(CATCH_INCLUDE_DIR test/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

enable_testing()
set(TEST_SOURCES test/tests-main.cc test/tests-word.cc test/tests-stage.cc test/tests-messageblock.cc test/tests-messageschedule.cc)
add_executable(tests ${TEST_SOURCES} ${SOURCE_FILES})
target_link_libraries(tests Catch)
add_test(Tester tests)