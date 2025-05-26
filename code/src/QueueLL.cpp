#include "../include/QueueLL.h"

QueueLL::QueueLL() {
    ll = new LinkedList();
}

void QueueLL::enqueue(int value) {
    ll->insertAtBack(value);
}

void QueueLL::dequeue() {
    ll->deleteAtFront();
}

void QueueLL::display() {
    ll->displayNodes();
}