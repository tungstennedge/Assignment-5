//
// Created by Wayne Li on 2020-11-20.
//

#include "Entry.h"
#include "iostream"
#include <cstdlib>
using namespace std;
string baseString = "qwertyuiopasdfghjklzxcvbnm";
Entry::Entry() {
    string baseString = "qwertyuiopasdfghjklzxcvbnm";
    key = rand()%100;

    for (int i = 0; i < 3; ++i) {
        int randomNum = rand() % 26;
        str+=baseString[randomNum];
    }
}
Entry::Entry(int k) {
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

void Entry::printSelf() {
    cout << "(" << key <<", "<<str<<")"<<"\n";
}