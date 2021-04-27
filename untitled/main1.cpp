#include "Dispatch.h"
#include "unistd.h"
#include "time.h"
int main() {
    dispatch data;
    for(int i=0;i<100;i++){
        person p(random()%20,random()%2000);
        data.pressup(i%20,p);
    }
    while (1) {
        int i = 0;
//        while (!data.getelevator(i).getpeople(data.getelevator(i).getplace()).empty()) data.getelevator(i).getpeople(data.getelevator(i).getplace()).pop(); //下电梯
        data.leave(i,data.getelevator(i).getplace());
        if ((data.getelevator(i).getplace() == 0 || data.getelevator(i).getplace() == 20)) {
            data.getelevator(i).changedirection();
        }
        if(data.getelevator(i).getdirection()) {
            for(int ii = 0;ii < data.getpeopleup(data.getelevator(i).getplace()).size();ii++){
                if(data.getelevator(i).getdirection()&&(data.getelevator(i).getW() + data.getpeopleup(data.getelevator(i).getplace()).front().getW() < data.getelevator(i).getmaxW())){
                    data.press(i,random()%20,data.getpeopleup(data.getelevator(i).getplace()).front()); //i代表几号电梯  ii代表想去哪个楼层
                    data.getpeopleup(data.getelevator(i).getplace()).pop();
                    continue;
                }
                data.getpeopleup(data.getelevator(i).getplace()).push(data.getpeopleup(data.getelevator(i).getplace()).front());
                data.getpeopleup(data.getelevator(i).getplace()).pop();
            }
        }else{
            for(int ii = 0;ii < data.getpeopledown(data.getelevator(i).getplace()).size();ii++){
                if(!data.getelevator(i).getdirection()&&(data.getelevator(i).getW() + data.getpeopledown(data.getelevator(i).getplace()).front().getW() < data.getelevator(i).getmaxW())){
                    data.press(i,random()%20,data.getpeopledown(data.getelevator(i).getplace()).front()); //i代表几号电梯  ii代表想去哪个楼层
                    data.getpeopledown(data.getelevator(i).getplace()).pop();
                    continue;
                }
                data.getpeopledown(data.getelevator(i).getplace()).push(data.getpeopledown(data.getelevator(i).getplace()).front());
                data.getpeopledown(data.getelevator(i).getplace()).pop();
            }
        }
        std::cout << std::endl;
        std::cout << "***************" <<std::endl;
        std::cout << "place:" <<data.getelevator(i).getplace() <<"    direction:"<<data.getelevator(i).getdirection()<< std::endl;
        std::cout << "weight:" <<data.getelevator(i).getW() <<"    "<<std::endl;
        for (int ii = 0; ii <= fNum-1; ii++){
            std::cout<<data.getelevator(i).getpeople(ii).size()<<" ";
        }
        std::cout << "***************" << std::endl;
        std::cout << std::endl;
        sleep(1);
        data.getelevator(i).move();
    }
    data.display();
    return 0;
}
