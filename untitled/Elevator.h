//
// Created by 孙文礼 on 2021/4/27.
//
#include "Person.h"
#include "iostream"
#include "queue"
#include "QObject"
#ifndef ELEVATOR_ELEVATOR_H
#define ELEVATOR_ELEVATOR_H


class Elevator :public QObject {
    Q_OBJECT
private:
    std::queue<Person> people[fNum]; //电梯的按钮  电梯里面的人下电梯是不会被阻碍的
    std::queue<Person> peopleStay;
    int place; //plce number  电梯在第几层
    bool direction;
    int maxW;
    int flag;//1 单层  2 双层 0全层
public:
    Elevator();
    void setFlag(int);
    void moveup();
    void move();
    void movedown();
    void leave(int);//  int目的地是这个楼层的人都下楼了
    int getW();
    void display();
    bool getdirection();
    void setdirection(bool);
    void changedirection();
    int getplace();
    void setplace(int);
    int getmaxW();
    void setmaxW(int);
    int getPeopleNum();
    int getPeopleNums();
    void pushpeopleStay(Person);
    Person getpeopleStayfront();
    int getStayNum();
    std::queue<Person> &getpeople(int );


 public slots:
    void press(int);//有一个人按下了按钮 //队列中的第一个人准备上电梯  ，目的地为int  目的地由前端给出
};


#endif //ELEVATOR_ELEVATOR_H
