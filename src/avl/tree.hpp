#pragma once

#include "node.hpp"

#include <memory>

namespace avl {
    class tree {
      private:
        std::unique_ptr<node> root;
        int size;

      public:
        tree();
        void insert(const int value);
        // add some kind of cpp docs here like java doc
        bool remove(const int value);
        bool contains(const int value) const;
        int getSize() const;
        // maybe more...
    };
} // namespace avl