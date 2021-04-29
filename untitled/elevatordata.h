#ifndef ELEVATORDATA_H
#define ELEVATORDATA_H

#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>
#include <QVariantList>

class ElevatorData : public QObject
{
Q_OBJECT
public:
	explicit ElevatorData(QObject* parent = nullptr);
	Q_PROPERTY(int floor READ floor WRITE setFloor NOTIFY floorChanged)
	Q_PROPERTY(
		int direction READ direction WRITE setDirection NOTIFY directionChanged)
	Q_PROPERTY(QVariantList list READ getList NOTIFY listChanged)

	Q_PROPERTY(
		int peopleNum READ peopleNum WRITE setPeopleNum NOTIFY peopleNumChanged)

	int peopleNum() const { return _peopleNum; }

	void setPeopleNum(int t);

	int floor() const { return _floor; }

	int direction() const { return _direction; }

	void setFloor(int t);

	void setDirection(int t);

	Q_INVOKABLE void increaseFloor() { setFloor(floor() + 1); }

	QVariantList getList() const { return _list; }

	Q_INVOKABLE void setValue(int i, int val);

	Q_INVOKABLE void increaseItem(int i);

public slots:
private:
	QVariantList _list;
	int _floor;
	int _direction;
	int _peopleNum;
signals:
	void listChanged();
	void floorChanged();
	void directionChanged();
	void peopleNumChanged();
	void fButton(int);
	void fButtonup(int);
	void fButtondown(int);
};

#endif  // ELEVATORDATA_H
