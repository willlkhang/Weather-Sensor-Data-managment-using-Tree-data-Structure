#ifndef OPERATOR_H
#define OPERATOR_H

#include "date.h"
#include "time.h"
#include "data_calculator.h"

/**
 * @file operator.h
 * @brief Defines overloaded relational operators for Date, Time, and SensorRecType classes
 *
 * This header provides custom comparison operators for key domain structures (`Date`, `Time`,
 * and `SensorRecType`). These operators are used for sorting, equality checks, and
 * time-series data comparison.
 *
 * @author Minh Khang Nguyen
 * @version 01
 * @date 2025-05-30
 */

//-----------[date operator]-------------

/**
 * @brief Less-than operator for Date
 *
 * Compares two dates chronologically by year, month, and day.
 *
 * @param here First date
 * @param there Second date
 * @return true if 'here' is earlier than 'there'
 */
bool operator<(const Date& here, const Date& there);

/**
 * @brief Greater-than operator for Date
 *
 * Equivalent to operator< with reversed operands.
 *
 * @param here First date
 * @param there Second date
 * @return true if 'here' is later than 'there'
 */
bool operator>(const Date& here, const Date& there);

/**
* @brief Equality operator for Date
*
* Checks if two Date objects have the same year, month, and day.
*
* @param here First date
* @param there Second date
* @return true if dates are equal
*/
bool operator==(const Date& here, const Date& there);


//------------time

/**
 * @brief Greater-than operator for Time
 *
 * Compares two time objects based on hour and minute.
 *
 * @param here First time
 * @param there Second time
 * @return true if 'here' is later than 'there'
 */
bool operator>(const Time& here, const Time& there);

/**
 * @brief Less-than operator for Time
 *
 * Compares two time objects based on hour and minute.
 *
 * @param here First time
 * @param there Second time
 * @return true if 'here' is earlier than 'there'
 */
bool operator<(const Time& here, const Time& there);

/**
* @brief Equality operator for Time
*
* Checks whether two time values are equal.
*
* @param here First time
* @param there Second time
* @return true if hours and minutes are equal
*/
bool operator==(const Time& here, const Time& there);


//----------------sensor data structure


/**
 * @brief Less-than operator for SensorRecType
 *
 * First compares by date, then time if dates are equal.
 *
 * @param here First sensor record
 * @param there Second sensor record
 * @return true if 'here' is earlier
 */
bool operator<(const SensorRecType& here, const SensorRecType& there);

/**
 * @brief Greater-than operator for SensorRecType
 *
 * First compares by date, then time if dates are equal.
 *
 * @param here First sensor record
 * @param there Second sensor record
 * @return true if 'here' is later
 */
bool operator>(const SensorRecType& here, const SensorRecType& there);

/**
* @brief Equality operator for SensorRecType
*
* Checks if both the date and time fields of two sensor records are equal.
*
* @param here First sensor record
* @param there Second sensor record
* @return true if both records represent the same timestamp
*/
bool operator==(const SensorRecType& here, const SensorRecType& there);


#endif // OPERATOR_H
