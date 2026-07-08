#include "Heap.h"
#include "Stack.h"

#include <iostream>
#include <algorithm>

void Stack::display(int a) {
  a = 0;
}

void Heap::buildHeapBU(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        data[i] = arr[i];
    }
    size = n;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        bubbleDown(i);
    }
}

void display(){

}

Heap::Heap() {
    size = 0;
    cap = 20;
    data = new int[cap];
}

Heap::Heap(const int arr[], int n) {
    size = 0;
    cap = (n == 0 ? 20 : n);
    data = new int[cap];
    buildHeapTD(arr, n);
}

Heap::~Heap() {
    delete[] data;
}

void Heap::insert(int val) {
    if (size == cap) {
        resize(cap * 2);
    }
    data[size] = val;
    bubbleUp(size);
    size++;
}

void Heap::extract() {
    if (size == 0) {
        std::cout << "The Heap is Empty!\n";
        return;
    }
    std::cout << data[0] << " ";
    swapAt(0, size - 1);
    size--;
    if (size != 0) {
        bubbleDown(0);
    }
}

void Heap::display() {
    std::cout << "Heap: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

void Heap::heapSort() {
    int n = size;
    for (int i = 0; i < n; i++) {
        extract();
    }
    size = n;
    display();
    std::reverse(data, data + size);
}
