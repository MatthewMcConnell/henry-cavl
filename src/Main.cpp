#include "avl/tree.hpp"

#include <iostream>

int main() {
    avl::tree tree;
    tree.insert(2);
    tree.insert(5);
    tree.insert(10);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.insert(8);
    tree.insert(11);
    tree.insert(4);
    std::cout << "contains 2: " << tree.contains(2) << std::endl;
    std::cout << "contains 6: " << tree.contains(6) << std::endl;
    tree.remove(5);
    tree.remove(6);
    std::cout << "size of tree: " << tree.getSize() << std::endl;

    tree.printStructure();

    std::cout << "Hi, I'm Henry Cavl!" << std::endl;
}