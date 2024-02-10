#pragma once

#include "node.hpp"

namespace avl {
    class tree {
      private:
        node* root;
        int size;

      public:
        tree();
        void insert(int value);
        // add some kind of cpp docs here like java doc
        void remove(int value);
        bool contains(int value) const;
        int getSize() const;
        void printStructure();
        // maybe more...
    };
} // namespace avl