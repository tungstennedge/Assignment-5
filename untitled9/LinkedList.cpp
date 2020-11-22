//
// Created by Wayne Li on 2020-11-21.
//

#include "LinkedList.h"
using namespace std;
LinkedList::LinkedList(){
    size = 0;
    this->head = NULL;
    this->tail = NULL;
    this->head->next = tail;

};

void LinkedList::insertStart(int i) {
    Node *temp=new Node;
    temp->value=i;
    temp->next=head;
    head=temp;
    size++;
}

void LinkedList::printList(){
    Node* curr = this->head;
    while(curr!=this->tail){
        cout << curr->value <<", ";
        curr = curr->next;
    }
}