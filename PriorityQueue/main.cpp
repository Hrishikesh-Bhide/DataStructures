#include "Heap.cpp"

int main() {
    Heap* h = new Heap(10);
    h->display();
    
    int* a = new int[5]{1, 10, 2, 12, 15};
    Heap* h2 = new Heap(a, 5);
    h2->display();
    h2->insert(100);
    h2->insert(80);
    h2->extract();
    h2->display();
    h2->heapSort();
    //h2->display();
    return 0;
}