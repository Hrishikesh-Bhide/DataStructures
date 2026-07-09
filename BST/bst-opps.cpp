#include <iostream>
#include <algorithm>

struct Node {
    int key;
    Node *left, *right;

    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* cur, int key) {
        if (cur == nullptr) return new Node(key);

        if (key < cur->key)
            cur->left = insertRec(cur->left, key);
        else if (key > cur->key)
            cur->right = insertRec(cur->right, key);

        return cur;
    }

    Node* findMin(Node* cur) {
        while (cur->left != nullptr)
            cur = cur->left;
        return cur;
    }

    Node* deleteRec(Node* cur, int key) {
        if (cur == nullptr) return nullptr;

        if (key < cur->key) {
            cur->left = deleteRec(cur->left, key);
        } else if (key > cur->key) {
            cur->right = deleteRec(cur->right, key);
        } else {
            if (cur->left == nullptr) {
                Node* temp = cur->right;
                delete cur;
                return temp;
            } else if (cur->right == nullptr) {
                Node* temp = cur->left;
                delete cur;
                return temp;
            }
            // Case 3: Two children
            Node* succ = findMin(cur->right);
            cur->key = succ->key;
            cur->right = deleteRec(cur->right, succ->key);
        }
        return cur;
    }

    int countRec(Node* curr) {
        int count = 0;
        if (curr != nullptr) {
            count += countRec(curr->left);
            count += countRec(curr->right);
            count += 1;
        }
        return count;
    }

    bool search(Node* curr, int val) {
        if (curr == nullptr) {
            return false;
        }
        if (curr->key == val) {
            return true;
        } else if (curr->key > val) {
            return search(curr->left, val);
        } else {
            return search(curr->right, val);
        }
    }

    int height(Node* curr) {
        if (curr != nullptr) {
            int lh = height(curr->left);
            int rh = height(curr->right);
            int h = std::max(lh, rh) + 1; 
            return h;
        } 
        return 0;
    }

    void clear(Node* curr) {
        if (curr == nullptr) return;

        clear(curr->left);
        clear(curr->right);
        delete curr;
    }


public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insertRec(root, key);
    }

    void remove(int key) {
        root = deleteRec(root, key);
    }

    int count() {
        return countRec(root);
    }

    bool search(int val) {
        return search(root, val);
    }

    int height() {
        return height(root)-1;
    }

    ~BinarySearchTree() {
       clear(root);
    }

};