#include <iostream>
#include "ArrayList.h"
#include <iterator>
static void testArrayListUnderflow()
{
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        arr.removeFront();
        arr.removeFront();

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        arr.removeBack();
        arr.removeBack();

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }
    try{
        ArrayList<int> arr;
        arr = ArrayList<int>();
        arr.insertBack(1);
        ArrayList<int>::Iterator itr(0,arr);
        itr = arr.begin();
        arr.remove(itr);
        arr.remove(itr);

        cout <<"did not catch exception"<< "\n";
    }catch(EmptyListException){
        cout << "caught Empty Stack Excpetion" << "\n";
    }



}



template<typename T>
void printArr(ArrayList<T> L){

    for(auto iter = L.begin(); !(iter.operator==(L.end())); iter.operator++()) {

        cout << iter.operator*() << "\n";
    }
    cout << endl;
}
void testIntegerIterator(){
    ArrayList<int> arr;
    arr = ArrayList<int>();
    cout << "\n";
    for (int i = 0; i < 6; ++i) {
        arr.insertBack(i);
    }
    cout<< "printing first array: "<<"\n";
    printArr(arr);
    arr.removeFront();
    arr.removeFront();
    arr.removeFront();
    arr.insertBack(9);
    arr.insertBack(8);
    arr.insertBack(7);
    cout<< "printing array after 3x remove front, then 3x insertBack:"<< "\n";
    printArr(arr);
    cout <<"\n";
    cout << "\n" << "size: " << arr.size()<< "\n"; // num elements stored
    cout << "Capacity : " << arr.capacity()<< "\n";// current max array size
}
void testStringIterator(){
    ArrayList<string> arr;
    arr = ArrayList<string>();
    cout << "\n";
    arr.insertBack("nya");
    arr.insertBack("nyom");
    arr.insertBack("noot");
    arr.insertBack("na");
    arr.insertBack("no");
    arr.insertBack("naa");
    cout<< "printing first array: "<<"\n";
    printArr(arr);
    arr.removeFront();
    arr.removeFront();
    arr.removeFront();
    arr.insertBack("woof");
    arr.insertBack("whoof");
    arr.insertBack("woof");
    cout<< "printing array after 3x remove front, then 3x insertBack:"<< "\n";
    printArr(arr);
    cout <<"\n";
    cout << "\n" << "size: " << arr.size()<< "\n"; // num elements stored
    cout << "Capacity : " << arr.capacity()<< "\n";// current max array size

}
int main() {
    testArrayListUnderflow();
    testIntegerIterator();
    testStringIterator();
    return 0;
}



