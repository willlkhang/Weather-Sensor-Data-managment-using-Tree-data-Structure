// user_input_validator.h


//---------------------------------------------------------------------------------

#ifndef USER_INPUT_VALIDATOR_H_INCLUDED
#define USER_INPUT_VALIDATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <string>
#include <cctype>

#include "data_structure.h"

//---------------------------------------------------------------------------------
	/**
	 * @brief Checks if a string contains only digits
	 *
	 * Validates that the input string is non-empty and consists only of digit characters.
	 * Returns false for empty strings or strings with non-digit characters.
	 *
	 * @param str The string to validate
	 * @return bool - True if the string contains only digits, false otherwise
	 * @pre None
	 * @post Returns true only for non-empty strings with digits
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Support negative numbers or leading zeros
	 */
bool isNumber(const std::string str);

    /**
	 * @brief Validates a month number
	 *
	 * Checks if the input month is between 1 and the number of months (12).
	 * Uses monthNum from data_structure.h for the upper bound.
	 *
	 * @param m The month number to validate
	 * @return bool - True if the month is valid (1-12), false otherwise
	 * @pre None
	 * @post Returns true only for months in range 1-12
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
bool isValidMonth(const int m);

    /**
	 * @brief Validates a year
	 *
	 * Checks if the input year is between 0 and 999999.
	 *
	 * @param y The year to validate
	 * @return bool - True if the year is valid (0-999999), false otherwise
	 * @pre None
	 * @post Returns true only for years in range 0-999999
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @bug Upper bound of 999999 may be overly permissive
	 */
bool isValidYear(const int y);

    /**
	 * @brief Validates a menu option
	 *
	 * Checks if the input option is between 1 and the number of menu items (5).
	 * Uses menuItem from data_structure.h for the upper bound.
	 *
	 * @param c The menu option to validate
	 * @return bool - True if the option is valid (1-5), false otherwise
	 * @pre None
	 * @post Returns true only for options in range 1-5
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 */
bool isInRangeMenu(const int c);

#endif // USER_INPUT_VALIDATOR_H
