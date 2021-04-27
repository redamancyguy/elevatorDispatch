//
// Created by 孙文礼 on 2021/4/27.
//

#ifndef ELEVATOR_PERSON_H
#define ELEVATOR_PERSON_H

#define fNum 21
#define eNum 4
#define false 0
#define true 1

class Person{
private:
    int num;
    int destination;
    int weight;
public:
    Person(int, int ,int);
    int getW();
    void setW(int);
    int getdestination();
};


#endif //ELEVATOR_PERSON_H
