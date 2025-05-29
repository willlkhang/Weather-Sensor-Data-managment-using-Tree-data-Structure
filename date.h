// Date.h


//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>

//---------------------------------------------------------------------------------

	/**
	 * @class Date
	 * @brief Represents a date for sensor data records
	 *
	 * Stores a date with day, month, and year components, providing getter and setter
	 * methods for each.
	 * Used to timestamp sensor measurements in a sensor log.
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add validation for day, month, and year (1-12 for month)
	 * @bug Setters do not validate input values
	 */
class Date {
public:

	/**
	 * @brief Default constructor
	 *
	 * Initializes a Date object with default values (0 for day, month, year).
	 *
	 * @return void
	 * @post day, month, and year are set to 0
	 */
	Date();

	/**
	 * @brief Parameterized constructor
	 *
	 * Initializes a Date object with specified day, month, and year.
	 *
	 * @param d The day of the month
	 * @param m The month (1-12)
	 * @param y The year
	 * @return void
	 * @pre Input values should be valid (m in 1-12)
	 * @post day, month, and year are set to provided values

	 */
	Date(int d, int m, int y);

	/**
	 * @brief Sets the day of the month
	 *
	 * Updates the day component of the Date object.
	 *
	 * @param d The day to set
	 * @return void
	 * @pre Object must be initialized
	 * @post day is set to d
	 */
	void SetDay(int d);


	/**
	 * @brief Gets the day of the month
	 *
	 * Retrieves the day component of the Date object.
	 *
	 * @return int - The day of the month
	 * @pre Object must be initialized
	 * @post Returns the current day value
	 *
	 */
	int GetDay() const;

	/**
	 * @brief used for setting value of the private variable function acts as
	 * setter for accessing the value of the private
	 * @param m - int month
	 * @return void
	 * @pre object had been declared
	 * @post the value of m is passed
	 */
	void SetMonth(int m);

	/**
	 * @brief used for getting value of the private variable function acts as
	 * getter for accessing and retrieve the value of the private
	 * @param None
	 * @return string month
	 * @pre object had been declared
	 * @post the value of month is set
	 */
	int GetMonth() const;


	/**
	 * @brief used for setting value of the private variable function acts as
	 * setter for accessing the value of the private
	 * @param y - int year
	 * @return void
	 * @pre object had been declared
	 * @post the value of y is passed
	 */
	void SetYear(int y);

	/**
	 * @brief used for getting value of the private variable function acts as
	 * getter for accessing and rettrieve the value of the private
	 * @param None
	 * @return int year
	 * @pre object had been declared
	 * @post the value of year is set
	 */
	int GetYear() const;


private:
	/// Day of the month
	int day;
	/// Month of the year (1-12)
	int month;
	/// Year
	int year;

};

#endif // DATE_H
