//
// Created by 孙文礼 on 2021/4/27.
//

#include "Elevator.h"
#include <iostream>

Elevator::Elevator(): flag(0)
{
	this->maxW = 800;
	this->place = 0;
	this->direction = false;
}

void Elevator::press(int index)
{
	if (this->flag == 1 && index % 2 != 1)
	{
		std::cout << "单号电梯不允许上双号" << std::endl;
		return;
	}

	if (this->flag == 2 && index % 2 != 0)
	{
		std::cout << "双号电梯不允许上单号" << std::endl;
		return;
	}

	if (!this->peopleStay.empty())
	{
		this->people[index].push(this->peopleStay.front());
		this->peopleStay.pop();
	}
	else
	{
		std::cout << "电梯里面没有人  别乱按好吗？？？" << std::endl;
	}
}

void Elevator::SetFlag(int data)
{
	this->flag = data;
}

void Elevator::SetMaxW(int data)
{
	this->maxW = data;
}

void Elevator::MoveUp()
{
	if (this->place <= 20)
	{
		this->place++;
	}
	else
	{
		return;
	}
}

void Elevator::MoveDown()
{
	if (this->place >= 0)
	{
		this->place--;
	}
	else
	{
		return;
	}
}

void Elevator::Leave(int index)
{
	while (!this->people[index].empty())
	{
		this->people[index].pop();
		std::cout << "下楼咯" << std::endl;
	}
}

void Elevator::Display()
{
	for (int i = 0; i < fNum; i++)
	{
		for (int j = 0; j < people[i].size(); j++)
		{
			std::cout << "想要在" << i << "下楼" << people[i].front().GetW()
				<< std::endl;
			people[i].push(people[i].front());
			people[i].pop();
		}
	}
}

int Elevator::GetPeopleNum() const
{
	int sum = 0;
	for (int i = 0; i < fNum; i++)
	{
		sum += this->people[i].size();
	}
	return sum + this->peopleStay.size();
}


int Elevator::GetPeopleNums() const
{
	int sum = 0;
	for (int i = 0; i < fNum; i++)
	{
		sum += this->people[i].size();
	}
	return sum;
}

int Elevator::GetW()
{
	int sum = 0;
	for (int i = 0; i < fNum; i++)
	{
		for (int j = 0; j < people[i].size(); j++)
		{
			sum += people[i].front().GetW();
			people[i].push(people[i].front());
			people[i].pop();
		}
	}
	for (int j = 0; j < this->peopleStay.size(); j++)
	{
		sum += this->peopleStay.front().GetW();
		this->peopleStay.push(this->peopleStay.front());
		this->peopleStay.pop();
	}
	return sum;
}

bool Elevator::GetDirection() const { return this->direction; }

void Elevator::SetDirection(bool d) { this->direction = d; }

void Elevator::ChangeDirection() { this->direction = !this->direction; }

void Elevator::Move()
{
	if (this->flag == 0)
	{
		if ((this->GetPlace() == 0 && this->GetDirection() == 0) ||
			(this->GetPlace() == 20 && this->GetDirection() == 1))
		{
			this->ChangeDirection();
			return;
		}
		if (this->GetDirection())
		{
			this->place++;
		}
		else
		{
			this->place--;
		}
	}
	else
	{
		if (this->flag == 1)
		{
			if ((this->GetPlace() == 1 && this->GetDirection() == 0) ||
				(this->GetPlace() == 19 && this->GetDirection() == 1))
			{
				this->ChangeDirection();
				return;
			}
			if (this->GetDirection())
			{
				this->place += 2;
			}
			else
			{
				this->place -= 2;
			}
		}
		if (this->flag == 2)
		{
			if ((this->GetPlace() == 0 && this->GetDirection() == 0) ||
				(this->GetPlace() == 20 && this->GetDirection() == 1))
			{
				this->ChangeDirection();
				return;
			}
			if (this->GetDirection())
			{
				this->place += 2;
			}
			else
			{
				this->place -= 2;
			}
		}
	}
}

int Elevator::GetPlace() const { return this->place; }

void Elevator::SetPlace(const int p) { this->place = p; }

int Elevator::GetMaxW() const { return this->maxW; }

void Elevator::PushPeopleStay(Person person) { this->peopleStay.push(person); }

int Elevator::getStayNum() { return this->peopleStay.size(); }

Person Elevator::GetPeopleStayFront()
{
	Person pp = this->peopleStay.front();
	this->peopleStay.pop();
	return pp;
}

std::queue<Person>& Elevator::GetPeople(int index)
{
	return this->people[index];
}
