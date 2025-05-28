#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int cap);
    ~CircularQueue();

    bool isEmpty();
    bool isFull();

    void enqueue(int value);
    void dequeue();

    int peek();

    void printQueue();
};

#endif
