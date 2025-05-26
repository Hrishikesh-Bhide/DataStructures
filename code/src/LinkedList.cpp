#include "../include/LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insertAtFront(int value) {
    Node* newnode = new Node(value, head);
    head = newnode;
}

void LinkedList::displayNodes() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->getValue() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

void LinkedList::insertAtBack(int value) {
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

void LinkedList::deleteAtFront() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteAtBack() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
