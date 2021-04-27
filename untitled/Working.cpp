#include "Working.h"
#include "Person.h"
#include<iostream>
#include<queue>
Working::Working(QObject *parent) : QObject(parent)
{

    for(int i=0;i<6;++i)elevatorDataList.append(new ElevatorData());




    connect(this,&Working::nameChanged,[=](){
        qDebug()<<this->name();
    });
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout,[&](){
        this->setName(this->name()+"!");
        for(int i=0;i<4;i++){
            this->data.leave(i,this->data.getelevator(i).getplace());
            if ((this->data.getelevator(i).getplace() == 0 || this->data.getelevator(i).getplace() == 20)) {
                this->data.getelevator(i).changedirection();
            }

            if(this->data.getelevator(i).getdirection()) {
                for(int ii = 0;ii < this->data.getpeopleup(this->data.getelevator(i).getplace()).size();ii++){
                    if(this->data.getelevator(i).getdirection()&&(this->data.getelevator(i).getW() + this->data.getpeopleup(this->data.getelevator(i).getplace()).front().getW() < this->data.getelevator(i).getmaxW())){
                        this->data.press(i,this->data.getpeopleup(this->data.getelevator(i).getplace()).front().getdestination(),this->data.getpeopleup(this->data.getelevator(i).getplace()).front()); //i代表几号电梯  ii代表想去哪个楼层
                        this->data.getpeopleup(this->data.getelevator(i).getplace()).pop();
                        ii = -1;
                        continue;
                    }
                    this->data.getpeopleup(this->data.getelevator(i).getplace()).push(this->data.getpeopleup(this->data.getelevator(i).getplace()).front());
                    this->data.getpeopleup(this->data.getelevator(i).getplace()).pop();
                }
            }else{
                for(int ii = 0;ii < this->data.getpeopledown(this->data.getelevator(i).getplace()).size();ii++){//place 这一层的人都准备上电梯
                    if(!this->data.getelevator(i).getdirection()&&
                            (this->data.getelevator(i).getW() + this->data.getpeopledown(this->data.getelevator(i).getplace()).front().getW() < this->data.getelevator(i).getmaxW())
                            ){
                        this->data.press(i,this->data.getpeopleup(this->data.getelevator(i).getplace()).front().getdestination(),this->data.getpeopledown(this->data.getelevator(i).getplace()).front()); //i代表几号电梯  ii代表想去哪个楼层
                        this->data.getpeopledown(this->data.getelevator(i).getplace()).pop();
                        ii = -1;
                        continue;
                    }
                    this->data.getpeopledown(this->data.getelevator(i).getplace()).push(this->data.getpeopledown(this->data.getelevator(i).getplace()).front());
                    this->data.getpeopledown(this->data.getelevator(i).getplace()).pop();
                }
            }
            this->data.getelevator(i).move();
        }
        std::cout << std::endl;
        std::cout << "***************" <<std::endl;
        for(int i=0;i<4;i++){
            std::cout << "place:" <<this->data.getelevator(i).getplace() <<"    direction:"<<this->data.getelevator(i).getdirection() << "weight:" <<this->data.getelevator(i).getW() <<"    "<<std::endl;
            for (int ii = 0; ii <= fNum-1; ii++){
                std::cout<<this->data.getelevator(i).getpeople(ii).size()<<" ";
            }
            std::cout << std::endl;
        }



        std::cout << std::endl;
        for (int ii = 0; ii <= fNum-1; ii++){
            std::cout<<this->data.getpeopleup(ii).size()<<" ";
            peopleup[ii].setNum(this->data.getpeopleup(ii).size());
        }
        std::cout << std::endl;
        for (int ii = 0; ii <= fNum-1; ii++){
            std::cout<<this->data.getpeopledown(ii).size()<<" ";
            peopledown[ii].setNum(this->data.getpeopledown(ii).size());
        }
        std::cout << std::endl;
        std::cout << "***************" << std::endl;
        std::cout << std::endl;
    });
    timer->start(200);
}
void Working::press(){
    this->setName("456");
}
void Working::press1(){
    for(int i=0;i<100;i++){
        Person p(random()%20,random()%200,random()%20);//num  weight  destination
        this->data.pressup(1,p); //从一楼 按 上楼按钮
    }
}

