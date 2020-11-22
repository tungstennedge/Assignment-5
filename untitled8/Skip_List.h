//
// Created by Wayne Li on 2020-11-20.
//

#ifndef UNTITLED8_SKIP_LIST_H
#define UNTITLED8_SKIP_LIST_H
#include "Entry.h"

class Skip_List {

    class Quad_Node{
    public:
        Quad_Node* upperNode = NULL;
        Quad_Node* lowerNode = NULL;
        Quad_Node* leftNode = NULL;
        Quad_Node* rightNode = NULL;
        Entry *entry;
        Quad_Node(Entry* e){
            entry = e;
        }
        Quad_Node(){

        }
    };
private:
    Quad_Node* head;
public:
    int levels;
    void put(Entry* e);
    void printList();
    Skip_List();
};

#include "Skip_List.cpp"
#endif //UNTITLED8_SKIP_LIST_H
