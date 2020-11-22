//
// Created by Wayne Li on 2020-10-27.
//

#include "ArrayList.h"
#include "iostream"
#include <iterator>
using namespace std;
class Exception{
public:
    Exception(const string& err)
    :errMsg(err){}
    string getError(){
        return errMsg;
    }
private:
   string errMsg;
};
class InvalidIteratorException:public Exception{
public:
    InvalidIteratorException(const string& err)
    :Exception(err){}
};
class EmptyListException:public Exception{
public:
    EmptyListException(const string& err)
            :Exception(err){}
};
template<typename T>
T ArrayList<T>::Iterator::operator*() {
    return array_.array_[index];
}

template<typename T>
typename ArrayList<T>::Iterator ArrayList<T>::Iterator::operator++() {

    if(index >= (array_.capacity_-1)){
        index = 0;
    }else{
        index++;
    }

    return ArrayList::Iterator(index, array_);
}
template<typename T>
typename ArrayList<T>::Iterator ArrayList<T>::Iterator::operator--() {
    if(index == 0){
        index == array_.capacity-1;
    }
    else{
        index--;
    }
    return ArrayList::Iterator(index, array_);
}
template<typename T>
bool ArrayList<T>::Iterator::operator==(Iterator i) {

if(this->index == i.index){
    return true;
}else{
    return false;
}
}
template<typename T>
ArrayList<T>::ArrayList(){
    array_ = new T[4];
    capacity_ = 4;
    length_ = 0;
}

template<typename T>
ArrayList<T>::ArrayList(int c){
    array_ = new T[c];
    capacity_ = c;
    length_ = 0;
}
template <typename T>
bool ArrayList<T>::resize(const int new_capacity)
{
    auto* temp = new T[new_capacity];
    for (auto i{ 0 }; i < length_; ++i)
    {
        temp[i] = array_[(front_index + i) % capacity_];
    }
    delete[] array_;
    capacity_ = new_capacity;

    front_index = 0;
    array_ = temp;
    temp = nullptr;
    return true;
}

template <typename T>
void ArrayList<T>::insertBack(T e) {

    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    array_[(front_index + length_) % capacity_] = std::move(e);
    ++length_;

}
template<typename T>

void ArrayList<T>::print_arr() {
    for (int i = 0; i < capacity_; ++i) {
        cout<< array_[i];
    }
}

template<typename T>
void ArrayList<T>::insertFront(T e) {
    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    if (front_index == 0) front_index = capacity_ - 1;
    else --front_index;
    ++length_;
    array_[front_index] = e;
}
template<typename T>
void ArrayList<T>::insert(Iterator it, T e) {

    if (length_ >= capacity_) resize(static_cast<int>(capacity_ * 2));
    length_++;
    ArrayList<T> temp;
    temp = ArrayList<T>(capacity_);
    for (int j = 0; j < capacity_; ++j) {
        if(j == it.index){
            temp.insertBack(e);
        }
        temp.insertBack(array_[j]);
    }
    delete array_;
    array_ = temp.array_;


}
template<typename T>
void ArrayList<T>::removeFront() {

        if (length_ == 0) throw EmptyListException("list is empty!");

    front_index++;
    if(front_index== capacity_-1){
        front_index = 0;
    }

    length_--;
}
template<typename T>
void ArrayList<T>::removeBack() {

        if (length_ == 0) throw EmptyListException("list is empty!");

    --length_;
}

template<typename T>
void ArrayList<T>::remove(Iterator i) {

        if (length_ == 0)throw EmptyListException("list is empty!");

    ArrayList<T> temp;
    temp = ArrayList<T>(capacity_);
    for (int j = 0; j < capacity_; ++j) {
        if(j == i.index){
            j++;
        }
        temp.insertBack(array_[j]);
    }
    delete array_;
    array_ = temp.array_;
    length_--;
}
template<typename T>
int ArrayList<T>::size() {
    return length_;
}
template<typename T>
int ArrayList<T>::capacity(){
    return capacity_;
}
template<typename T>
bool ArrayList<T>::empty() {
if(length_ == 0){
    return true;
}
return false;
}

template<typename T>
typename ArrayList<T>::Iterator ArrayList<T>::end() {
    return ArrayList::Iterator((front_index + length_) % capacity_, *this);
}

template<typename T>
typename ArrayList<T>::Iterator ArrayList<T>::begin() {

    return ArrayList::Iterator(front_index, *this);
}
template<typename T>
T ArrayList<T>::operator[](int i) {
    return array_[(front_index + i) % capacity_];
}
template<typename T>
T ArrayList<T>::front() {
    return array_[front_index];
}
template<typename T>
T ArrayList<T>::back() {
    return array_[(front_index + length_) % capacity_];
}




