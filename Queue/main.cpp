#include "QueueArray.cpp"

int main() {
    Queue* q = new Queue(4);
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->dequeue();
    q->displayQ();
    q->enqueue(50);
    q->displayA();
    q->enqueue(60);
    q->displayA();
    q->displayQ();
    q->enqueue(70);
    q->enqueue(80);
    q->enqueue(90);
    q->displayA();
    q->displayQ();   
    q->dequeue();
    q->dequeue();
    q->enqueue(100);
    q->enqueue(110);
    q->displayA();
    q->displayQ(); 
    q->enqueue(120);
    q->displayA();
    q->displayQ(); 
    return 0;
}