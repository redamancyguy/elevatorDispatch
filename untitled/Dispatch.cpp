//
// Created by 孙文礼 on 2021/4/27.
//

#include "Dispatch.h"
#include <iostream>

Dispatch::Dispatch()
{
	elevators[0].SetFlag(0);
	elevators[0].SetPlace(1);
	elevators[0].SetMaxW(800);

	elevators[1].SetFlag(1);
	elevators[1].SetPlace(1);
	elevators[1].SetMaxW(800);

	elevators[2].SetFlag(2);
	elevators[2].SetMaxW(800);
	elevators[2].SetPlace(0);

	elevators[3].SetFlag(0);
	elevators[3].SetMaxW(2000);
	elevators[3].SetPlace(1);
}

void Dispatch::PressUp(const int index, const Person person)
{
	PeopleUp[index].push(person);
}

int Dispatch::GetPeopleNum() const
{
	int sum = 0;
	for (int i = 0; i < fNum; i++)
	{
		sum += this->PeopleUp[i].size();
		sum += this->PeopleDown[i].size();
	}
	return sum;
}


int Dispatch::GetPeopleNum(const int flag) const
{
	int sum = 0;
	for (int i = 0; i < fNum; i++)
	{
		if (i % 2 == flag)
		{
			sum += this->PeopleUp[i].size();
			sum += this->PeopleDown[i].size();
		}
	}
	return sum;
}


void Dispatch::PressDown(const int index, const Person person)
{
	PeopleDown[index].push(person);
}

void Dispatch::PressBtnDown(const int index)
{
	Person p(rand() % 21, rand() % 200, rand() % 21);
	this->PeopleDown[index].push(p);
}

void Dispatch::PressBtnUp(const int index)
{
	Person p(rand() % 21, rand() % 200, rand() % 21);
	this->PeopleUp[index].push(p);
}

void Dispatch::Display()
{
	std::cout << "people up" << std::endl;
	for (int i = 0; i < fNum; i++)
	{
		for (size_t j = 0; j < PeopleUp[i].size(); j++)
		{
			std::cout << i << " " << PeopleUp[i].front().GetW() << std::endl;
			PeopleUp[i].push(PeopleUp[i].front());
			PeopleUp[i].pop();
		}
	}
	std::cout << std::endl;
	std::cout << "people down" << std::endl;
	for (int i = 0; i < fNum; i++)
	{
		for (size_t j = 0; j < PeopleDown[i].size(); j++)
		{
			std::cout << i << " " << PeopleDown[i].front().GetW() << std::endl;
			PeopleDown[i].push(PeopleDown[i].front());
			PeopleDown[i].pop();
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < eNum; i++)
	{
		std::cout << "num:" << i << std::endl;
		elevators[i].Display();
	}
}

Elevator& Dispatch::GetElevator(const int index) { return this->elevators[index]; }

std::queue<Person>& Dispatch::GetPeopleUp(const int index)
{
	return this->PeopleUp[index];
}

std::queue<Person>& Dispatch::GetPeopleDown(const int index)
{
	return this->PeopleDown[index];
}

void Dispatch::Leave(const int index1, const int index2)
{
	this->elevators[index1].Leave(index2);
}
