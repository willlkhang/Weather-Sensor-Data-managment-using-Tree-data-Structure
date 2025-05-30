// data_calculator.h

//---------------------------------------------------------------------------------

#ifndef DATA_CALCULATOR_H_INCLUDED
#define DATA_CALCULATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include "math.h"
#include "io_operator.h"
#include "data_match.h"
#include "data_structure_enumeration.h"

	/**
	 * @brief Calculates the sum of values in a given sensor field
	 *
	 * Extracts values of the specified sensor data field and computes the total sum.
	 *
	 * @param data The sensor data vector
	 * @param type The field to extract (e.g., S_XTR, SR)
	 * @return double - Sum of all extracted values
	 * @pre Data vector must be initialized and non-empty
	 * @post Returns 0.0 if no valid data found
	 */
double generalSumCalculation(const Vector<SensorRecType>& data, SensorDataField type);
	

	/**
	 * @brief Calculates the total solar radiation above the minimum threshold
	 * 
	 * Filters solar radiation values that are at least 100.0 W/m² before applying the
	 * conversion factor to compute the total.
	 * 
	 * @param data The vector of sensor records
	 * @param type The solar radiation field type (e.g., SR_XTR)
	 * @return double - Sum of solar radiation values meeting the threshold
	 * @pre Field type must be solar-related
	 * @post Returns 0.0 if no values pass the threshold
	 */
double SumForSolarCalculation(const Vector<SensorRecType>& data, SensorDataField type);
	
	/**
	 * @brief Calculates the average of values in a given sensor field
	 * 
	 * Extracts the selected data field and computes the mean of the values.
	 * 
	 * @param data The vector of sensor records
	 * @param type The field to extract (e.g., T, S_XTR)
	 * @return double - Average of extracted values
	 * @pre Vector must be initialized
	 * @post Returns 0.0 if vector is empty
	 */
double generalAvgCalculation(const Vector<SensorRecType>& data, SensorDataField type);

	/**
	 * @brief Calculates the standard deviation based on a given mean
	 *
	 * Computes the sample standard deviation using a provided mean value and extracted data field.
	 *
	 * @param data The sensor data vector
	 * @param mean The precomputed mean value to use
	 * @param type The field to extract for standard deviation calculation
	 * @return double - Standard deviation of the field values
	 * @pre Vector must have at least two elements
	 * @post Returns 0.0 if vector is empty
	 */
double generalStardDeviationCalculation(const Vector<SensorRecType>& data, double &mean, SensorDataField type);
	
	/**
	 * @brief Computes the sample Pearson Correlation Coefficient (sPCC)
	 * 
	 * Calculates correlation between two specified fields extracted from sensor data.
	 * 
	 * @param data The vector of sensor records
	 * @param type1 The first data field (e.g., S_XTR)
	 * @param type2 The second data field (e.g., T)
	 * @return double - The computed correlation coefficient
	 * @pre Data fields must be valid and of equal length
	 * @post Returns a value between -1 and 1 representing the correlation
	 */
double generalsPCCcalculation(const Vector<SensorRecType>& data, SensorDataField type1, SensorDataField type2);

	/**
	 * @brief Calculates the Median Absolute Deviation (MAD) for a sensor field
	 * 
	 * Extracts values of the given field and computes the MAD, a robust measure of variability.
	 * 
	 * @param data The vector of sensor records
	 * @param type The data field to compute MAD on (e.g., S_XTR)
	 * @return double - The MAD of the field values
	 * @pre Vector must be initialized
	 * @post Returns 0.0 if vector is empty
	 */
double generalMADCalculation(const Vector<SensorRecType>& data, SensorDataField type);

#endif // DATA_CALCULATOR _H
