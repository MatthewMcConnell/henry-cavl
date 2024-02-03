#include "tree.hpp"

#include <memory>

namespace avl {
    tree::tree() : root(nullptr), size(0) {}

    void tree::insert(const int value) {
        if (root == nullptr) {
            root = new node(value);
        } else {
            root = node::insert(root, value);
        }
        size++;
    }

    bool tree::contains(const int value) const { return node::contains(root, value); }

    void tree::remove(const int value) {
        root = node::remove(root, value);
        size--;
    }

    int tree::getSize() const { return size; }
} // namespace avl
