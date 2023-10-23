#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a new node in the BST
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to search for a node with a specific value
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Function to perform an in-order traversal
    void inOrderTraversal() {
        inOrderTraversalRecursive(root);
    }

private:
    // Recursive function to insert a new node in the BST
    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Recursive function to search for a node with a specific value
    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        }

        if (value < node->data) {
            return searchRecursive(node->left, value);
        } else {
            return searchRecursive(node->right, value);
        }
    }

    // Recursive function to perform an in-order traversal
    void inOrderTraversalRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversalRecursive(node->left);
        std::
