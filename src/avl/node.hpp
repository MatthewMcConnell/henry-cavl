#pragma once

#include <optional>

namespace avl {
    class node {
      private:
        int value;
        node* left = nullptr;
        node* right = nullptr;
        int height = 1;

        static node* rotateRight(node* oldRoot) {
            node* newRoot = oldRoot->left;
            oldRoot->left = newRoot->right;
            newRoot->right = oldRoot;

            updateHeight(oldRoot);
            updateHeight(newRoot);

            return newRoot;
        }

        static node* rotateLeft(node* oldRoot) {
            node* newRoot = oldRoot->right;
            oldRoot->right = newRoot->left;
            newRoot->left = oldRoot;

            updateHeight(oldRoot);
            updateHeight(newRoot);

            return newRoot;
        }

        /**
         * @return std::optional<node*> - the node created or that was already present in the tree, otherwise empty
         */
        static std::optional<node*> doNormalBSTInsertion(node* root, int value) {
            if (root == nullptr) {
                return std::optional(new node(value));
            }

            if (value == root->value) {
                return std::optional(root);
            }

            if (value < root->value) {
                root->left = insert(root->left, value);
            }

            if (value > root->value) {
                root->right = insert(root->right, value);
            }

            return std::nullopt;
        }

        static void updateHeight(node* root) {
            root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
        }

        static int getHeight(node* root) { return root == nullptr ? 0 : root->height; }

        static node* rebalance(node* root, int value) {
            int balance = getBalance(root);

            if (balance > 1) {
                if (value > root->left->value) {
                    root->left = rotateLeft(root->left);
                }
                return rotateRight(root);
            } else if (balance < -1) {
                if (value < root->right->value) {
                    root->right = rotateRight(root->right);
                }
                return rotateLeft(root);
            }

            return root;
        }

        static int getBalance(node* root) { return getHeight(root->left) - getHeight(root->right); }

      public:
        node(int value) : value(value) {}
        int getValue() const { return value; }

        static node* insert(node* root, int value) {
            std::optional<node*> newNode = doNormalBSTInsertion(root, value);

            if (newNode.has_value()) {
                return newNode.value();
            }

            updateHeight(root);

            return rebalance(root, value);
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