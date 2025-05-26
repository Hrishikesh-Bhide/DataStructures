#ifndef STACKLL_H
#define STACKLL_H

#include "LinkedList.h"

class StackLL {
private:
    LinkedList* ll;

public:
    StackLL();
    void push(int value);
    void pop();
    void peek();
};

#endif