#ifndef QUEUELL_H
#define QUEUELL_H

#include "LinkedList.h"

class QueueLL {
private:
    LinkedList* ll;

public:
    QueueLL();
    void enqueue(int value);
    void dequeue();
    void display();
};

#endif
