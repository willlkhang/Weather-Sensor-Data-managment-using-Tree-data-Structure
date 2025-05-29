// menu_operator.h


//---------------------------------------------------------------------------------

#ifndef MENU_OPERATOR_H_INCLUDED
#define MENU_OPERATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>

#include "data_match.h"
#include "user_input.h"
#include "menu_operator.h"
#include "data_calculator.h"
#include "data_structure.h"

//---------------------------------------------------------------------------------

void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType& sensor_data);

void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType& sensor_data);

void S_T_R_SPCC_Combination(SensorlogType& sensorData);

//void TotalSolarRadiationKwhm2ForEACHMonthvsYear(SensorlogType1& sensor_data);

void AnnualSensorReportToCSV(SensorlogType& sensor_data);

#endif
