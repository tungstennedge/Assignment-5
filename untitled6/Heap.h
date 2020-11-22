//
// Created by Wayne Li on 2020-11-06.
//

#ifndef UNTITLED6_HEAP_H
#define UNTITLED6_HEAP_H
#include "Entry.h"

class Heap {
private:
    Entry* arr;
    int capacity;
    int stored;
public:
    Heap();
    ~Heap();
    Entry* getUnderlyingArray();
    Entry& removeMin();
    void insert(Entry e);
    int getSize();
    bool isEmpty();
    void make(Entry* entries, int n);
    int getParentIndex(int i);
    int getLeftIndex(int i);
    int getRightIndex(int i);
    bool hasParent(int i);
    bool hasLeft(int i);
    bool hasRight(int i);
    Entry parent(int i);
    Entry left(int i);
    Entry right(int i);
    Entry peek(int i);
    void swap(int i, int k);
    void expandCapacity();
    void heapifyDown(int i);
    void heapifyUp();
    void setVals(int i, int key, string s);




};

#include "Heap.cpp"
#endif //UNTITLED6_HEAP_H
