//
// Created by Wayne Li on 2020-11-06.
//
#include <tgmath.h>
#include <iostream>
#include "Heap.h"
using namespace std;
Heap::Heap() {
    arr = new Entry[5];
    capacity = 5;
    stored = 0;
}
Heap::~Heap(){

}
bool Heap::isEmpty() {
    if(stored == 0) return true;
}

int Heap::getSize() {
    return capacity;
}
int Heap::getParentIndex(int i) {
    return floor(i-2)/2;
}
int Heap::getLeftIndex(int i) {
    return floor(i*2+1);
}
int Heap::getRightIndex(int i) {
    return floor(i*2+2);
}
bool Heap::hasParent(int i){
    return (getParentIndex(i)<capacity);
}
bool Heap::hasLeft(int i){
    return (getLeftIndex(i)<capacity);
}
bool Heap::hasRight(int i){
    return (getRightIndex(i)<capacity);
}
Entry Heap::parent(int i){
    return arr[getParentIndex(i)];
}
Entry Heap::left(int i){
    return arr[getLeftIndex(i)];
}
Entry Heap::right(int i){
    return arr[getRightIndex(i)];
}
void Heap::swap(int index1, int index2) {
    Entry tempval = arr[index1];
    arr[index1].setData(arr[index2].getKey(),arr[index2].getData());
    arr[index2].setData(tempval.getKey(),tempval.getData());
}
void Heap::expandCapacity() {
    if(stored == capacity){
        Entry* newArr = new Entry[capacity*2];
        for (int i = 0; i < stored; ++i) {
            newArr[i] = arr[i];
        }
        delete arr;
        arr = newArr;
        capacity*=2;
    }
}
Entry& Heap::removeMin() {
    if(stored == 0){
        cout << "empty heap error. ";
        throw;
    }
    if(stored == 1){
        stored --;
        return arr[0];
    }
    cout<< "printing arr[0]: ("<< arr[0].getKey()<<", "<<arr[0].getData()<< ")\n";
    Entry root = arr[0];
    cout<< "printing arr[stored-1]: ("<< arr[stored-1].getKey()<<", "<<arr[stored-1].getData()<< ")\n";
    arr[0].setData(arr[stored-1].getKey(),arr[stored-1].getData());
    cout<< "printing arr[0]: ("<< arr[0].getKey()<<", "<<arr[0].getData()<< ")\n";
    stored--;
    heapifyDown(0);
    cout<< "printing arr[0] after heapify: ("<< arr[0].getKey()<<", "<<arr[0].getData()<< ")\n";
    cout<< "printing root ("<< root.getKey()<<", "<<root.getData()<< ")\n";
    cout<< "printing arr after remove: \n";
    for (int i = 0; i < getSize(); ++i) {
        cout<< "printing arr["<<i<<"]: ("<< arr[i].getKey()<<", "<<arr[i].getData()<< ")\n";
    }
   Entry temp = arr[0];
    arr[0].setData(temp.getKey(),temp.getData());
    cout<<"\n\n";
    temp = root;
    return temp;
}
void Heap::heapifyDown(int i){
 int l = getLeftIndex(i);
 int r = getRightIndex(i);
 int smallest =i;
 if(l<stored && arr[l].getKey()<arr[smallest].getKey()){
     smallest = l;
 }if(r<stored&& arr[r].getKey()<arr[smallest].getKey()){
     smallest = r;
 }
 if(smallest != i){
     cout<< "smaller key is: "<< arr[smallest].getKey()<<"\n";
     cout<< "current key is: "<< arr[i].getKey()<<"\n";
     cout<< "printing arr[i]: ("<< arr[i].getKey()<<", "<<arr[i].getData()<< ")\n";
     cout<< "printing arr[smallest]: ("<< arr[smallest].getKey()<<", "<<arr[smallest].getData()<< ")\n";
     Entry tempval = arr[i];
     arr[i] = arr[smallest];
     arr[smallest] = tempval;
     cout<< "after swap, smaller key is: "<< arr[smallest].getKey()<<"\n";
     cout<< "after swap, current key is: "<< arr[i].getKey()<<"\n";
     cout<< "printing arr[i]: ("<< arr[i].getKey()<<", "<<arr[i].getData()<< ")\n";
     cout<< "printing arr[smallest]: ("<< arr[smallest].getKey()<<", "<<arr[smallest].getData()<< ")\n";
     heapifyDown(smallest);
 }
}

    void Heap::insert(Entry e){
        //expandCapacity();
        stored++;
        int i = stored-1;
        arr[i] = e;

        while(i!=0&&arr[getParentIndex(i)].getKey()>arr[i].getKey()){
            swap(i,getParentIndex(i));
            i = getParentIndex(i);
        }
    }


Entry Heap::peek(int i){
    if(i > stored){
        throw;
    }
    return arr[i];
}


void Heap::make(Entry* data, int n){
    for (int i = 0; i < n ; ++i) {
        insert(data[i]);
    }
}
Entry* Heap::getUnderlyingArray() {
    return arr;
}
void Heap::setVals(int i, int key, string s){
    arr[i].setData(key,s);
}