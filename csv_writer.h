//---------------------------------------------------------------------------------

#ifndef CSV_WRITER_H
#define CSV_WRITER_H

//---------------------------------------------------------------------------------

#include <iostream>
#include "data_structure.h"

//---------------------------------------------------------------------------------

	/**
	 * @brief Writes the header for the annual CSV report
	 *
	 * Outputs the column headers for year, month, and sensor statistics
	 * including average wind speed, ambient temperature, and solar radiation.
	 *
	 * @param outFile The output file stream to write to
	 * @param year The year of the data being written
	 * @return void
	 * @pre outFile must be open and valid
	 * @post Writes the CSV header row including the year
	 */
void writeDataHeaderToCSV(std::ofstream& outFile, const int year);

	/**
	 * @brief Writes a line of processed sensor data to the CSV
	 *
	 * Each line includes a month's name and corresponding average values
	 * with standard deviation and MAD for wind speed and temperature,
	 * as well as the solar radiation sum.
	 *
	 * @param outFile The output stream to write the data to
	 * @param SPEEDavg The average wind speed for the month
	 * @param SPEEDstddvi The standard deviation of wind speed
	 * @param SPEEDmad The MAD (median absolute deviation) of wind speed
	 * @param TEMPavg The average ambient temperature for the month
	 * @param TEMPstddvi The standard deviation of temperature
	 * @param TEMPmad The MAD (median absolute deviation) of temperature
	 * @param SRsum The total solar radiation for the month (kWh/m^2)
	 * @param month The numeric index of the month (1–12)
	 * @return void
	 * @pre outFile must be open and valid
	 * @post Appends a formatted row to the CSV file
	 */
void writeWholeDataToCSV(std::ostream& outFile, double SPEEDavg, double SPEEDstddvi,
	double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month);

#endif // CSV_WRITER_H
