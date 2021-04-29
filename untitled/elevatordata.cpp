#include "elevatordata.h"

ElevatorData::ElevatorData(QObject* parent)
	: QObject(parent), _direction(-1), _peopleNum(0)
{
	_floor = 1;
	for (int i = 0; i < 21; ++i)
	{
		_list.append(0);
	}
}

void ElevatorData::setPeopleNum(int t)
{
	if (t != _peopleNum)
	{
		_peopleNum = t;
		emit peopleNumChanged();
	}
}

void ElevatorData::setFloor(int t)
{
	if (t != _floor)
	{
		_floor = t;
		emit floorChanged();
	}
}

void ElevatorData::setDirection(int t)
{
	if (t != _direction)
	{
		_direction = t;
		emit directionChanged();
	}
}

void ElevatorData::setValue(int i, int val)
{
	_list[i] = val;
	emit listChanged();
}

void ElevatorData::increaseItem(int i)
{
	_list[i] = _list[i].toInt() + 1;
	emit listChanged();
}
