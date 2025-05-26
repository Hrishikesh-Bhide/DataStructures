#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();

    void insertAtFront(int value);
    void insertAtBack(int value);
    void deleteAtFront();
    void deleteAtBack();
    void displayNodes();
};

#endif