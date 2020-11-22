#include <iostream>
#include "Entry.h"
#include "Skip_List.h"
int main() {
    int numEntries = 15;
   Skip_List* skipList = new Skip_List();
    for (int i = 0; i < numEntries; ++i) {
        Entry* e = new Entry(i);
        skipList->put(e);
    }
    skipList->printList();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
