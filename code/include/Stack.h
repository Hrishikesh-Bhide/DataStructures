#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
private:
    Node* head;

public:
    Stack();
    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};

#endif
