#include "Heap.cpp"

int main() {
    Heap* h = new Heap(10);
    h->display();
    h->enqueue(10);
    h->display();
    h->enqueue(8);
    h->display();
    h->enqueue(11);
    h->display();
    h->enqueue(3);
    h->display();
    h->enqueue(12);
    h->display();
    h->enqueue(100);
    h->display();
    h->enqueue(2);
    h->display();
    h->enqueue(1);
    h->display();
    h->dequeue();
    h->display();
    h->dequeue();
    h->display();
 
    return 0;
}