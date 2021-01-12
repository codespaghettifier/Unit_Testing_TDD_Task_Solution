project(Tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(runTests ../UserActions.cpp tests.cpp)

target_link_libraries(runTests gtest gtest_main gmock gmock_main)
