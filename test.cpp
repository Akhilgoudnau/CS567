#include "avl.h"
#include <deepstate/DeepState.hpp>

using namespace deepstate;

TEST(AVLTree, BasicOperations) {
    AVLTree avl;

    // Test insertion and search
    avl.insert(10);
    ASSERT_TRUE(avl.search(10));

    // Test deletion
    avl.remove(10);
    ASSERT_FALSE(avl.search(10));
}

TEST(AVLTree, HeightCalculation) {
    AVLTree avl;

    // Test height of an empty tree
    ASSERT_EQ(avl.getHeight(), 0);

    // Test height after insertion
    avl.insert(10);
    ASSERT_EQ(avl.getHeight(), 1);
    avl.insert(20);
    ASSERT_EQ(avl.getHeight(), 2);
}

TEST(AVLTree, MinMaxValue) {
    AVLTree avl;

    // Test min and max value of an empty tree
    ASSERT_EQ(avl.getMinValue(), INT_MAX);
    ASSERT_EQ(avl.getMaxValue(), INT_MIN);

    // Test min and max value after insertion
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    ASSERT_EQ(avl.getMinValue(), 5);
    ASSERT_EQ(avl.getMaxValue(), 20);
}

TEST(AVLTree, InorderTraversal) {
    AVLTree avl;

    // Test inorder traversal after insertion
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(15);
    
    std::vector<int> inorder = avl.printInorder();

    ASSERT_EQ(inorder.size(), 4);
    ASSERT_EQ(inorder[0], 5);
    ASSERT_EQ(inorder[1], 10);
    ASSERT_EQ(inorder[2], 15);
    ASSERT_EQ(inorder[3], 20);
}
