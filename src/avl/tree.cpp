#include "tree.hpp"

#include <memory>

namespace avl {
    tree::tree() : root(nullptr), treeSize(0) {}

    void tree::insert(int value) {
        if (root == nullptr) {
            root = std::make_unique<node>(value);
        } else {
            root->insert(value);
        }
        treeSize++;
    }

    bool tree::contains(int value) const {
        return treeSize > 0 && root->contains(value);
    }

    bool tree::remove(int value) {
        return root != nullptr || root->remove(value);
    }

    int tree::size() const { return treeSize; }
} // namespace avl
