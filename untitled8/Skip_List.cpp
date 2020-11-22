//
// Created by Wayne Li on 2020-11-20.
//

#include "Skip_List.h"
using namespace std;
Skip_List::Skip_List() {
head = new Quad_Node();
Entry* e = new Entry(-9999999);
head->entry = e;
levels = 0;
}

void Skip_List::put(Entry* e){
    int insertAtLevel = findRandomLevel();
    cout<< "insertatlvl: " << insertAtLevel <<"\n";
    if(levels <= insertAtLevel){
        levels++;
        insertAtLevel = levels;
        Quad_Node* newHead = new Quad_Node();
        Entry* e = new Entry(-9999999);
        newHead->entry = e;
        newHead->lowerNode = head;
        head->upperNode = newHead;
        head = newHead;
    }
    int levelDifference = levels-insertAtLevel;
    Quad_Node* curr = head;
    while(levelDifference>0){
        curr = head->lowerNode;
        levelDifference--;
    }
    while(curr->rightNode&&curr->entry->key < curr->rightNode->entry->key){
        curr = curr->rightNode;
    }
    Quad_Node* newNode = new Quad_Node(e);
    newNode->leftNode = curr;
    newNode->rightNode = curr->rightNode;
    curr->rightNode = newNode;

    while(curr->lowerNode){
        curr = curr->lowerNode;
        while(curr->rightNode&&curr->entry->key < curr->rightNode->entry->key){
            curr = curr->rightNode;
        }
        Quad_Node* newNode = new Quad_Node(e);
        newNode->leftNode = curr;
        newNode->rightNode = curr->rightNode;
        curr->rightNode = newNode;

    }

}
int Skip_List::findRandomLevel(){
    int random = rand()%100;
    int count = 0;
    while(random > 50){
        count++;
        random =  rand()%100;
    }
    return count;
}
void Skip_List::printList(){
    Quad_Node* curr = this->head;
    while(curr->lowerNode) {
        while (curr) {
            curr->entry->printSelf();
            curr = head->leftNode;
        }
        curr = curr->lowerNode;
    }
}