#include "LinkedList.cpp"

int main() {
    LinkedList* l = new LinkedList();
    l->insert_front(10);
    l->display();
    l->insert_front(20);
    l->insert_front(30);
    l->display();
    l->insert_back(40);
    l->insert_back(130);
    l->display();
    l->delete_back();
    l->delete_front();
    l->display();
}