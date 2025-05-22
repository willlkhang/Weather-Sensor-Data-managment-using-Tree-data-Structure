// data_structure_enumeration.h

//---------------------------------------------------------------------------------

#ifndef DATA_STRUCTURE_ENUMERATION_H_INCLUDED
#define DATA_STRUCTURE_ENUMERATION_H_INCLUDED

//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------

	/**
	 * @enum SensorDataField
	 * @brief Defines fields for sensor data extraction
	 *
	 * Specifies the types of data fields that can be extracted from a sensor log,
	 * such as wind speed, converted speed, solar radiation, and temperature.
	 * Used by data calculation functions to select specific fields.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Move enum to data_structure.h to avoid circular include
	 * @bug Circular include with data_calculator.h may cause compilation issues
	 */
	enum SensorDataField {
		S,      /** Wind speed in m/s */
		S_XTR,  /**Wind speed converted to km/h */
		SR,     /** Solar radiation */
		SR_XTR, /** Solar radiation to kwh/m2*/
		T       /**Temperature */
	};

#endif // DATA_STRUCTURE_ENUMERATION_H_INCLUDED
