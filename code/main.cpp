#include "../include/QueueLL.h"
#include "../include/StackLL.h"

int main() {
    QueueLL* q = new QueueLL();
    q->enqueue(10);
    q->enqueue(20);
    q->dequeue();
    q->enqueue(30);
    q->dequeue();
    q->display();

    return 0;
}
