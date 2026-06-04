#include "Stack.cpp"

int main() {
    Stack* s = new Stack();
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);
    s->pop();
    s->pop();
    s->push(100);
    s->display();
    s->pop();
    s->display();
    s->pop();
    s->display();

}