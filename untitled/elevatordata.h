#ifndef ELEVATORDATA_H
#define ELEVATORDATA_H

#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>
#include <QVariantList>

class ElevatorData : public QObject {
  Q_OBJECT
 public:
  explicit ElevatorData(QObject *parent = nullptr);
  Q_PROPERTY(int floor READ floor WRITE setFloor NOTIFY floorChanged)
  Q_PROPERTY(
      int loadCount READ loadCount WRITE setLoadCount NOTIFY loadCountChanged)
  Q_PROPERTY(
      int direction READ direction WRITE setDirection NOTIFY directionChanged)
  Q_PROPERTY(QVariantList list READ getList NOTIFY listChanged)


    Q_PROPERTY(
        int peopleNum READ peopleNum WRITE setpeopleNum NOTIFY peopleNumChanged)



    int peopleNum() { return _peopleNum; }
    void setpeopleNum(int t) {
      if (t != _peopleNum) {
        _peopleNum = t;
        emit peopleNumChanged();
      }
    }

  int floor() { return _floor; }

  int direction() { return _direction; }
  int loadCount() { return _loadCount; }
  void setLoadCount(int t) {
    if (t != _loadCount) {
      _loadCount = t;
      emit loadCountChanged();
    }
  }
  void setFloor(int t) {
    if (t != _floor) {
      _floor = t;
      emit floorChanged();
    }
  }

  void setDirection(int t) {
    if (t != _direction) {
      _direction = t;
      emit directionChanged();
    }
  }

  Q_INVOKABLE void increaseFloor() { setFloor(floor() + 1); }




  QVariantList getList() const { return _list; }

  Q_INVOKABLE void setValue(int i, int val) {
    _list[i] = val;
    emit listChanged();
  }

  Q_INVOKABLE void increaseItem(int i) {
    _list[i] = _list[i].toInt() + 1;
    emit listChanged();
  }









 public slots:

 private:
  QVariantList _list;
  int _floor;
  int _direction;
  int _loadCount;
  int _peopleNum;
 signals:
  void listChanged();
  void floorChanged();
  void directionChanged();
  void loadCountChanged();
   void peopleNumChanged();
   void fButton(int);
};

#endif  // ELEVATORDATA_H
