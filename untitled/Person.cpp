//
// Created by 孙文礼 on 2021/4/27.
//

#include "Person.h"
Person::Person(int num, int weight,int destination) {
    this->num = num;
    this->weight = weight;
    this->destination = destination;
}

int Person::getW() {
    return this->weight;
}

void Person::setW(int weight) {
    this->weight = weight;
}

int Person::getdestination() {
    return this->destination;
}
