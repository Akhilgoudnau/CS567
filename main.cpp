#include "avl.h"
#include <iostream>

int main() {
    AVLTree avl;

    // Test case 1: Insertion and search
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25); // Unbalance to test rotations

    std::cout << "Search 20: " << std::boolalpha << avl.search(20) << std::endl; // Should print true
    std::cout << "Search 100: " << std::boolalpha << avl.search(100) << std::endl; // Should print false

    // Test case 2: Deletion
    avl.remove(20);
    std::cout << "Search 20 after deletion: " << std::boolalpha << avl.search(20) << std::endl; // Should print false

    return 0;
}
