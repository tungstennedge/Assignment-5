//
// Created by Wayne Li on 2020-09-24.
//

#ifndef UNTITLED4_ANIMAL_H
#define UNTITLED4_ANIMAL_H


#include <iostream>
class Animal{
private:
    int ageInMonths;
public:
    Animal(int age);
    Animal();
    ~Animal();
    void print();
    int getRepeats();
    int getAgeInMonths();
};

class Cow: public Animal{
public:
    std::string getNoise();
    int getRepeats();
    int getAgeInMonths();
private:
};


#endif //UNTITLED4_ANIMAL_H
