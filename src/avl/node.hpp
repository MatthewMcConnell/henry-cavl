#pragma once

#include <optional>

namespace avl {
    class node {
      private:
        int value;
        node* left = nullptr;
        node* right = nullptr;
        int height = 1;

        void rebalance();
        void rotateRight();
        void rotateLeft();

        static std::optional<node*> doNormalBSTInsertion(node* root, int value) {
            if (root == nullptr) {
                return std::optional<node*>(new node(value));
            }

            if (value == root->getValue()) {
                return std::optional<node*>(root);
            }

            if (value < root->getValue()) {
                root->left = insert(root->left, value);
            }

            if (value > root->getValue()) {
                root->right = insert(root->right, value);
            }

            return std::nullopt;
        }

      public:
        node(int value) : value(value) {}
        int getValue() const { return this->value; }

        static node* insert(node* root, int value) {
            std::optional<node*> newNode = doNormalBSTInsertion(root, value);

            if (newNode.has_value()) {
                return newNode.value();
            }

            return root;
        }

        static bool contains(node* root, int value) {
            if (root == nullptr) {
                return false;
            }

            if (value == root->value) {
                return true;
            }

            if (value < root->value) {
                return contains(root->left, value);
            }

            return contains(root->right, value);
        }

        node* remove(int value);
    };
} // namespace avl