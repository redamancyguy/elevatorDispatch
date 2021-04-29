#include "Working.h"
#include "Person.h"
#include <iostream>
#include <queue>


Working::Working(QObject* parent) : QObject(parent)
{
	for (int i = 0; i < 6; ++i) elevatorDataList.append(new ElevatorData());

	auto timer = new QTimer(this);
	QObject::connect(timer, &QTimer::timeout, this, &Working::Flush);

	for (int i = 0; i < 4; i++)
	{
		QObject::connect(elevatorDataList[i], &ElevatorData::fButton,
		                 &(data.elevators[i]), &Elevator::press);
	}

	QObject::connect(elevatorDataList[4], &ElevatorData::fButtonup, &(data),
	                 &Dispatch::PressBtnUp);
	QObject::connect(elevatorDataList[5], &ElevatorData::fButtondown,
	                 &(this->data), &Dispatch::PressBtnDown);
	timer->start(500);
}

void Working::Flush()
{
	for (int i = 0; i < 4; i++)
	{
		this->data.Leave(
			i, this->data.GetElevator(i).GetPlace()); //这一楼层的人都下电梯

		if (this->data.GetElevator(i).GetDirection())
		{
			for (size_t j = 0;
			     j <
			     this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace()).size();
			     j++)
			{
				if (this->data.GetElevator(i).GetDirection() &&
					(this->data.GetElevator(i).GetW() +
						this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace()).front().GetW() <
						this->data.GetElevator(i).GetMaxW()))
				{
					this->data.GetElevator(i).PushPeopleStay(
						this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace())
						    .front()); //这一层的人进了 电梯 但是还没有确定去
					//哪个目的地
					this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace()).pop();
					j = -1;
					continue;
				}
				this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace())
				    .push(this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace())
				              .front());
				this->data.GetPeopleUp(this->data.GetElevator(i).GetPlace()).pop();
			}
		}
		else
		{
			for (size_t j = 0;
			     j < this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace())
			             .size();
			     j++)
			{
				// place 这一层的人都准备上电梯
				if (!this->data.GetElevator(i).GetDirection() &&
					(this->data.GetElevator(i).GetW() +
						this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace())
						    .front()
						    .GetW() <
						this->data.GetElevator(i).GetMaxW()))
				{
					this->data.GetElevator(i).PushPeopleStay(
						this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace())
						    .front()); //这一层的人进了 电梯 但是还没有确定去
					//哪个目的地

					this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace()).pop();
					j = -1;
					continue;
				}
				this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace())
				    .push(this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace())
				              .front());
				this->data.GetPeopleDown(this->data.GetElevator(i).GetPlace()).pop();
			}
		}

		std::cout << "--------------------------"
			<< this->data.GetElevator(i).GetPeopleNum() << std::endl;
		std::cout << "--------------------------" << this->data.GetPeopleNum()
			<< std::endl;


		if (this->data.GetPeopleNum() == 0 && this->data.GetElevator(i).GetPeopleNums() == 0)
		{
			std::cout << "\n=========================== \n" << std::endl;
		}
		else
		{
			if (i == 1)
			{
				if (this->data.GetPeopleNum(1) > 0 || this->data.GetElevator(i).GetPeopleNum() > 0)
				{
					this->data.GetElevator(i).Move();
				}
			}
			else if (i == 2)
			{
				if (this->data.GetPeopleNum(0) > 0 || this->data.GetElevator(i).GetPeopleNum() > 0)
				{
					this->data.GetElevator(i).Move();
				}
			}
			else if (this->data.GetElevator(i).GetPeopleNum() > 0 ||
				this->data.GetPeopleNum() > 0)
			{
				this->data.GetElevator(i).Move();
			}
		}

		if (this->data.GetElevator(i).GetDirection())
		{
			int sum = 0;
			for (int ii = this->data.GetElevator(i).GetPlace(); ii < fNum; ii++)
			{
				sum += this->data.GetElevator(i).GetPeople(ii).size();
				sum += this->data.GetPeopleUp(ii).size();
				sum += this->data.GetPeopleDown(ii).size();
			}
			if (sum == 0 && !(this->data.GetPeopleNum() == 0 && this->data.GetElevator(i).GetPeopleNums() == 0))
			{
				this->data.GetElevator(i).ChangeDirection(); // ----------------------------------
			}
		}

		else
		{
			int sum = 0;
			for (int ii = this->data.GetElevator(i).GetPlace(); ii >= 0; ii--)
			{
				sum += this->data.GetElevator(i).GetPeople(ii).size();
				sum += this->data.GetPeopleUp(ii).size();
				sum += this->data.GetPeopleDown(ii).size();
			}
			if (sum == 0 && !(this->data.GetPeopleNum() == 0 && this->data.GetElevator(i).GetPeopleNums() == 0))
			{
				this->data.GetElevator(i).ChangeDirection(); // -------------------------------
			}
		}
	}
	std::cout << std::endl;
	std::cout << "***************" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << "place:" << this->data.GetElevator(i).GetPlace()
			<< "    direction:" << this->data.GetElevator(i).GetDirection()
			<< "weight:" << this->data.GetElevator(i).GetW() << "    "
			<< std::endl;
		for (int j = 0; j <= fNum - 1; j++)
		{
			std::cout << this->data.GetElevator(i).GetPeople(j).size() << " ";
			elevatorDataList[i]->setValue(
				j, this->data.GetElevator(i).GetPeople(j).size()); // s nldn
			elevatorDataList[i]->setPeopleNum(
				this->data.GetElevator(i).GetPeopleNum());
			elevatorDataList[i]->setFloor(this->data.GetElevator(i).GetPlace());
			elevatorDataList[i]->setDirection(
				this->data.GetElevator(i).GetDirection());
		}
		std::cout << data.GetElevator(i).GetStayNum() << " "
			<< data.GetElevator(i).GetW() << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i <= fNum - 1; i++)
	{
		std::cout << this->data.GetPeopleUp(i).size() << " ";
		peopleup[i].setNum(this->data.GetPeopleUp(i).size());
		elevatorDataList[4]->setValue(i, this->data.GetPeopleUp(i).size());
	}
	std::cout << std::endl;
	for (int i = 0; i <= fNum - 1; i++)
	{
		std::cout << this->data.GetPeopleDown(i).size() << " ";
		peopledown[i].setNum(this->data.GetPeopleDown(i).size());
		elevatorDataList[5]->setValue(i, this->data.GetPeopleDown(i).size());
	}
	std::cout << std::endl;
	std::cout << "***************" << std::endl;
	std::cout << std::endl;
	//  for (int iii = 0; iii < elevatorDataList[0]->getList().size(); iii++) {
	//    qDebug() << elevatorDataList[0]->getList()[iii];
	//  }
	qDebug() << elevatorDataList[0]->peopleNum();
}
