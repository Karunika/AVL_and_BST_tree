#include <gtest/gtest.h>
#include <string>
#include "../BinarySearchTreeLib/BinarySearchTree.hpp"

using namespace std;

class BSTTest : public ::testing::Test {
    protected:
		BinarySearchTree<int, int>* tree;

        void SetUp() override {
            tree = new BinarySearchTree<int, int>();
        }
};

TEST_F(BSTTest, ConstructEmpty) {
	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertToEmpty) {
	tree->insert(10, 100);
	string expected = "([10,100],,)";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe2LevelOnTheLeftThereIsNoRight) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	string expected = "([10,100],([5,50],,),)";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe2LevelOnTheRightThereIsNoLeft) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	string expected = "([10,100],,([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe2LevelOnTheLeftThereIsRight) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	tree->insert(5, 50);
	string expected = "([10,100],([5,50],,),([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe2LevelOnTheRightThereIsLeft) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	string expected = "([10,100],([5,50],,),([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelLeftLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	string expected = "([50,500],([20,200],([10,100],,),),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelLeftLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	tree->insert(10, 100);
	string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelLeftRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	string expected = "([50,500],([20,200],,([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelLeftRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->insert(30, 300);
	string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelRightLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelRightLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	tree->insert(70, 700);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelRightRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	string expected = "([50,500],([20,200],,),([80,800],,([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertOnThe3LevelRightRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, insertExisting) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	tree->insert(50, 501);
	tree->insert(20, 201);
	tree->insert(80, 801);
	tree->insert(70, 701);
	tree->insert(90, 901);
	string expected = "([50,501],([20,201],,),([80,801],([70,701],,),([90,901],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeFromEmpty) {
	tree->remove(10);
	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeRoot) {
	tree->insert(50, 500);
	tree->remove(50);
	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeNotExisting) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	tree->insert(50, 501);
	tree->insert(20, 201);
	tree->insert(80, 801);
	tree->insert(70, 701);
	tree->insert(90, 901);
	tree->remove(25);
	string expected = "([50,501],([20,201],,),([80,801],([70,701],,),([90,901],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeNodeWithoutChildren) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->remove(20);
	string expected = "([50,500],,([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeNodeWithoutLeftChild) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	tree->remove(20);
	string expected = "([50,500],([30,300],,),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeNodeWithoutRightChild) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->remove(20);
	string expected = "([50,500],([10,100],,),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, removeNodeWithChildren) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->insert(30, 300);
	tree->insert(15, 150);
	tree->insert(12, 120);
	tree->remove(20);
	string expected = "([50,500],([15,150],([10,100],,([12,120],,)),([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, findInEmpty) {
	EXPECT_EQ(nullptr, tree->find(10));
};

TEST_F(BSTTest, findNotExisted) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(nullptr, tree->find(2));
	EXPECT_EQ(nullptr, tree->find(7));
	EXPECT_EQ(nullptr, tree->find(12));
	EXPECT_EQ(nullptr, tree->find(24));
};

TEST_F(BSTTest, findOnThe1LevelNoChildren) {
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
	tree->insert(5, 50);
	EXPECT_EQ(100, *tree->find(10));
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe1LevelIsLeftChild) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe1LevelIsRightChild) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe1LevelAreChildren) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe2LevelOnTheLeftThereIsNoRight) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	EXPECT_EQ(50, *tree->find(5));
};

TEST_F(BSTTest, findOnThe2LevelOnTheRightThereIsNoLeft) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	EXPECT_EQ(200, *tree->find(20));
};

TEST_F(BSTTest, findOnThe2LevelOnTheLeftThereIsRight) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	tree->insert(5, 50);
	EXPECT_EQ(50, *tree->find(5));
};

TEST_F(BSTTest, findOnThe2LevelOnTheRightThereIsLeft) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(200, *tree->find(20));
};

TEST_F(BSTTest, findOnThe3LevelLeftLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe3LevelLeftLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(BSTTest, findOnThe3LevelLeftRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	EXPECT_EQ(300, *tree->find(30));
};

TEST_F(BSTTest, findOnThe3LevelLeftRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->insert(30, 300);
	EXPECT_EQ(300, *tree->find(30));
};

TEST_F(BSTTest, findOnThe3LevelRightLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	EXPECT_EQ(700, *tree->find(70));
};

TEST_F(BSTTest, findOnThe3LevelRightLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	tree->insert(70, 700);
	EXPECT_EQ(700, *tree->find(70));
};

TEST_F(BSTTest, findOnThe3LevelRightRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	EXPECT_EQ(900, *tree->find(90));
};

TEST_F(BSTTest, findOnThe3LevelRightRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	EXPECT_EQ(900, *tree->find(90));
};

TEST_F(BSTTest, print0) {
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "";
	EXPECT_EQ(s1, s);
};

TEST_F(BSTTest, print1) {
	tree->insert(1, 1);
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "[1, 1]\n";
	EXPECT_EQ(s1, s);
};

TEST_F(BSTTest, print3) {
	tree->insert(2, 2);
	tree->insert(1, 1);
	tree->insert(3, 3);
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "[2, 2]\n    L: [1, 1]\n    R: [3, 3]\n";
	EXPECT_EQ(s1, s);
};

TEST_F(BSTTest, print7) {
	tree->insert(4, 4);
	tree->insert(2, 2);
	tree->insert(1, 1);
	tree->insert(3, 3);
	tree->insert(6, 6);
	tree->insert(5, 5);
	tree->insert(7, 7);

	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "[4, 4]\n    L: [2, 2]\n        L: [1, 1]\n        R: [3, 3]\n    R: [6, 6]\n        L: [5, 5]\n        R: [7, 7]\n";
	EXPECT_EQ(s1, s);
};

TEST_F(BSTTest, clearEmpty) {
	tree->clear();

	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(BSTTest, clear) {
	tree->insert(4, 4);
	tree->insert(2, 2);
	tree->insert(1, 1);
	tree->insert(3, 3);
	tree->insert(6, 6);
	tree->insert(5, 5);
	tree->insert(7, 7);

	tree->clear();

	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};
