#include <iostream>
#include "../LinkedList/LinkedList.cpp"

class Stack {
    private:
       LinkedList* l;
    public:
        Stack() {
            l = new LinkedList(); 
        } 
        ~Stack() {
            delete l;
        }
        void push(int val) {
            l->insert_front(val);
        }
        void pop(){
            l->delete_front();
        }
        void display(){
            l->display();
        }
};
