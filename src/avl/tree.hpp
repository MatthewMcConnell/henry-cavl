#pragma once

#include <memory>
#include "node.hpp"

namespace avl
{
    class tree
    {
    private:
        std::unique_ptr<node> root;

    public:
        tree();
        void insert(int value);
        // add some kind of cpp docs here like java doc
        bool remove(int value);
        bool contains(int value);
        int size();
        // maybe more...
    };
}