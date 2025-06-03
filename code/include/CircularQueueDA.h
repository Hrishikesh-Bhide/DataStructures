#ifndef CIRCULARQUEUE_DA_H
#define CIRCULARQUEUE_DA_H

#include "DynamicArray.h"

class CircularQueueDA {
private:
    DynamicArray arr;
    int head;
    int tail;
    int count;

public:
    CircularQueueDA();
    void enqueue(int value);
    void dequeue();
    int front();
    bool isEmpty();
    int size();
};

#endif