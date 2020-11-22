//
// Created by Wayne Li on 2020-11-20.
//

#ifndef UNTITLED8_ENTRY_H
#define UNTITLED8_ENTRY_H
#include<string>
using namespace std;


class Entry {
private:
    int key;
    string str;
public:
    int getKey(){
        return key;
    }
    string getData(){
        return str;
    }
    void printSelf();
    Entry(int k, string data);
    Entry();
    Entry(int k);
    void setKey(int i);
    void setStr(string s);
    //~Entry();
};

#include "Entry.cpp"
#endif //UNTITLED8_ENTRY_H
