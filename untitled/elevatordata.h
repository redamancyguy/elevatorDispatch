#ifndef ELEVATORDATA_H
#define ELEVATORDATA_H


#include <QObject>
#include<QString>
#include<QList>
#include<QDebug>
#include<QVariantList>

class ElevatorData : public QObject
{
    Q_OBJECT
public:
    explicit ElevatorData(QObject *parent = nullptr);
    Q_PROPERTY(int floor READ floor WRITE setFloor NOTIFY floorChanged)
    Q_PROPERTY(QVariantList list READ getList NOTIFY listChanged)
    int floor(){
        return _floor;
    }
    void setFloor(int t){
        if(t!=_floor){
            _floor=t;
            floorChanged();
        }
    }
    Q_INVOKABLE void increaseFloor(){
        setFloor(floor()+1);
    }


    QVariantList getList() const{
        return _list;
    }

    Q_INVOKABLE void setValue(int i,int val){
        _list[i]=val;
        emit listChanged();
    }

    Q_INVOKABLE void increaseItem(int i){
        _list[i]=_list[i].toInt()+1;
        emit listChanged();
    }
public slots:

private:
    QVariantList _list;
    int _floor;
signals:
    void listChanged();
    void floorChanged();
};

#endif // ELEVATORDATA_H
