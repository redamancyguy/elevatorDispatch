//
// Created by 孙文礼 on 2021/4/27.
//

#include "Elevator.h"
Elevator::Elevator() {
    this->maxW = 10800;
    this->place = 0;
    this->direction = false;
}


void Elevator::press(int index) {
    if(!this->peopleStay.empty()){
        this->people[index].push(this->peopleStay.front());
        this->peopleStay.pop();
    }
    else{
        std::cout<<"电梯里面没有人  别乱按好吗？？？"<<std::endl;
    }
}

void Elevator::press(int index, Person person) {
    this->people[index].push(person);
}

void Elevator::moveup() {
    if (this->place <= 20) {
        this->place++;
    } else {
        return;
    }
}

void Elevator::movedown() {
    if (this->place >= 0) {
        this->place--;
    } else {
        return;
    }
}

void Elevator::leave(int index) {
    while (!this->people[index].empty()){
        this->people[index].pop();
        std::cout<<"clear"<<std::endl;
    }
}

void Elevator::display() {
    for (int i = 0; i < fNum; i++) {
        for (int j = 0; j < people[i].size(); j++) {
            std::cout << "想要在" << i << "下楼" << people[i].front().getW() << std::endl;
            people[i].push(people[i].front());
            people[i].pop();
        }
    }
}

int Elevator::getW() {
    int sum = 0;
    for (int i = 0; i < fNum; i++) {
        for (int j = 0; j < people[i].size(); j++) {
            sum += people[i].front().getW();
            people[i].push(people[i].front());
            people[i].pop();
        }
    }
    for (int j = 0; j < this->peopleStay.size(); j++) {
        sum += this->peopleStay.front().getW();
        this->peopleStay.push(this->peopleStay.front());
        this->peopleStay.pop();
    }
    return sum;
}

bool Elevator::getdirection() {
    return this->direction;
}

void Elevator::setdirection(bool direction) {
    this->direction = direction;
}

void Elevator::changedirection() {
    this->direction = !this->direction;
}

void Elevator::move() {
    if (this->getdirection()) {
        this->place++;
    } else {
        this->place--;
    }
}


int Elevator::getplace() {
    return this->place;
}


void Elevator::setplace(int place){
    this->place = place;
}

int Elevator::getmaxW() {
    return this->maxW;
}


void Elevator::pushpeopleStay(Person person){
    this->peopleStay.push(person);
}


int Elevator::getStayNum(){
    return this->peopleStay.size();
}

Person Elevator::getpeopleStayfront(){
    Person pp = this->peopleStay.front();
    this->peopleStay.pop();
    return pp;
}
std::queue<Person> &Elevator::getpeople(int index) {
    return this->people[index];
}

