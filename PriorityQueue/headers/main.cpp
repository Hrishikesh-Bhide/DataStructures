#include "Heap.h"

int main() {
    Heap* h = new Heap();

    h->insert(20);
    h->insert(50);
    h->display();

    h->insert(10);
    h->display();

    h->insert(100);
    h->display();

    h->insert(70);
    h->display();

    delete h;
    return 0;
}
