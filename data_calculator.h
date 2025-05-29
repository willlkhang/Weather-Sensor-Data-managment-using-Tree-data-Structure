// data_calculator.h

//---------------------------------------------------------------------------------

#ifndef DATA_CALCULATOR_H_INCLUDED
#define DATA_CALCULATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include "math.h"
#include "io_operator.h"
#include "data_match.h"
#include "data_structure_enumeration.h"


double generalSumCalculation(const Vector<SensorRecType>& data, SensorDataField type);

double SumForSolarCalculation(const Vector<SensorRecType>& data, SensorDataField type);

double generalAvgCalculation(const Vector<SensorRecType>& data, SensorDataField type);

double generalStardDeviationCalculation(const Vector<SensorRecType>& data, double &mean, SensorDataField type);

double generalsPCCcalculation(const Vector<SensorRecType>& data, SensorDataField type1, SensorDataField type2);

double generalMADCalculation(const Vector<SensorRecType>& data, SensorDataField type);

#endif // DATA_CALCULATOR _H
