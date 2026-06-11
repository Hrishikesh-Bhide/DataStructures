#include "PQArray.cpp"

int main() {
    PQArray* q = new PQArray(6);
    q->enqueue(100);
    q->enqueue(-200);
    q->enqueue(30);
    q->enqueue(40);
    q->dequeue();
    q->enqueue(50);
    q->enqueue(6);
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    return 0;
}