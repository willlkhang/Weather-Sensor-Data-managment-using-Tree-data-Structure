// data_match.h
//---------------------------------------------------------------------------------

#ifndef DATA_MATCH_H_INCLUDED
#define DATA_MATCH_H_INCLUDED

//---------------------------------------------------------------------------------

#include "date.h"
#include "data_structure.h"
#include "DataExtractor.h"
#include "data_structure_enumeration.h"

	/**
	 * @brief Extracts a specified data field from sensor records
	 *
	 * Filters and returns a vector of values from the input sensor records based on
	 * the specified field type (e.g., speed, solar radiation, temperature).
	 * Converts values if necessary based on field enumeration (e.g., S_XTR or SR_XTR).
	 *
	 * @param data The vector of sensor records
	 * @param type The sensor data field to extract
	 * @return Vector<double> - Vector containing the extracted field values
	 * @pre Data must contain valid sensor records
	 * @post Returns an empty vector if no match found
	 * @bug Prints message to std::cout for unmatched fields (should throw exception or log)
	 */
Vector<double> dataFieldFilter(const Vector<SensorRecType>& data, const SensorDataField type);
	
	/**
	 * @brief Filters sensor records by date
	 *
	 * Extracts sensor data based on year and/or month parameters. Supports partial filtering:
	 * - If both year and month are provided, returns data for that specific month.
	 * - If only year is provided, returns data for all months of that year.
	 * - If only month is provided, returns data for that month across all years.
	 *
	 * Uses in-order traversal to extract data into a flat vector.
	 *
	 * @param sensor_data The full dataset organized as a 2D Red-Black Tree by year and month
	 * @param newData The output vector containing filtered sensor records
	 * @param month The month to filter (1–12) or -1 for all months
	 * @param year The year to filter or -1 for all years
	 * @return void
	 * @pre sensor_data must be loaded and valid
	 * @post newData contains extracted records; internal extractor buffer is cleared
	 */
void dataFilter(const SensorlogType& sensor_data, SensorlogTypeVector& newData, const int month, const int year);


#endif // DATA_MATCH_H