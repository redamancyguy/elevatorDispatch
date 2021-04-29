//
// Created by 孙文礼 on 2021/4/27.
//
#ifndef ELEVATOR_ELEVATOR_H
#define ELEVATOR_ELEVATOR_H
#include "Person.h"
#include "queue"
#include "QObject"


class Elevator : public QObject
{
Q_OBJECT
private:
	std::queue<Person> people[fNum]; //电梯的按钮  电梯里面的人下电梯是不会被阻碍的
	std::queue<Person> peopleStay;
	int place; //plce number  电梯在第几层
	bool direction;
	int maxW;
	int flag; //1 单层  2 双层 0全层
public:
	Elevator();
	void SetFlag(int data);
	void MoveUp();
	void Move();
	void MoveDown();
	void Leave(int index); //  int目的地是这个楼层的人都下楼了
	int GetW();
	void Display();
	bool GetDirection() const;
	void SetDirection(bool d);
	void ChangeDirection();
	int GetPlace() const;
	void SetPlace(int p);
	int GetMaxW() const;
	void SetMaxW(int data);
	int GetPeopleNum() const;
	int GetPeopleNums() const;
	void PushPeopleStay(Person person);
	Person GetPeopleStayFront();
	int getStayNum();
	std::queue<Person>& GetPeople(int index);

public slots:
	void press(int index); //有一个人按下了按钮 //队列中的第一个人准备上电梯  ，目的地为int  目的地由前端给出
};


#endif //ELEVATOR_ELEVATOR_H
