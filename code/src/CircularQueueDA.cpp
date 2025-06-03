#include "../include/CircularQueueDA.h"
#include <iostream>
using namespace std;

CircularQueueDA::CircularQueueDA() {
    head = 0;
    tail = 0;
    count = 0;
}

void CircularQueueDA::enqueue(int value) {
    if (count == arr.getCapacity()) {
        int* temp = new int[count];
        for (int i = 0; i < count; i++) {
            temp[i] = arr.get((head + i) % arr.getCapacity());
        }
        for (int i = 0; i < count; i++) {
            arr.insertAt(i, temp[i]);
        }
        delete[] temp;

        head = 0;
        tail = count;
    }

    arr.add(value);
    tail = (tail + 1) % arr.getCapacity();
    count++;
}


void CircularQueueDA::dequeue() {
    if (count == 0) {
        cout << "Queue is empty\n";
        return;
    }
    head = (head + 1) % arr.getCapacity();
    count--;
}

int CircularQueueDA::front() {
    if (count == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return arr.get(head);
}

bool CircularQueueDA::isEmpty() {
    return count == 0;
}

int CircularQueueDA::size() {
    return count;
}