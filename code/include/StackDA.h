#ifndef STACK_DA_H
#define STACK_DA_H

#include "DynamicArray.h"

class StackDA {
private:
    DynamicArray arr;
    int top;

public:
    StackDA();

    void push(int value);
    void pop();
    int topElement();
    bool isEmpty();
    int size();
};

#endif
