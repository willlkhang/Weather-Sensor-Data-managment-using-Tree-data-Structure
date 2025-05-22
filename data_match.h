// data_match.h
//---------------------------------------------------------------------------------

#ifndef DATA_MATCH_H_INCLUDED
#define DATA_MATCH_H_INCLUDED

//---------------------------------------------------------------------------------

#include "date.h"
#include "data_structure.h"
#include "DataExtractor.h"
#include "data_structure_enumeration.h"

Vector<double> dataFieldFilter(const Vector<SensorRecType>& data, const SensorDataField type);
void dataFilter(SensorlogType1& sensor_data, SensorlogType& newData, const int month, const int year);


#endif // DATA_MATCH_H