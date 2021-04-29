//
// Created by 孙文礼 on 2021/4/27.
//

#include "Elevator.h"
Elevator::Elevator() {
  this->maxW = 800;
  this->place = 0;
  this->direction = false;
}

void Elevator::press(int index) {



    if(this->flag == 1 && index % 2 != 1){
        std::cout<<"单号电梯不允许上双号"<<std::endl;
        return;
    }

    if(this->flag == 2 && index % 2 != 0){
        std::cout<<"双号电梯不允许上单号"<<std::endl;
        return;
    }

  if (!this->peopleStay.empty()) {
    this->people[index].push(this->peopleStay.front());
    this->peopleStay.pop();
  } else {
    std::cout << "电梯里面没有人  别乱按好吗？？？" << std::endl;
  }
}

void Elevator::setFlag(int data){
    this->flag = data;
}

void Elevator::setmaxW(int data){
    this->maxW = data;
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
  while (!this->people[index].empty()) {
    this->people[index].pop();
    std::cout << "下楼咯" << std::endl;
  }
}

void Elevator::display() {
  for (int i = 0; i < fNum; i++) {
    for (int j = 0; j < people[i].size(); j++) {
      std::cout << "想要在" << i << "下楼" << people[i].front().getW()
                << std::endl;
      people[i].push(people[i].front());
      people[i].pop();
    }
  }
}

int Elevator::getPeopleNum() {
  int sum = 0;
  for (int i = 0; i < fNum; i++) {
    sum += this->people[i].size();
  }
  return sum+this->peopleStay.size();
}


int Elevator::getPeopleNums() {
  int sum = 0;
  for (int i = 0; i < fNum; i++) {
    sum += this->people[i].size();
  }
  return sum;
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

bool Elevator::getdirection() { return this->direction; }

void Elevator::setdirection(bool direction) { this->direction = direction; }

void Elevator::changedirection() { this->direction = !this->direction; }

void Elevator::move() {

    if(this->flag == 0){
        if ((this->getplace() == 0 && this->getdirection()==0)||
             (this->getplace() == 20 && this->getdirection()==1)) {
          this->changedirection();
            return;
        }
        if (this->getdirection()) {
          this->place++;
        } else {
          this->place--;
        }
    }
    else{
        if(this->flag == 1)
        {
            if ((this->getplace() == 1&&this->getdirection()==0) ||
                 (this->getplace() == 19&&this->getdirection()==1)) {
              this->changedirection();
                return;
            }
            if (this->getdirection()) {
              this->place+=2;
            } else {
              this->place-=2;
            }
        }
        if(this->flag == 2)
        {
            if ((this->getplace() == 0&&this->getdirection()==0) ||
                    (this->getplace() == 20&&this->getdirection()==1)) {
              this->changedirection();
                return;
            }
            if (this->getdirection()) {
              this->place+=2;
            } else {
              this->place-=2;
            }
        }
    }
}

int Elevator::getplace() { return this->place; }

void Elevator::setplace(int place) { this->place = place; }

int Elevator::getmaxW() { return this->maxW; }

void Elevator::pushpeopleStay(Person person) { this->peopleStay.push(person); }

int Elevator::getStayNum() { return this->peopleStay.size(); }

Person Elevator::getpeopleStayfront() {
  Person pp = this->peopleStay.front();
  this->peopleStay.pop();
  return pp;
}
std::queue<Person> &Elevator::getpeople(int index) {
  return this->people[index];
}
