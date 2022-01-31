#include <gtest/gtest.h>
#include "../AVLTreeLib/AVLTree.hpp"

using namespace std;

class AVLTreeTest : public ::testing::Test {
    protected:
		AVLTree<int, int>* tree;

        void SetUp() override {
            tree = new AVLTree<int, int>();
        }
};


TEST_F(AVLTreeTest, leftRootRotationAfterInsert) {
	tree->insert(10, 10);
	tree->insert(20, 20);
	string expected = "([10,10],,([20,20],,))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(30, 30);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, leftRotationAfterInsert) {
	tree->insert(60, 60);
	tree->insert(20, 20);
	tree->insert(70, 70);
	tree->insert(10, 10);
	tree->insert(30, 30);
	tree->insert(80, 80);
	tree->insert(25, 25);
	tree->insert(40, 40);
	string expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(50, 50);
	expected = "([60,60],([30,30],([20,20],([10,10],,),([25,25],,)),([40,40],,([50,50],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, rightLeftRootRotationAfterInsert) {
	tree->insert(10, 10);
	tree->insert(30, 30);
	string expected = "([10,10],,([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(20, 20);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, rightLeftRotationAfterInsert) {
	tree->insert(60, 60);
	tree->insert(20, 20);
	tree->insert(70, 70);
	tree->insert(10, 10);
	tree->insert(30, 30);
	tree->insert(80, 80);
	tree->insert(25, 25);
	tree->insert(40, 40);
	string expected = "([60,60],([20,20],([10,10],,),([30,30],([25,25],,),([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(22, 22);
	expected = "([60,60],([25,25],([20,20],([10,10],,),([22,22],,)),([30,30],,([40,40],,))),([70,70],,([80,80],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, rightRootRotationAfterInsert) {
	tree->insert(30, 30);
	tree->insert(20, 20);
	string expected = "([30,30],([20,20],,),)";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(10, 10);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, rightRotationAfterInsert) {
	tree->insert(30, 30);
	tree->insert(20, 20);
	tree->insert(80, 80);
	tree->insert(10, 10);
	tree->insert(60, 60);
	tree->insert(90, 90);
	tree->insert(50, 50);
	tree->insert(70, 70);
	string expected = "([30,30],([20,20],([10,10],,),),([80,80],([60,60],([50,50],,),([70,70],,)),([90,90],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(40, 40);
	expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, leftRightRootRotationAfterInsert) {
	tree->insert(30, 30);
	tree->insert(10, 10);
	std::string expected = "([30,30],([10,10],,),)";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(20, 20);
	expected = "([20,20],([10,10],,),([30,30],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, leftRightRotationAfterInsert) {
	tree->insert(30, 30);
	tree->insert(20, 20);
	tree->insert(80, 80);
	tree->insert(10, 10);
	tree->insert(50, 50);
	tree->insert(90, 90);
	tree->insert(40, 40);
	tree->insert(60, 60);
	string expected = "([30,30],([20,20],([10,10],,),),([80,80],([50,50],([40,40],,),([60,60],,)),([90,90],,)))";
	EXPECT_EQ(expected, tree->toString());
	tree->insert(70, 70);
	expected = "([30,30],([20,20],([10,10],,),),([60,60],([50,50],([40,40],,),),([80,80],([70,70],,),([90,90],,))))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, ConstructEmpty) {
	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertToEmpty) {
	tree->insert(10, 100);
	string expected = "([10,100],,)";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe2LevelOnTheLeftThereIsNoRight) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	string expected = "([10,100],([5,50],,),)";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe2LevelOnTheRightThereIsNoLeft) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	string expected = "([10,100],,([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe2LevelOnTheLeftThereIsRight) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	tree->insert(5, 50);
	string expected = "([10,100],([5,50],,),([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe2LevelOnTheRightThereIsLeft) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	string expected = "([10,100],([5,50],,),([20,200],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelLeftLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	string expected = "([50,500],([20,200],([10,100],,),),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelLeftLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	tree->insert(10, 100);
	string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelLeftRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	string expected = "([50,500],([20,200],,([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelLeftRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->insert(30, 300);
	string expected = "([50,500],([20,200],([10,100],,),([30,300],,)),([80,800],,))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelRightLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelRightLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	tree->insert(70, 700);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelRightRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	string expected = "([50,500],([20,200],,),([80,800],,([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertOnThe3LevelRightRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	string expected = "([50,500],([20,200],,),([80,800],([70,700],,),([90,900],,)))";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, insertExisting) {
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

TEST_F(AVLTreeTest, findInEmpty) {
	EXPECT_EQ(nullptr, tree->find(10));
};

TEST_F(AVLTreeTest, findNotExisted) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(nullptr, tree->find(2));
	EXPECT_EQ(nullptr, tree->find(7));
	EXPECT_EQ(nullptr, tree->find(12));
	EXPECT_EQ(nullptr, tree->find(24));
};

TEST_F(AVLTreeTest, findOnThe1LevelNoChildren) {
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
	tree->insert(5, 50);
	EXPECT_EQ(100, *tree->find(10));
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe1LevelIsLeftChild) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe1LevelIsRightChild) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe1LevelAreChildren) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe2LevelOnTheLeftThereIsNoRight) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	EXPECT_EQ(50, *tree->find(5));
};

TEST_F(AVLTreeTest, findOnThe2LevelOnTheRightThereIsNoLeft) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	EXPECT_EQ(200, *tree->find(20));
};

TEST_F(AVLTreeTest, findOnThe2LevelOnTheLeftThereIsRight) {
	tree->insert(10, 100);
	tree->insert(20, 200);
	tree->insert(5, 50);
	EXPECT_EQ(50, *tree->find(5));
};

TEST_F(AVLTreeTest, findOnThe2LevelOnTheRightThereIsLeft) {
	tree->insert(10, 100);
	tree->insert(5, 50);
	tree->insert(20, 200);
	EXPECT_EQ(200, *tree->find(20));
};

TEST_F(AVLTreeTest, findOnThe3LevelLeftLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe3LevelLeftLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	tree->insert(10, 100);
	EXPECT_EQ(100, *tree->find(10));
};

TEST_F(AVLTreeTest, findOnThe3LevelLeftRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(30, 300);
	EXPECT_EQ(300, *tree->find(30));
};

TEST_F(AVLTreeTest, findOnThe3LevelLeftRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(10, 100);
	tree->insert(30, 300);
	EXPECT_EQ(300, *tree->find(30));
};

TEST_F(AVLTreeTest, findOnThe3LevelRightLeftThereIsNoRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	EXPECT_EQ(700, *tree->find(70));
};

TEST_F(AVLTreeTest, findOnThe3LevelRightLeftThereIsRight) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	tree->insert(70, 700);
	EXPECT_EQ(700, *tree->find(70));
};

TEST_F(AVLTreeTest, findOnThe3LevelRightRightThereIsNoLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(90, 900);
	EXPECT_EQ(900, *tree->find(90));
};

TEST_F(AVLTreeTest, findOnThe3LevelRightRightThereIsLeft) {
	tree->insert(50, 500);
	tree->insert(20, 200);
	tree->insert(80, 800);
	tree->insert(70, 700);
	tree->insert(90, 900);
	EXPECT_EQ(900, *tree->find(90));
};

TEST_F(AVLTreeTest, print0) {
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "";
	EXPECT_EQ(s1, s);
};

TEST_F(AVLTreeTest, print1) {
	tree->insert(1, 1);
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "[1, 1]\n";
	EXPECT_EQ(s1, s);
};

TEST_F(AVLTreeTest, print3) {
	tree->insert(2, 2);
	tree->insert(1, 1);
	tree->insert(3, 3);
	ostringstream stream;
	tree->print(stream);
	auto s = stream.str();
	string s1 = "[2, 2]\n    L: [1, 1]\n    R: [3, 3]\n";
	EXPECT_EQ(s1, s);
};

TEST_F(AVLTreeTest, print7) {
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

TEST_F(AVLTreeTest, clearEmpty) {
	tree->clear();

	string expected = "";
	EXPECT_EQ(expected, tree->toString());
};

TEST_F(AVLTreeTest, clear) {
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