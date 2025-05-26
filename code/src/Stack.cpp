#include "../include/Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    head = nullptr;
}

void Stack::push(int value) {
    Node* newnode = new Node();
    newnode->setValue(value);
    if (head == nullptr) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    temp->setNext(newnode);
}

void Stack::pop() {
    if (head == nullptr) return;
    if (head->getNext() == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->getNext()->getNext() != nullptr) {
        temp = temp->getNext();
    }
    delete temp->getNext();
    temp->setNext(nullptr);
}

int Stack::peek() {
    if (head == nullptr) {
        cout << "Stack empty!";
        return -1;
    }
    Node* temp = head;
    while (temp->getNext() != nullptr) {
        temp = temp->getNext();
    }
    cout << "Peek: " << temp->getValue() << "\n";
    return temp->getValue();
}

bool Stack::isEmpty() {
    return (head == nullptr);
}

void Stack::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
