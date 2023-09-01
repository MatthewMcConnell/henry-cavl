#include "node.hpp"

namespace avl {
    node::node(const int value) : value(value), left(nullptr), right(nullptr) {}

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

    bool node::remove(const int value) { return false; }
} // namespace avl
