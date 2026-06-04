#include "LinkedList.cpp"

int main() {
    LinkedList* l = new LinkedList();
    l->insert_back(20);
    l->insert_back(30);
    int x[] = {1,2,3,4};
    l->insertManyAtBack(x, 4);
    l->display();
    l->insertManyAtFront(x, 4);
    l->display();

    LinkedList* stack = new LinkedList();
    stack->insert_back(20);
    stack->insert_back(30);
    stack->insert_front(10);

}