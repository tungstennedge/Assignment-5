//
// Created by Wayne Li on 2020-11-21.
//

#ifndef UNTITLED9_LINKEDLIST_H
#define UNTITLED9_LINKEDLIST_H


class LinkedList {
    struct node {
        int data;
        node *next;
    };
    Private:
            node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
};

#include "LinkedList.cpp"
#endif //UNTITLED9_LINKEDLIST_H
