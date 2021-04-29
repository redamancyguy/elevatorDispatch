#ifndef WORKING_H
#define WORKING_H

#include <QDebug>
#include <QObject>
#include <QTimer>

#include "Dispatch.h"
#include "Person.h"
#include "elevatordata.h"

class Working : public QObject
{
Q_OBJECT
	Dispatch data;
public:
	explicit Working(QObject* parent = nullptr);
	QString peopleup[21];
	QString peopledown[21];

	QList<ElevatorData*> elevatorDataList;
public slots:
	void Flush();
};

#endif  // WORKING_H
