cmake_minimum_required(VERSION 3.11.0)
project(Lab VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(AVLTreeLib)

add_subdirectory(BinarySearchTreeLib)

add_subdirectory(AVLTreeUnitTest)
target_link_libraries(${PROJECT_NAME} PUBLIC AVLTreeUnitTest)

add_subdirectory(BinarySearchTreeUnitTest)
target_link_libraries(${PROJECT_NAME} PUBLIC BinarySearchTreeUnitTest)

add_subdirectory(Dictionary)

SET(TXT_FILE "The Voyage of the Beagle by Charles Darwin")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${TXT_FILE}.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})