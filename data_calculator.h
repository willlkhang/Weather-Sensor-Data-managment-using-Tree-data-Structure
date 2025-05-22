// data_calculator.h

//---------------------------------------------------------------------------------

#ifndef DATA_CALCULATOR_H_INCLUDED
#define DATA_CALCULATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include "math.h"
#include "io_operator.h"
#include "data_match.h"
#include "data_structure_enumeration.h"


double calSum(const Vector<SensorRecType>& data, SensorDataField type);

double calSumForSolar(const Vector<SensorRecType>& data, SensorDataField type);

double calAvg(const Vector<SensorRecType>& data, SensorDataField type);

double calStardDeviation(const Vector<SensorRecType>& data, double &mean, SensorDataField type);

double calsPCC(const Vector<SensorRecType>& data, SensorDataField type1, SensorDataField type2);

double calMAD(const Vector<SensorRecType>& data, SensorDataField type);

#endif // DATA_CALCULATOR _H
