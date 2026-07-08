#ifndef HEAP_H
#define HEAP_H

class Heap {
private:
    int* data;
    int size;
    int cap;

    void resize(int new_cap);

    int parent(int i);
    int left(int i);
    int right(int i);

    void swapAt(int a, int b);
    void bubbleUp(int i);
    void bubbleDown(int i);

    void buildHeapTD(const int arr[], int n);
    void buildHeapBU(const int arr[], int n);

public:
    Heap();
    Heap(const int arr[], int n);
    ~Heap();

    void insert(int val);
    void extract();
    void display();
    void heapSort();
};

#endif
