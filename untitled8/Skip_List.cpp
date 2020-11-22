//
// Created by Wayne Li on 2020-11-20.
//

#include "Skip_List.h"

Skip_List::Skip_List() {
head = new Quad_Node();
}

void Skip_List::put(Entry* e){
    Quad_Node* newNode = new Quad_Node(e);
    newNode->rightNode = head;
    newNode->leftNode = head->leftNode;
    head->leftNode = newNode;
}
void Skip_List::printList(){
    Quad_Node* curr = this->head;
}