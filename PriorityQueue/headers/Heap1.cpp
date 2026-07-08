#include "Heap.h"

void Heap::resize(int new_cap) {
    int* temp = new int[new_cap];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    cap = new_cap;
}

int Heap::parent(int i) { return (i - 1) / 2; }
int Heap::left(int i)   { return 2 * i + 1; }
int Heap::right(int i)  { return 2 * i + 2; }

void Heap::swapAt(int a, int b) {
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void Heap::bubbleUp(int i) {
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

void Heap::bubbleDown(int i) {
    while (true) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && data[l] > data[largest]) largest = l;
        if (r < size && data[r] > data[largest]) largest = r;

        if (largest == i) break;

        swapAt(i, largest);
        i = largest;
    }
}

void Heap::buildHeapTD(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }
}