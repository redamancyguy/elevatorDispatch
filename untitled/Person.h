//
// Created by 孙文礼 on 2021/4/27.
//

#ifndef ELEVATOR_PERSON_H
#define ELEVATOR_PERSON_H

#define fNum 21
#define eNum 4
#define false 0
#define true 1

class Person
{
private:
	int Num;
	int Destination;
	int Weight;
public:
	Person(int, int, int);
	int GetW() const;
	void SetW(int);
	int GetDestination() const;
};


#endif //ELEVATOR_PERSON_H

//0110
