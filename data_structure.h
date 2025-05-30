//data_structure.h

//---------------------------------------------------------------------------------

#ifndef DATA_STRUCTURE_H_INCLUDED
#define DATA_STRUCTURE_H_INCLUDED

//---------------------------------------------------------------------------------

#include "date.h"
#include "time.h"
#include "vector.h"
#include <string>
#include "hashMap.h"
#include "RBTree.h"

//---------------------------------------------------------------------------------

	/**
	 * @brief Array of English month names
	 *
	 * Stores the full names of the 12 months for use in date formatting.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const std::string monthList[] = {"January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};


    /**
	 * @brief Number of months in a year
	 *
	 * Defines the total number of months (12) for use in date-related operations.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const int monthNum = 12;

    /**
	 * @brief Conversion rate from m/s to km/h
	 *
	 * Used to convert wind speed from meters per second to kilometers per hour (3.6).
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const double SPEEDconvertRate = 3.6; //m/s -> km/h

    /**
	 * @brief Conversion rate for solar radiation
	 *
	 * Used to convert solar radiation measurements (0.000167).
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const double SOLARconvertRate = 0.000167;

    /**
	 * @brief Minimum valid solar radiation value
	 *
	 * Defines the minimum threshold for solar radiation measurements (100.0).
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const double minSolarRadiation = 100.0;

    /**
	 * @brief Number of menu items
	 *
	 * Defines the number of items in a menu interface (5).
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
const int menuItem = 5;


    /**
	 * @struct SensorRecType
	 * @brief Represents a single sensor record entry
	 *
	 * Stores the date, time, wind speed (in m/s), solar radiation, and temperature
	 * of a single measurement.
	 * Used as the primary data structure for sensor log entries.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add validation for negative speed or temperature values
	 * @bug Uninitialized fields may cause undefined behavior if not set
	 */
 struct SensorRecType {
     /// Date of the measurement
    Date d;
    /// Time of the measurement
    Time t;
    /// Wind speed in meters per second
    double speed;
    /// Solar radiation measurement
    double solarRadiation;
    /// Temperature measurement
    double temperature;

        /**
		 * @brief Default constructor
		 *
		 * Initializes an empty sensor record with default values.
		 *
		 * @return void
		 * @post All fields are initialized to default values
		 */
    SensorRecType() : d(), t(), speed(0.0), solarRadiation(0.0), temperature(0.0) {}

        /**
		 * @brief Parameterized constructor
		 *
		 * Initializes a sensor record with provided date, time, speed, solar radiation, and temperature.
		 *
		 * @param date The date of the measurement
		 * @param time The time of the measurement
		 * @param s The wind speed in m/s
		 * @param sr The solar radiation measurement
		 * @param temp The temperature measurement
		 * @return void
		 * @pre Input values must be valid
		 * @post Fields are set to provided values
		 */
    SensorRecType(const Date &date, const Time &time, double s, double sr, double temp)
        : d(date), t(time), speed(s), solarRadiation(sr), temperature(temp) {}
};

 /**
  * @typedef SensorlogTypeVector
  * @brief A flat collection of sensor records
  *
  * Defines a Vector of SensorRecType to store entries from a sensor log (e.g., CSV file).
  * Used in temporary operations such as filtering or computing statistics.
  *
  * @author Minh Khang Nguyen
  * @version 01
  *
  * @todo Optimize memory usage for large logs
  * @bug Vector resizing may impact performance for large datasets
  */
typedef Vector<SensorRecType> SensorlogTypeVector;
	
/**
 * @typedef SensorlogType
 * @brief Hierarchical structure of sensor records by year and month
 *
 * Defines a HashMap of years, where each year maps to another HashMap of months,
 * which in turn maps to a Red-Black Tree of SensorRecType.
 *
 * This structure allows fast access and sorted traversal by date.
 *
 * @author Minh Khang Nguyen
 * @version 01
 */
typedef HashMap<int, HashMap<int, RBTree<SensorRecType>>> SensorlogType;

#endif // DATA_STRUCTURE_H_INCLUDED
