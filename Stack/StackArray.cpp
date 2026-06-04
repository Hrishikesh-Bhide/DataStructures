#include <iostream>
#include "../LinkedList/LinkedList.cpp"

class StackA {
    private:
       int* arr;
       int top;
       int capacity;
    public:
        StackA(int size) {
            if (size <= 0) {
                size = 10;
            }
            arr = new int[size];
            top = -1;
            capacity = size;
        } 
        ~StackA() {
            delete[] arr;
        }
        void push(int val) {
            if (top < capacity-1) {
                top++;
                arr[top] = val;
                std::cout << "Pushed successfully " << val << std::endl;
            } else {
                std::cout << "Stack is full! Resizing!" << std::endl;
                int* temp = new int[capacity*2];
                for (int i = 0; i<= top; i++) {
                    temp[i] = arr[i];
                }
                delete[] arr;
                arr = temp;
                capacity = capacity*2;
                push(val);
            }
        }
        void pop(){
            if (top == -1) {
                std::cout << "Stack is Empty!" << std::endl;
            } else {
                std::cout << " Deleting " << arr[top] << std::endl;
                top --;
            }
        }
        bool isEmpty() {
            return (top == -1);
        }
        void display(){
            if (top == -1) {
                std::cout << "Stack is Empty!" << std::endl;
            } else {
                std::cout << "Printing Stack!" << std::endl;
                for (int i = 0; i <= top; i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }
};
