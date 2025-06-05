#include "../include/StackDA.h"
#include <iostream>
using namespace std;

StackDA::StackDA() {
    top = 0;
}

void StackDA::push(int value) {
    if (top < arr.size()) {
        arr.insertAt(top, value);
    } else {
        arr.add(value);
    }
    top++;
}

void StackDA::pop() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }
    top--;
}

int StackDA::topElement() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr.get(top - 1);
}

bool StackDA::isEmpty() {
    return top == 0;
}

int StackDA::size() {
    return top;
}
