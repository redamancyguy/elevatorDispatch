#ifndef WORKING_H
#define WORKING_H

#include <QObject>
#include "Dispatch.h"
#include <QDebug>
#include <QTimer>
#include "elevatordata.h"
#include "Person.h"
class Working : public QObject
{
    Dispatch data;
    Q_OBJECT
     Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
public:
    explicit Working(QObject *parent = nullptr);
        QString _data;
        QString peopleup[21];
        QString peopledown[21];


       QList<ElevatorData*> elevatorDataList;
        QString name(){
                return _data;
            }
        void setName(QString str){
                if(str!=_data){
                    _data=str;
                    nameChanged();
                }
            }
        Q_INVOKABLE void press();
          Q_INVOKABLE void press1();

signals:
 void nameChanged();

};

#endif // WORKING_H
