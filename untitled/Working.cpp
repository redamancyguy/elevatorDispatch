#include "Working.h"

#include <iostream>
#include <queue>

#include "Person.h"

Working::Working(QObject *parent) : QObject(parent) {
  for (int i = 0; i < 6; ++i) elevatorDataList.append(new ElevatorData());

  connect(this, &Working::nameChanged, [=]() { qDebug() << this->name(); });

  for (int ii = 0; ii < 1000; ii++) {
    Person p(rand() % 21, rand() % 200,
             rand() % 21);     // num  weight  destination
    this->data.pressup(rand() % 21, p);  //从一楼 按 上楼按钮
  }
  for (int ii = 0; ii < 1000; ii++) {
    Person p(rand() % 21, rand() % 200,
             rand() % 21);     // num  weight  destination
    this->data.pressdown(rand() % 21, p);  //从一楼 按 上楼按钮
  }

  QTimer *timer = new QTimer(this);
  QObject::connect(timer, &QTimer::timeout, this, &Working::flush);
    for(int i=0;i<4;i++){
        QObject::connect(elevatorDataList[i], &ElevatorData::fButton, &(data.elevators[i]), &Elevator::press);
    }

  timer->start(200);
}
void Working::flush() {
  this->setName(this->name() + "!");

  for (int i = 0; i < 4; i++) {
    this->data.leave(
        i, this->data.getelevator(i).getplace());  //这一楼层的人都下电梯

    for (int y = 0; y < 10; y++) {
      this->data.getelevator(i).press(rand() % 20);
    }

    if (this->data.getelevator(i).getdirection()) {
      for (int ii = 0;
           ii <
           this->data.getpeopleup(this->data.getelevator(i).getplace()).size();
           ii++) {
        if (this->data.getelevator(i).getdirection() &&
            (this->data.getelevator(i).getW() +
                 this->data.getpeopleup(this->data.getelevator(i).getplace())
                     .front()
                     .getW() <
             this->data.getelevator(i).getmaxW())) {
          this->data.getelevator(i).pushpeopleStay(
              this->data.getpeopleup(this->data.getelevator(i).getplace())
                  .front());  //这一层的人进了 电梯 但是还没有确定去
                              //哪个目的地

          this->data.getpeopleup(this->data.getelevator(i).getplace()).pop();
          ii = -1;
          continue;
        }
        this->data.getpeopleup(this->data.getelevator(i).getplace())
            .push(this->data.getpeopleup(this->data.getelevator(i).getplace())
                      .front());
        this->data.getpeopleup(this->data.getelevator(i).getplace()).pop();
      }
    } else {
      for (int ii = 0;
           ii < this->data.getpeopledown(this->data.getelevator(i).getplace())
                    .size();
           ii++) {  // place 这一层的人都准备上电梯
        if (!this->data.getelevator(i).getdirection() &&
            (this->data.getelevator(i).getW() +
                 this->data.getpeopledown(this->data.getelevator(i).getplace())
                     .front()
                     .getW() <
             this->data.getelevator(i).getmaxW())) {
          this->data.getelevator(i).pushpeopleStay(
              this->data.getpeopledown(this->data.getelevator(i).getplace())
                  .front());  //这一层的人进了 电梯 但是还没有确定去
                              //哪个目的地

          this->data.getpeopledown(this->data.getelevator(i).getplace()).pop();
          ii = -1;
          continue;
        }
        this->data.getpeopledown(this->data.getelevator(i).getplace())
            .push(this->data.getpeopledown(this->data.getelevator(i).getplace())
                      .front());
        this->data.getpeopledown(this->data.getelevator(i).getplace()).pop();
      }
    }

    std::cout << "--------------------------"
              << this->data.getelevator(i).getPeopleNum() << std::endl;
    std::cout << "--------------------------" << this->data.getPeopleNum()
              << std::endl;
    if (this->data.getelevator(i).getPeopleNum() > 0 ||
        this->data.getPeopleNum() > 0) {
      this->data.getelevator(i).move();
    }
  }
  std::cout << std::endl;
  std::cout << "***************" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << "place:" << this->data.getelevator(i).getplace()
              << "    direction:" << this->data.getelevator(i).getdirection()
              << "weight:" << this->data.getelevator(i).getW() << "    "
              << std::endl;
    for (int ii = 0; ii <= fNum - 1; ii++) {
      std::cout << this->data.getelevator(i).getpeople(ii).size() << " ";
      elevatorDataList[i]->setValue(
          ii, this->data.getelevator(i).getpeople(ii).size());// s nldn
      elevatorDataList[i]->setpeopleNum(this->data.getelevator(i).getPeopleNum());
      elevatorDataList[i]->setFloor(this->data.getelevator(i).getplace());
      elevatorDataList[i]->setDirection(
          this->data.getelevator(i).getdirection());
    }
    std::cout << data.getelevator(i).getStayNum() << " "
              << data.getelevator(i).getW() << std::endl;
    std::cout << std::endl;
  }

  std::cout << std::endl;
  for (int ii = 0; ii <= fNum - 1; ii++) {
    std::cout << this->data.getpeopleup(ii).size() << " ";
    peopleup[ii].setNum(this->data.getpeopleup(ii).size());
    elevatorDataList[4]->setValue(ii, this->data.getpeopleup(ii).size());
  }
  std::cout << std::endl;
  for (int ii = 0; ii <= fNum - 1; ii++) {
    std::cout << this->data.getpeopledown(ii).size() << " ";
    peopledown[ii].setNum(this->data.getpeopledown(ii).size());
    elevatorDataList[5]->setValue(ii, this->data.getpeopledown(ii).size());
  }
  std::cout << std::endl;
  std::cout << "***************" << std::endl;
  std::cout << std::endl;
//  for (int iii = 0; iii < elevatorDataList[0]->getList().size(); iii++) {
//    qDebug() << elevatorDataList[0]->getList()[iii];
//  }
  qDebug() << elevatorDataList[0]->peopleNum();
}
void Working::press() { this->setName("456"); }

void Working::press1() {
  for (int i = 0; i < 100; i++) {
    Person p(rand() % 20, rand() % 200,
             rand() % 20);     // num  weight  destination
    this->data.pressup(1, p);  //从一楼 按 上楼按钮
  }
}
