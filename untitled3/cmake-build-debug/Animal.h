//
// Created by Wayne Li on 2020-09-18.
//

#ifndef UNTITLED3_ANIMAL_H
#define UNTITLED3_ANIMAL_H

#endif //UNTITLED3_ANIMAL_H
class Animal{
private:
    int ageInMonths;
public:
    void print();
};

class Cow: public Animal{

public:
    static string noise();
    static int repeats();

};