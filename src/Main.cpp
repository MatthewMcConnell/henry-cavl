#include "avl/tree.hpp"

#include <iostream>

int main() {
    avl::tree tree;
    tree.insert(2);
    tree.insert(5);
    std::cout << "contains 2: " << tree.contains(2) << std::endl;
    std::cout << "contains 6: " << tree.contains(6) << std::endl;
    tree.remove(5);
    tree.remove(6);
    std::cout << "size of tree: " << tree.getSize() << std::endl;

    std::cout << "Hi, I'm Henry Cavl!" << std::endl;
}