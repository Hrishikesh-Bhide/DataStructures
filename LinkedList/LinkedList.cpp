#include <iostream>

class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert_back(int val) {
        Node* temp = new Node(val);

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insert_front(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;

        if (tail == nullptr) {
            tail = temp;
        }
    }

    void delete_back() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }

        delete tail;
        tail = curr;
        tail->next = nullptr;
    }

    void delete_front() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
    }

    void display() {
        Node* curr = head;

        while (curr != nullptr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }

        std::cout << std::endl;
    }

    void insertManyAtBack(int x[], int n){
        for (int i = 0; i < n; i++) {
            insert_back(x[i]);
        }
    }

    void insertManyAtFront(int x[], int n){
        for (int i = 0; i < n; i++) {
            insert_front(x[i]);
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};