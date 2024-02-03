#include "avl/tree.hpp"

#include <iostream>

int main() {
    avl::tree tree;
    tree.insert(2);
    tree.insert(5);
    std::cout << tree.contains(2) << std::endl;
    std::cout << tree.contains(6) << std::endl;
    // t.remove(5);
    // t.remove(6);
    std::cout << tree.getSize() << std::endl;

    std::cout << "Hi, I'm Henry Cavl!" << std::endl;
}