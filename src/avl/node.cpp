#include "node.hpp"

namespace avl {
    node::node(const int value) : value(value), left(nullptr), right(nullptr), height(1) {}

    bool node::insert(const int value) {
        if (this->value == value) {
            return false;
        }

        if (value < this->value) {
            return insertIntoSubtree(left, value);
        }

        return insertIntoSubtree(right, value);
    }

    bool node::contains(const int value) const {
        return this->value == value || subtreeContains(left, value) || subtreeContains(right, value);
    }

    bool node::insertIntoSubtree(std::unique_ptr<node>& subtree, const int value) {
        if (subtree == nullptr) {
            subtree = std::make_unique<node>(value);
            height++;
            rebalance();
            return true;
        }

        return subtree->insert(value);
    }

    void node::rebalance() {
        // todo we need to check if we have a problem when we insert something in the middle of the tree, or if that's
        // even possible
        int heightDifference = left->height - right->height;
        if (heightDifference > 1) {
            rotateRight();
        } else if (heightDifference < -1) {
            rotateLeft();
        }
    }

    void node::rotateRight() {
        // todo
        height--;
        left->height++;

        if (left->right != nullptr) {
            // wait, how do we handle the pointer to this node from the parent?

            right = std::move(left->right);
            left->right = nullptr;
        }
    }

    void node::rotateLeft() {
        // todo
    }

    bool node::subtreeContains(const std::unique_ptr<node>& subtree, const int value) {
        return subtree != nullptr && subtree->contains(value);
    }

    bool node::remove(const int value) { return false; }
} // namespace avl
