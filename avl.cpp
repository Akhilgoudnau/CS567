#include "avl.h"
#include <iostream>
#include <algorithm>

using namespace std;

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    // TODO: Implement destructor to free allocated memory
}

Node* AVLTree::newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int AVLTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* AVLTree::insertNode(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(int key) {
    root = insertNode(root, key);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Node* AVLTree::deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVLTree::remove(int key) {
    root = deleteNode(root, key);
}

bool AVLTree::search(int key) {
    Node* current = root;
    while (current != nullptr) {
        if (current->key == key)
            return true;
        else if (current->key > key)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

int AVLTree::getHeight() {
    return height(root);
}

int AVLTree::getMinValue() {
    Node* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current->key;
}

int AVLTree::getMaxValue() {
    Node* current = root;
    while (current->right != nullptr)
        current = current->right;
    return current->key;
}

std::vector<int> AVLTree::printInorder() {
    Node* current = root;
    std::vector<int> res;
    printInorderHelper(current, res);
    std::cout << std::endl;

    return res;
}

std::vector<int> AVLTree::printInorderHelper(Node* node, std::vector<int>& res) {
    if (node != nullptr) {
        printInorderHelper(node->left, res);
        std::cout << node->key << " ";
        res.push_back(node->key);
        printInorderHelper(node->right, res);
    }
}
