//
// Created by 孙文礼 on 2021/4/27.
//

#include "Person.h"

Person::Person(int num, int weight, int destination)
{
	this->Num = num;
	this->Weight = weight;
	this->Destination = destination;
}

int Person::GetW() const
{
	return this->Weight;
}

void Person::SetW(int weight)
{
	this->Weight = weight;
}

int Person::GetDestination() const
{
	return this->Destination;
}
