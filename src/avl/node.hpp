#pragma once

#include <memory>

namespace avl
{
    class node
    {
    private:
        // todo remove the maybe unused later
        [[maybe_unused]] int value;
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;

    public:
        node(int value);
    };
}