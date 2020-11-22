//
// Created by Wayne Li on 2020-11-20.
//

#ifndef UNTITLED8_ENTRY_H
#define UNTITLED8_ENTRY_H
#include<string>
using namespace std;


class Entry {
public:
    int key;
    string str;
    void printSelf();
    Entry(int k, string data);
    Entry();
    Entry(int k);

    int getKey();
    string getData();
    //~Entry();
};

#include "Entry.cpp"
#endif //UNTITLED8_ENTRY_H
