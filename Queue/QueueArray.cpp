#include <iostream>

class Queue {
    private:
       int* arr;
       int front;
       int back;
       int capacity;
       int size;
    public:
        Queue(int cap) {
            if (cap <= 0) {
                cap = 10;
            }
            arr = new int[cap];
            front = 0;
            back = 0;
            capacity = cap;
            size = 0;
        } 
        ~Queue() {
            delete[] arr;
        }
        void enqueue(int val) {
            if (size == capacity) {
                std::cout << "Queue is Full - Resizing!" << std::endl;
                int* temp = new int(capacity + 4);
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[(front + i)%capacity];
                }
                capacity = capacity + 4;
                delete[] arr;
                arr = temp;
                front = 0;
                back = size;
                enqueue(val);

            } else {
                std::cout << "Enqueuing " << val << std::endl;
                arr[back] = val;
                back = (back + 1) % capacity;
                size = size + 1;
            }
        }
        void dequeue(){
            if (size == 0) {
                std::cout << "Queue is Empty" << std::endl;
            } else {
                std::cout << "Dequeuing " << arr[front] << std::endl;
                front = (front + 1) % capacity;
                size = size - 1;
            }
        }
        bool isEmpty() {
            return false;
        }
        void displayA(){
            std::cout << "Printing Array!" << std::endl;
            for (int i = 0; i < capacity; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
        void displayQ(){
            std::cout << "Printing Queue!" << std::endl;
            for (int i = 0; i < size; i++) {
                std::cout << arr[(front + i)%capacity] << " ";
            }
            std::cout << std::endl;
        }
};
