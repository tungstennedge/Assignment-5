#include "Animal.h"
#include <iostream>
using namespace std;
Animal::Animal(int age)
        :
        ageInMonths(age){

}

Animal::Animal()
        :
        ageInMonths(0){

}

Animal::~Animal(){
    //delete something
}
int Animal::getAgeInMonths(){
    return ageInMonths;
}
int Animal::getRepeats() {
    return 3;
}
void Animal::print(){
    cout <<ageInMonths;
    for (int i = 0; i < 3; ++i) {
        cout<< "grunt ";
    }
    cout << "\n";
}
