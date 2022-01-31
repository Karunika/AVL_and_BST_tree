#include <gtest/gtest.h>
#include "./AVLTreeUnitTest/AVLTreeUnitTest.cpp"
#include "./BinarySearchTreeUnitTest/BinarySearchTreeUnitTest.cpp"
#include "./Dictionary/Dictionary.hpp"

int main(int argc, char* argv[]){
    wrapper("dictionary_lexicographical.txt", "dictionary_occurance.txt");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};