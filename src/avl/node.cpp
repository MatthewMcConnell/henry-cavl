// #include "node.hpp"
// #include <memory>

// namespace avl {
//     node::node(const int value) : value(value), left(nullptr), right(nullptr), height(1) {}

//     std::unique_ptr<node> node::insert(const int value) {
//         if (this->value == value) {
//             return this;
//         }

//         if (value < this->value) {
//             return insertIntoSubtree(left, value);
//         }

//         return insertIntoSubtree(right, value);
//     }

//     bool node::contains(const int value) const {
//         return this->value == value || subtreeContains(left, value) || subtreeContains(right, value);
//     }

//     bool node::subtreeContains(const std::unique_ptr<node>& subtree, const int value) {
//         return subtree != nullptr && subtree->contains(value);
//     }

//     node node::remove(const int value) { return false; }
// } // namespace avl
