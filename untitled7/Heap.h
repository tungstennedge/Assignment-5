//
// Created by Wayne Li on 2020-11-06.
//
#include "Entry.h"
#include <vector>
#ifndef UNTITLED7_HEAP_H
#define UNTITLED7_HEAP_H


class Heap {
private:
    vector<Entry> vect;
    int size;
    int capacity;
public:
    Heap();
    ~Heap();
};

#include "Heap.cpp"
#endif //UNTITLED7_HEAP_H
