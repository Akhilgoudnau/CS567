#ifndef AVL_H
#define AVL_H

#include <limits.h>
#include <vector>

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
private:
    Node* root;

    Node* newNode(int key);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    int height(Node* node);
    int getBalance(Node* node);
    Node* insertNode(Node* node, int key);
    Node* minValueNode(Node* node);
    Node* deleteNode(Node* root, int key);

public:
    AVLTree();
    ~AVLTree();
    void insert(int key);
    void remove(int key);
    bool search(int key);
    int getHeight();
    int getMinValue();
    int getMaxValue();
    std::vector<int> printInorder();
    std::vector<int> printInorderHelper(Node* node, std::vector<int>& res);
};

#endif
