#include "../include/DynamicArray.h"
#include <iostream>
using namespace std;

DynamicArray::DynamicArray() {
    capacity = 4;
    length = 0;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize() {
    int newCapacity = capacity * 2;
    int* newData = new int[newCapacity];
    for (int i = 0; i < length; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void DynamicArray::add(int value) {
    if (length == capacity) {
        resize();
    }
    data[length++] = value;
}

void DynamicArray::insertAt(int index, int value) {
    if (index >= capacity) {
        while (index >= capacity) {
            resize();
        }
    }
    data[index] = value;
    if (index >= length) {
        length = index + 1;
    }
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= length) {
        cout << "Index out of bounds in get()\n";
        return -1;
    }
    return data[index];
}

int DynamicArray::size() {
    return length;
}

int DynamicArray::getCapacity() {
    return capacity;
}