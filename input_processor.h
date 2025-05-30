// input_processor.h

//---------------------------------------------------------------------------------

#ifndef INPUT_PROCESSOR_H_INCLUDED
#define INPUT_PROCESSOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include "data_structure.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "file_reader.h"
#include "operator.h"

//---------------------------------------------------------------------------------

/**
 * @file input_processor.h
 * @brief Provides functions to read and convert raw CSV files into structured sensor records.
 *
 * This module contains utility functions to handle file input, parse header and rows,
 * extract fields such as date, time, speed, solar radiation, and temperature,
 * and populate the sensor data structure.
 *
 * @author Minh Khang Nguyen
 * @version 01
 */

 /**
  * @brief Loads a CSV file into the sensor log data structure
  *
  * Opens and reads the specified CSV file, and processes its content into structured data.
  *
  * @param sensorData Reference to the main data structure that holds all records
  * @param csvName Name of the CSV file to read (with relative path)
  * @pre The file must be present in the 'data' directory
  * @post sensorData will contain valid records parsed from file
  */
void loadCSV(SensorlogType& sensorData, std::string csvName);

/**
 * @brief Processes CSV input stream and stores into sensorData
 *
 * Reads CSV content from an input stream, extracts header and each row, converts it
 * to a SensorRecType and inserts into the correct month-year position in sensorData.
 *
 * @param sensorData Main data structure to populate
 * @param inFile Input stream to process (e.g., from opened CSV file)
 * @post sensorData is updated with accepted rows
 */
void processCSVtoSensorData(SensorlogType& sensorData, std::istream& inFile);

/**
 * @brief Prints summary of accepted and denied lines
 *
 * Provides feedback after CSV upload processing, showing how many lines were accepted
 * and how many were rejected.
 *
 * @param acceptedLine Number of accepted records
 * @param deniedLine Number of rejected records
 * @post Summary is printed to standard output
 */
void fileUploadinglogSummary(int acceptedLine, int deniedLine);


/**
 * @brief Reads and extracts the header line from CSV file
 *
 * Parses the first line from input stream as column headers and stores each
 * column label into a Vector.
 *
 * @param input Input stream with the header line
 * @return Vector of column labels
 * @throws std::runtime_error if the header line cannot be read
 */
Vector<std::string> readHeader(std::istream& input);

/**
* @brief Converts a CSV row and its header into a structured SensorRecType
*
* Matches values in a row with header labels to extract relevant fields such
* as date, time, speed, solar radiation, and temperature.
*
* @param row Vector of values in the row
* @param header Vector of header strings
* @return A SensorRecType object populated from the row
*/
SensorRecType rowExtraction(const Vector<std::string>& row, const Vector<std::string>& header);

/**
 * @brief Parses a full date-time field and updates Date and Time objects
 *
 * Splits a combined datetime string into its date and time parts and parses them.
 *
 * @param date Date object to populate
 * @param time Time object to populate
 * @param field Raw datetime string from CSV
 * @post date and time are updated
 */
void readDateTime(Date& date, Time& time, const std::string& field);

/**
* @brief Parses time from a string and updates a Time object
*
* Extracts hours and minutes from time-formatted string.
*
* @param data String containing time (e.g., "15:20")
* @param time Reference to Time object to set
* @post time is updated
*/
void readTime(std::string& data, Time& time);

/**
* @brief Parses date from a string and updates a Date object
*
* Extracts day, month, and year from date-formatted string.
*
* @param data String containing date (e.g., "05/03/2021")
* @param date Reference to Date object to set
* @post date is updated
*/
void readDate(std::string& data, Date& date);

/**
* @brief Finds the index of a column by name in the header
*
* Searches for a target column name in the header and returns its index.
*
* @param data Vector of header column names
* @param target Column name to search for
* @return Index of the target column if found, otherwise -1
*/
int getColIndex(const Vector<std::string>& data, const std::string& target);

#endif// INPUT_PROCESSOR_H_INCLUDED
