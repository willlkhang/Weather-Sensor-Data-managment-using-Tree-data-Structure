//---------------------------------------------------------------------------------

#ifndef DATA_PRINTER_H
#define DATA_PRINTER_H
//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>

#include "data_structure.h"

//---------------------------------------------------------------------------------

/**
 * @brief Displays the average wind speed and standard deviation for a specific month and year
 *
 * Prints the average wind speed and its standard deviation using the specified month and year.
 *
 * @param avg Average wind speed
 * @param stdev Sample standard deviation of wind speed
 * @param m Month (1–12)
 * @param y Year
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void displaySpeed(double avg, double stdev, int m, int y);

//---------------------------------------------------------------------------------

/**
 * @brief Displays the Pearson Correlation Coefficients (PCCs) for sensor data in a given month
 *
 * Shows correlation values between speed-temperature, speed-radiation, and temperature-radiation.
 *
 * @param S_T PCC between speed and temperature
 * @param S_R PCC between speed and solar radiation
 * @param T_R PCC between temperature and solar radiation
 * @param month The month (1–12) to display
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void displaySPCCforAllData(double S_T, double S_R, double T_R, int month);

//---------------------------------------------------------------------------------

/**
 * @brief Displays average temperature and its standard deviation
 *
 * Prints the ambient temperature average and deviation or a "No Data" message if values are zero.
 *
 * @param avg Average temperature
 * @param stddvi Standard deviation of temperature
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void displayTEMPdata(double avg, double stddvi);

//---------------------------------------------------------------------------------

/**
 * @brief Displays a CSV-style header line for yearly summary output
 *
 * Prints formatted column headers for average wind speed, temperature, and solar radiation.
 *
 * @param year The year being reported
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void displayHeaderForWholeData(int year);

/**
 * @brief Displays all monthly aggregated sensor values
 *
 * Outputs a summary line for one month, showing average wind speed, temperature,
 * and total solar radiation if any values are non-zero.
 *
 * @param SPEEDavg Average wind speed
 * @param SPEEDstddvi Standard deviation of wind speed
 * @param SPEEDmad Median absolute deviation of wind speed
 * @param TEMPavg Average temperature
 * @param TEMPstddvi Standard deviation of temperature
 * @param TEMPmad Median absolute deviation of temperature
 * @param SRsum Total solar radiation
 * @param month The month (1–12) being reported
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void displayAllWholeData(double SPEEDavg, double SPEEDstddvi, double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month);

#endif // DATA_PRINTER_H
