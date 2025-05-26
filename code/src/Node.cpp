#include "../include/Node.h"

Node::Node() {
    value = 0;
    next = nullptr;
}

Node::Node(int val) {
    value = val;
    next = nullptr;
}

Node::Node(int val, Node* n) {
    value = val;
    next = n;
}

void Node::setValue(int val) {
    if (val > 0) {
        value = val;
    }
}

int Node::getValue() {
    return value;
}

void Node::setNext(Node* node) {
    next = node;
}

Node* Node::getNext() {
    return next;
}