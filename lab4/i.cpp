#include <iostream>
#include <vector>

using namespace std;

// Node structure to store key and count
struct Node {
    int key;
    int count;
    Node* left;
    Node* right;
    Node(int k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

// Class for Binary Search Tree
class BST {
private:
    Node* root;

    // Insert helper function
    Node* insertHelper(Node* root, int key) {
        if (root == nullptr) return new Node(key);
        
        if (key == root->key) {
            root->count++; // Increment count if key already exists
        } else if (key < root->key) {
            root->left = insertHelper(root->left, key);
        } else {
            root->right = insertHelper(root->right, key);
        }
        return root;
    }

    // Delete helper function
    Node* deleteHelper(Node* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->key) {
            root->left = deleteHelper(root->left, key);
        } else if (key > root->key) {
            root->right = deleteHelper(root->right, key);
        } else {
            if (root->count > 1) {
                root->count--; // Decrease count if key exists multiple times
            } else {
                // If count is 1, delete the node
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                } else if (root->left == nullptr) {
                    Node* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    Node* temp = root->left;
                    delete root;
                    return temp;
                } else {
                    Node* successor = root->right;
                    while (successor->left != nullptr) {
                        successor = successor->left;
                    }
                    root->key = successor->key;
                    root->count = successor->count;
                    root->right = deleteHelper(root->right, successor->key);
                }
            }
        }
        return root;
    }

    // Count helper function
    int countHelper(Node* root, int key) {
        if (root == nullptr) return 0;
        if (root->key == key) return root->count;
        if (key < root->key) return countHelper(root->left, key);
        return countHelper(root->right, key);
    }

public:
    BST() : root(nullptr) {}

    // Insert method
    void insert(int key) {
        root = insertHelper(root, key);
    }

    // Delete method
    void deleteKey(int key) {
        root = deleteHelper(root, key);
    }

    // Count method
    int count(int key) {
        return countHelper(root, key);
    }
};

int main() {
    int Q;
    cin >> Q;

    BST tree;

    while (Q--) {
        string op;
        int x;
        cin >> op >> x;

        if (op == "insert") {
            tree.insert(x);
        } else if (op == "delete") {
            tree.deleteKey(x);
        } else if (op == "cnt") {
            cout << tree.count(x) << endl;
        }
    }

    return 0;
}
