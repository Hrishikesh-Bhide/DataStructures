#include "../include/StackLL.h"

StackLL::StackLL() {
    ll = new LinkedList();
}

void StackLL::push(int value) {
    ll->insertAtBack(value);
}

void StackLL::pop() {
    ll->deleteAtBack();
}

void StackLL::peek() {
    ll->displayNodes();
}