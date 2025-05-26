#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value;
    Node* next;

    Node();
    Node(int val);
    Node(int val, Node* n);

    void setValue(int val);
    int getValue();

    void setNext(Node* node);
    Node* getNext();
};

#endif