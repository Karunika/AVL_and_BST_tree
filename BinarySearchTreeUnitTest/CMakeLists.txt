set(LIB BinarySearchTreeUnitTest)
add_library(${LIB} BinarySearchTreeUnitTest.cpp)

include(FetchContent)

FetchContent_Declare(
    googleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googleTest)

target_link_libraries(${LIB} PUBLIC gtest_main)
