#include <iostream>

class Heap {
    private:
       int* arr;
       int size;
       int capacity;

    public:

        Heap(int cap) {
            if (cap <= 0) {
                cap = 10;
            }
            arr = new int[cap];
            capacity = cap;
            size = 0;
        } 

        ~Heap() {
            delete[] arr;
        }

        int parent(int ind) {
            return (ind-1)/2;
        }

        void swap(int i, int j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        void bubbleUP(int ind) {
            while (ind > 0) {
                int p = parent(ind);
                if (arr[p] > arr[ind]) {
                    swap(p, ind);
                    ind = p;
                } else {
                    break;
                } 
            }
        }

        int leftChild(int i) {
            return (2*i)+1;
        }

        int rightChild(int i) {
            return (2*i)+2;
        }

        void bubbleDown(int ind) {
            while(true) {
                int l = leftChild(ind);
                int r = rightChild(ind);
                int smallest = ind;
                if (l < size && arr[l] < arr[ind]) {
                    smallest = l;
                }
                if (r < size && arr[r] < arr[smallest]) {
                    smallest = r;
                }
                if (smallest == ind) {
                    break;
                } else {
                    swap(ind, smallest);
                    ind = smallest;
                }
            }
        }

        void enqueue(int val) { // O(log n)
            if (size == capacity) {
                std::cout << "Queue is Full - Could not insert! " << val << std::endl;
            } else {
                //std::cout << "Inserting " << val << std::endl;
                arr[size] = val;
                bubbleUP(size);
                size = size + 1;
            }
        }

        void dequeue(){ // O(log n)
            if (size == 0) {
                std::cout << "Heap is Empty" << std::endl;
            } else {
               std::cout << "Removing " << arr[0] << std::endl;
               swap(0, size-1);
               size--;
               if (size > 0) {
                 bubbleDown(0);
               }
               
            }
        }

        void display(){
            if (size == 0) {
                std::cout << "Heap is Empty!" << std::endl;
            } else {
                std::cout << "Printing Heap!" << std::endl;
                for (int i = 0; i < size; i++) {
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }


};
