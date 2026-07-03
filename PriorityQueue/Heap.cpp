#include <iostream>
#include <algorithm>

class Heap {
    private:
      int* data;
      int size;
      int cap;
    
      void resize(int new_cap) {
        int* temp = new int[new_cap];
        for (int i = 0; i<size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        cap = new_cap;
      }

      int parent(int i) {
        return (i-1)/2;
      }

      int left(int i) {
        return 2*i + 1;
      }

      int right(int i) {
        return 2*i + 2;
      }

      void swapAt(int a, int b) {
        int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
      }
      
      void bubbleUp(int i) {
        while (i > 0) {
            int j = parent(i);
            if (data[j] < data[i]) {
                swapAt(i, j);
                i = j;
            } else {
                break;
            }
        }
      }

      void bubbleDown(int i) {
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;
            if (l < size and data[l] > data[largest]){
                largest = l;
            } 
            if (r < size and data[r] > data[largest]) {
                largest = r;
            }
            if (largest == i){
                break;
            }
            swapAt(i, largest);
            i = largest;
        }
      }

      void buildHeapTD(const int arr[], int n){
        for (int i = 0; i<n; i++) {
            insert(arr[i]);
        }
      }

      void buildHeapBU(const int arr[], int n){
        for (int i = 0; i<n; i++) {
            data[i] = arr[i];
        }
        size = n;
        for (int i = (n/2)-1; i>=0; i--) {
            bubbleDown(i);
        }
      }

    public:
      
      Heap(int n) {
        size = 0;
        cap = n;
        if (cap <= 0) {
            cap = 20;
        }
        data = new int[cap];
      }

      Heap(const int arr[], int n) {
        size = 0;
        cap = n;
        if (cap <= 0) {
            cap = 20;
        }
        data = new int[cap];
        buildHeapBU(arr, n);
      }

      void insert(int val) {
        if (size == cap) {
            resize(cap*2);
        }
        data[size] = val;
        bubbleUp(size);
        size++;
      }

      void extract() {
        if (size == 0) {
          std::cout << "The Heap is Empty!\n"; 
          return;   
        }
        swapAt(0, size-1);
        size--;
        if (size != 0) {
          bubbleDown(0);
        }        
      }

      void display() {
        std::cout << "Heap: ";
        for (int i=0; i<size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
      }

      void heapSort() {
        int n = size;
        for (int i=0; i<n; i++){
            extract();
        }
        size = n;
        std::cout << "Heap Sort" << std::endl;
        display();
        std::cout << "Heap Sort Done - Turning our array back into a Heap" << std::endl;
        std::reverse(data, data + size);
      }

      ~Heap() {
        delete[] data;
      }
};