//---------------------------------------------------------------------------------

#ifndef FILE_READER_H
#define FILE_READER_H

//---------------------------------------------------------------------------------

#include "data_structure.h"
#include "input_processor.h"

//---------------------------------------------------------------------------------

/**
 * @brief Loads and processes a list of sensor CSV file paths from a source file
 *
 * Reads the given file line by line to retrieve names of individual CSV files, then delegates
 * their loading to `loadCSV` to populate the provided sensor data structure.
 *
 * @param sensorData A reference to the SensorlogType data structure to be filled
 * @param fileName The path to the source file containing a list of CSV filenames
 * @throws std::runtime_error if the source file cannot be opened
 * @pre The file must exist and contain valid CSV filenames, one per line
 * @post The sensorData structure is populated with all records from the listed CSV files
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
void loadSource(SensorlogType& sensorData, std::string fileName);

//---------------------------------------------------------------------------------

#endif // FILE_READER_H
