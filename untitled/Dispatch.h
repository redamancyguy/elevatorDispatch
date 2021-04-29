//
// Created by 孙文礼 on 2021/4/27.
//
#include <QObject>

#include "Elevator.h"
#ifndef ELEVATOR_DISPATCH_H
#define ELEVATOR_DISPATCH_H

class Dispatch : public QObject
{
	//使用电梯的类
Q_OBJECT
	std::queue<Person> PeopleUp[fNum];
	std::queue<Person> PeopleDown[fNum]; //楼梯门口排队

public:
	Elevator elevators[eNum];
	Dispatch();

	void PressUp(int index, Person person);
	void PressDown(int index, Person person);
	void Display();
	Elevator& GetElevator(int index);
	std::queue<Person>& GetPeopleUp(int index);
	std::queue<Person>& GetPeopleDown(int index);
	int GetPeopleNum() const;
	int GetPeopleNum(int flag) const;
	void Leave(int index1, int index2);
public slots:
	void PressBtnUp(int index);
	void PressBtnDown(int index);
};

#endif  // ELEVATOR_DISPATCH_H
