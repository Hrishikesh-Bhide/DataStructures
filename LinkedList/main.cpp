#include "ll.cpp"

int main() {
    LinkedList* l = new LinkedList();
    l->insertAtFront(10);
    l->display();
    l->insertAtFront(20);
    l->insertAtFront(30);
    l->display();
    l->insertAtBack(40);
    l->insertAtBack(130);
    l->display();
    l->deleteAtBack();
    l->deleteAtFront();
    l->display();
}