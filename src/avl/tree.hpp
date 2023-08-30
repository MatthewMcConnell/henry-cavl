#pragma once

#include "node.hpp"

#include <memory>

namespace avl {
    class tree {
      private:
        std::unique_ptr<node> root;
        int treeSize;

      public:
        tree();
        void insert(int value);
        // add some kind of cpp docs here like java doc
        bool remove(int value);
        bool contains(int value) const;
        int size() const;
        // maybe more...
    };
} // namespace avl