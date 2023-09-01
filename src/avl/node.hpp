#pragma once

#include <memory>

namespace avl {
    class node {
      private:
        // todo remove the maybe unused later
        [[maybe_unused]] int value;
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;

        static bool insertIntoSubtree(std::unique_ptr<node>& subtree, const int value) {
            if (subtree == nullptr) {
                subtree = std::make_unique<node>(value);
                return true;
            }

            return subtree->insert(value);
        }

        static bool subtreeContains(const std::unique_ptr<node>& subtree, const int value) {
            return subtree != nullptr && subtree->contains(value);
        }

      public:
        node(const int value);
        bool insert(const int value);
        bool contains(const int value) const;
        bool remove(const int value);
    };
} // namespace avl