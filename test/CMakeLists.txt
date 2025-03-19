set(LIB ${PROJECT_NAME}-lib)
set(TEST ${PROJECT_NAME}-test)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/6910c9d9165801d8827d628cb72eb7ea9dd538c5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${TEST} main.cpp dijkstra.cpp bfs.cpp)
target_link_libraries(${TEST} PRIVATE ${LIB} GTest::gtest_main)
target_include_directories(${TEST} PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(${TEST})

