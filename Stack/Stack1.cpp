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

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }
    ~Stack() {
      while (head != nullptr) {
          Node* temp = head;
          head = head->next;
          delete temp;
      }
    }
    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

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

};
