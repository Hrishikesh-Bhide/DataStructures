#include "bst-opps.cpp"

//Added comments in main.cpp

int main() {
    BinarySearchTree* b = new BinarySearchTree();
    b->insert(10);
    b->insert(20);
    b->insert(30);
    b->insert(40);
    b->insert(2);
    b->insert(22);
    b->insert(2);
    b->insert(21);
    b->insert(1);
    b->insert(15);
    b->insert(14);
    b->inOrder();
    b->postOrder();
    b->preOrder();
    b->levelOrder();
    b->remove(15);
    b->remove(14);
    b->insert(14);
    b->insert(15);
    b->levelOrder();
    

}