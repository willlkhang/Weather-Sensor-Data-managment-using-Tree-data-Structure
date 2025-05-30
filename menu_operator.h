// data_printer.h

//---------------------------------------------------------------------------------

#ifndef DATA_PRINTER_H_INCLUDED
#define DATA_PRINTER_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

#include "io_operator.h"
#include "data_calculator.h"
#include "data_match.h"
#include "data_structure.h"
#include "data_printer.h"
#include "csv_writer.h"

//---------------------------------------------------------------------------------
/**
 * @file data_printer.h
 * @brief Provides functions for outputting sensor analysis results to console and CSV
 *
 * This file defines functions that extract, calculate, and print sensor data
 * such as wind speed, temperature, solar radiation, and correlation statistics
 * to both the terminal and external CSV files.
 *
 * @author Minh Khang Nguyen
 * @version 01
 * @date 2025-05-30
 */

 /**
  * @brief Output wind speed average and standard deviation for a given month/year
  *
  * Filters sensor data by month and year, calculates average and standard deviation of wind speed,
  * and prints the result to console.
  *
  * @param sensorData The full sensor dataset
  * @param m The target month (1–12)
  * @param y The target year
  * @return void
  * @pre sensorData must include the specified year and month
  */
void outputSPEEDtoCMDprocessing(const SensorlogType& sensorData, int m, int y);

/**
 * @brief Outputs average temperature and standard deviation for each month of a specific year
 *
 * Filters sensor data by year and prints the monthly temperature statistics to console.
 *
 * @param wholeData The complete sensor dataset
 * @param year The target year
 * @return void
 * @pre wholeData must contain records for the specified year
 */
void outputTEMPtoCMDprocessing(const SensorlogType& wholeData, int year);

/**
* @brief Calculates and prints SPCC values between sensor metrics for a given month
*
* Calculates Pearson correlation coefficients between temperature, speed, and solar radiation
* for the specified month, printing the results to console.
*
* @param sensorData The sensor data used for correlation analysis
* @param month The month (1–12) to analyze
* @return void
* @pre sensorData should have valid data entries for the month
*/
void outputToCMDforS_T_R_SPCC_CombinationProcessing(const SensorlogType& sensorData, int month);

/**
* @brief Filters and retains only sensor data with acceptable solar radiation values
*
* Copies valid entries (solar radiation >= 100) from one dataset to another.
*
* @param data1 Input dataset
* @param data2 Output dataset (filtered)
* @return void
* @post data2 contains only rows from data1 where solarRadiation >= 100
*/
void skipRowContainingUnacceptableDataBaseOnSR(const SensorlogTypeVector& data1, SensorlogTypeVector& data2);

/**
 * @brief Displays annual sensor data summary for all 12 months to the console
 *
 * Aggregates wind speed, temperature, and solar radiation for each month of a given year,
 * and prints formatted results to the terminal.
 *
 * @param wholeData Complete sensor dataset
 * @param year The target year
 * @return void
 * @pre wholeData must include data for each month of the year
 */
void outputWholeDATAtoCMDprocessing(const SensorlogType& wholeData, int year);

/**
 * @brief Exports annual sensor statistics to a CSV file
 *
 * Writes computed statistics (wind speed, temperature, solar radiation) for each month
 * of a given year into a specified CSV file.
 *
 * @param name The name of the output CSV file
 * @param wholeData Complete sensor dataset
 * @param year The year to process
 * @return void
 * @pre wholeData must have valid entries for each month
 */
void outputWholeDATAtoCSVprocessing(std::string name, const SensorlogType& wholeData, int year);

/**
* @brief Writes formatted sensor statistics to CSV output stream
*
* Processes the data and exports monthly statistical summaries into the provided stream.
*
* @param outFile Output stream to write the CSV content
* @param wholeData Complete sensor dataset
* @param year The year to export
* @return void
* @pre outFile must be open and writable
*/
void outputToCSVprocessing(std::ofstream& outFile, const SensorlogType& wholeData, const int year);


#endif // DATA_PRINTER_H
