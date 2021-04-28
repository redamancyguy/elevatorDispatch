#include "elevatordata.h"

ElevatorData::ElevatorData(QObject *parent) : QObject(parent) {
  _floor = 1;
  for (int i = 0; i < 21; ++i) {
    _list.append(0);
  }
}
