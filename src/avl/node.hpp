#pragma once

#include <memory>

namespace avl {
    class node {
      private:
        // todo remove the maybe unused later
        [[maybe_unused]] int value;
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;
        int height;

        static bool subtreeContains(const std::unique_ptr<node>& subtree, const int value);
        
        bool insertIntoSubtree(std::unique_ptr<node>& subtree, const int value);
        void rebalance();
        void rotateRight();
        void rotateLeft(); 

      public:
        node(const int value);
        bool insert(const int value);
        bool contains(const int value) const;
        bool remove(const int value);
    };
} // namespace avl