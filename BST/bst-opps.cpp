#include <iostream>
#include <algorithm>
#include <queue>

struct Node {
    int key;
    int f;
    Node *left, *right;

    Node(int val) {
        f = 1;
        key = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* cur, int key) {
        if (cur == nullptr) return new Node(key);

        if (key < cur->key)
            cur->left = insert(cur->left, key);
        else if (key > cur->key)
            cur->right = insert(cur->right, key);
        else {
            cur->f += 1;
        }

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
            if (cur->f > 1) {
                cur->f -= 1;
                return cur;
            }
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
            cur->f = succ->f;
            succ->f = 1;
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

    void inOrder(Node* curr) {
        if (curr != nullptr) {
            inOrder(curr->left);
            for (int i = 1; i<= curr->f; i++) {
                std::cout << curr->key << " ";
            }
            inOrder(curr->right);
        }
    }

    void postOrder(Node* curr) {
        if (curr != nullptr) {
            postOrder(curr->left);
            postOrder(curr->right);
            for (int i = 1; i<= curr->f; i++) {
                std::cout << curr->key << " ";
            }
        }
    }

    //13 43 42 41 68 70 90 76 58 58

    void preOrder(Node* curr) {
        if (curr != nullptr) {
            for (int i = 1; i<= curr->f; i++) {
                std::cout << curr->key << " ";
            }
            preOrder(curr->left);
            preOrder(curr->right);
        }
    }

    void levelOrder(Node* curr) {
        if (curr == nullptr) {
            return;
        } 
        std::queue<Node*> q;
        q.push(curr);

        while (!q.empty()){
            Node* temp = q.front();
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
            q.pop();
            for (int i = 1; i<= temp->f; i++) {
                std::cout << temp->key << " ";
            }
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
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

    void inOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    void postOrder() {
        postOrder(root);
        std::cout << std::endl;
    }

    void preOrder() {
        preOrder(root);
        std::cout << std::endl;
    }

    void levelOrder() {
        levelOrder(root);
        std::cout << std::endl;
    }

    ~BinarySearchTree() {
       clear(root);
    }

};