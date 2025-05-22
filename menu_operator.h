// menu_operator.h


//---------------------------------------------------------------------------------

#ifndef MENU_OPERATOR_H_INCLUDED
#define MENU_OPERATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>

#include "input_processor2.h"
#include "data_match.h"
#include "user_input.h"
#include "data_printer.h"
#include "data_calculator.h"
#include "data_structure.h"

//---------------------------------------------------------------------------------

void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType1& sensor_data);

void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType1& sensor_data);

void S_T_R_SPCC_Combination(SensorlogType1& sensorData);

//void TotalSolarRadiationKwhm2ForEACHMonthvsYear(SensorlogType1& sensor_data);

void AnnualSensorReportToCSV(SensorlogType1& sensor_data);

#endif
