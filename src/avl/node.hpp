#pragma once

#include <iostream>
#include <optional>
#include <queue>

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
        static std::optional<node*> doBSTInsertion(node* root, int value) {
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

        static node* rebalance(node* root) {
            int balance = getBalance(root);

            if (balance > 1) {
                if (getBalance(root->left) < 0) {
                    root->left = rotateLeft(root->left);
                }
                return rotateRight(root);
            } else if (balance < -1) {
                if (getBalance(root->right) > 0) {
                    root->right = rotateRight(root->right);
                }
                return rotateLeft(root);
            }

            return root;
        }

        static int getBalance(node* root) {
            if (root == nullptr) {
                return 0;
            }
            return getHeight(root->left) - getHeight(root->right);
        }

        /**
         * Does a BST removal in place, potentially altering the root node provided
         */
        static void doBSTRemoval(node*& root, int value) {
            if (root != nullptr) {
                if (value < root->value) {
                    root->left = remove(root->left, value);
                } else if (value > root->value) {
                    root->right = remove(root->right, value);
                } else {
                    if (root->left != nullptr && root->right != nullptr) {
                        replaceWithMinValueInRightSubtree(root);
                    } else {
                        replaceWithChild(root);
                    }
                }
            }
        }

        static void replaceWithChild(node*& root) {
            node* newRoot = root->left != nullptr ? root->left : root->right;
            delete root;
            root = newRoot;
        }

        static void replaceWithMinValueInRightSubtree(node*& root) {
            int minValue = findMin(root->right);
            root->value = minValue;
            root->right = remove(root->right, minValue);
        }

        static int findMin(node*& root) {
            if (root->left == nullptr) {
                return root->value;
            }

            return findMin(root->left);
        }

      public:
        node(int value) : value(value) {}

        static node* insert(node* root, int value) {
            std::optional<node*> newNode = doBSTInsertion(root, value);

            if (newNode.has_value()) {
                return newNode.value();
            }

            updateHeight(root);
            return rebalance(root);
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

        static node* remove(node* root, int value) {
            doBSTRemoval(root, value);

            if (root == nullptr) {
                return nullptr;
            }

            updateHeight(root);
            return rebalance(root);
        }

        static void printStructure(node* root) {
            std::queue<node*> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                node* current = nodes.front();
                nodes.pop();

                std::cout << current->value << " ";

                if (current->left != nullptr) {
                    nodes.push(current->left);
                }

                if (current->right != nullptr) {
                    nodes.push(current->right);
                }
            }
            std::cout << std::endl;
        }
    };
} // namespace avl