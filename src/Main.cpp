#include "avl/tree.hpp"

#include <iostream>

int main() {
    avl::tree t;
    t.insert(2);
    t.insert(5);
    std::cout << t.contains(2) << std::endl;
    std::cout << t.contains(6) << std::endl;
    t.remove(5);
    t.remove(6);
    std::cout << t.size() << std::endl;

    std::cout << "Hi, I'm Henry Cavl!" << std::endl;
}