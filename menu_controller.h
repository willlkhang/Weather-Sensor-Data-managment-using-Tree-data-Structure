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

/**
 * @file menu_controller.h
 * @brief Provides user-driven menu function handlers to interact with sensor data.
 *
 * This header declares high-level controller functions for handling various menu options,
 * such as computing average speed/temperature, SPCC analysis, and exporting annual reports.
 *
 * @author Minh Khang Nguyen
 * @version 01
 * @date 2025-05-30
 */

 /**
  * @brief Computes and displays average speed and standard deviation
  *
  * Prompts the user for a year and month, then outputs wind speed statistics to console.
  *
  * @param sensor_data Sensor dataset containing speed values
  * @return void
  * @pre sensor_data must be populated
  */
void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType& sensor_data);

/**
 * @brief Computes and displays average temperature and standard deviation for each month of a specific year
 *
 * Prompts the user for a year, then processes and displays temperature statistics for all 12 months.
 *
 * @param sensor_data Sensor dataset containing temperature values
 * @return void
 * @pre sensor_data must be populated
 */
void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType& sensor_data);

/**
* @brief Computes and displays sample Pearson correlation coefficients (SPCC)
*
* Prompts the user for a month and calculates SPCC between temperature, speed, and solar radiation.
*
* @param sensorData Sensor dataset containing numeric values
* @return void
* @pre sensorData must be valid and cover the required time period
*/
void S_T_R_SPCC_Combination(SensorlogType& sensorData);

/**
* @brief Generates an annual sensor data report and exports to CSV
*
* Prompts the user for a year and attempts to output corresponding sensor data summary to both
* console and a file named "WindTempSolar.csv".
*
* @param sensor_data Sensor dataset containing wind, temperature, and radiation readings
* @return void
* @pre sensor_data must contain data for the specified year
*/
void AnnualSensorReportToCSV(SensorlogType& sensor_data);

#endif
