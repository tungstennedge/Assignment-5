//
// Created by Wayne Li on 2020-11-20.
//

#include "Entry.h"
#include "iostream"
#include <cstdlib>
using namespace std;

Entry::Entry() {
    string baseString = "qwertyuiopasdfghjklzxcvbnm";
    key = rand()%100;

    for (int i = 0; i < 3; ++i) {
        int randomNum = rand() % 26;
        str+=baseString[randomNum];
    }
}
Entry::Entry(int k) {
    string baseString = "qwertyuiopasdfghjklzxcvbnm";
    key = k;

    for (int i = 0; i < 3; ++i) {
        int randomNum = rand() % 26;
        str+=baseString[randomNum];
    }
}
Entry::Entry(int k, string v) {
    key = k;
    str = v;
}

int Entry::getKey(){
    return key;
}
string Entry::getData(){
    return str;
}

void Entry::printSelf() {
    cout<< "("<< key <<", "<< str << ")\n";
}