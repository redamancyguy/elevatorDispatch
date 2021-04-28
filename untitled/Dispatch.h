//
// Created by 孙文礼 on 2021/4/27.
//
#include "Elevator.h"
#ifndef ELEVATOR_DISPATCH_H
#define ELEVATOR_DISPATCH_H


class  Dispatch{  //使用电梯的类
    std::queue<Person> peopleup[fNum];
    std::queue<Person> peopledown[fNum];//楼梯门口排队
    Elevator elevators[eNum];
public:
    Dispatch();
    void press(int , int, Person);//前往 int1  电梯 的 int2  楼层
    void pressup(int, Person);
    void pressdown(int, Person);
    void display();
    Elevator &getelevator(int );
    std::queue<Person> &getpeopleup(int );
    std::queue<Person> &getpeopledown(int );
    void leave(int,int);
};


#endif //ELEVATOR_DISPATCH_H
