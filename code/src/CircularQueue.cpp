#include <iostream>
#include "../include/CircularQueue.h"
using namespace std;

CircularQueue::CircularQueue(int cap) {
    capacity = cap;
    arr = new int[capacity];
    front = 0;
    rear = -1;
    size = 0;
}

CircularQueue::~CircularQueue() {
    delete[] arr;
}

bool CircularQueue::isEmpty() {
    return size == 0;
}

bool CircularQueue::isFull() {
    return size == capacity;
}

void CircularQueue::enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = value;
    size++;
    cout << "Enqueued: " << value << endl;
}

void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    cout << "Dequeued: " << arr[front] << endl;
    front = (front + 1) % capacity;
    size--;
}

int CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Nothing to peek." << endl;
        return -1;
    }
    return arr[front];
}

void CircularQueue::printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";
    for (int i = 0; i < size; i++) {
        int index = (front + i) % capacity;
        cout << arr[index] << " ";
    }
    cout << endl;
}

// Below is the version of the code we wrote together in class.
// Functionally, it is similar to the main implementation above.
// I'm including it here in case anyone wants to refer back to it.
// class CircularQueue {
// private:
//     int* arr;
//     int capacity;
//     int size;
//     int rear;
//     int front;

// public:
//     CircularQueue(int cap) {
//         capacity = cap;
//         arr = new int[cap];
//         front = 0;
//         rear = 0;
//         size = 0;
//     }

//     bool isFull() {
//         return size == capacity;
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     void enqueue(int val) {
//         if (isFull()) {
//             cout << "Queue is full. Cannot enqueue. " << endl;
//             return;
//         }
//         arr[rear] = val;
//         rear = (rear + 1) % capacity;
//         size = size + 1;
//         return;
//     }

//     void dequeue() {
//         if (isEmpty()) {
//             cout << "Queue is empty. Cannot Dequeue. " << endl;
//             return;
//         }
//         front = (front + 1) % capacity;
//         size = size - 1;
//         return;
//     }

//     void printQueue() {
//         if (isEmpty()) {
//             cout << "Queue is empty. Cannot Print. " << endl;
//             return;
//         }
//         int temp = front;
//         for (int temp = 0; temp < size; temp = (temp + 1)) {
//             cout << arr[(front + temp) % capacity] << " ";
//         }
//         cout << endl;
//     }

// };