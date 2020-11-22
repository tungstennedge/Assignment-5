//
// Created by Wayne Li on 2020-11-06.
//

#include "Entry.h"
#include <cstdlib>

Entry::Entry() {
    data = to_string(0);
    key = 0;
}
Entry::~Entry() {
}
void Entry::random() {
    data = to_string(7);
    key = rand()%100;
}

string Entry::getData() {
    return data;
}
int Entry::getKey() {
    return key;
}
void Entry::setData(int k, string s){
    data = s;
    key = k;
}

