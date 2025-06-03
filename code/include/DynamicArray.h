#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* data;
    int capacity;
    int length;
    void resize();

public:
    DynamicArray();
    ~DynamicArray();
    void add(int value);
    void insertAt(int index, int value);
    int get(int index);
    int size();
    int getCapacity();
};

#endif