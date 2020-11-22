//
// Created by Wayne Li on 2020-11-06.
//
using namespace std;
#include <vector>
#include "Heap.h"
Heap::Heap(){
    vector<Entry> vect;
    for (int i = 0; i < 10; ++i) {
        vect.push_back(Entry());
    }
}