#include "StackArray.cpp"

int main() {
    StackA* s = new StackA(2);
    s->pop();
    s->push(20);
    s->push(30);
    s->push(40);
    s->push(50);
    s->display();
    s->pop();
    s->display();
    s->pop();
    s->push(100);
    s->display();
    s->pop();
    s->display();
    s->pop();
    s->display();

}