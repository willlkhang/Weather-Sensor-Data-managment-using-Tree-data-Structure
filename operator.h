#ifndef OPERATOR_H
#define OPERATOR_H

#include "date.h"
#include "time.h"
#include "data_calculator.h"


//-----------[date operator]-------------
bool operator<(const Date& here, const Date& there);
bool operator>(const Date& here, const Date& there);
bool operator==(const Date& here, const Date& there);


//------------time
bool operator>(const Time& here, const Time& there);
bool operator<(const Time& here, const Time& there);
bool operator==(const Time& here, const Time& there);


//----------------sensor data structure
bool operator<(const SensorRecType& here, const SensorRecType& there);
bool operator>(const SensorRecType& here, const SensorRecType& there);
bool operator==(const SensorRecType& here, const SensorRecType& there);


#endif // OPERATOR_H
