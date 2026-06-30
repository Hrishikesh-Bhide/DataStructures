#include <iostream>

class PQArray {
    private:
       int* arr;
       int size;
       int capacity;
    public:
        PQArray(int cap) {
            if (cap <= 0) {
                cap = 10;
            }
            arr = new int[cap];
            capacity = cap;
            size = 0;
        } 
        ~PQArray() {
            delete[] arr;
        }
        void enqueue(int val) { // O(1)
            if (size == capacity) {
                std::cout << "Queue is Full - Could not insert! " << val << std::endl;
            } else {
                //std::cout << "Inserting " << val << std::endl;
                arr[size] = val;
                size = size + 1;
            }
        }
        void dequeue(){ // O(n)
            if (size == 0) {
                std::cout << "Queue is Empty" << std::endl;
            } else {
                int max = 0;
                for (int i = 0; i < size; i++) {
                    if (arr[i] > arr[max])
                    max = i;
                }
                std::cout << "Removing " << arr[max] << std::endl;
                for (int i = max; i<size-1; i++) {
                    arr[i] = arr[i+1];
                }
                size = size - 1;
            }
        }
};
