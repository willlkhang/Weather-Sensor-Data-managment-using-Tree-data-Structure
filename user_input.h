// user_input.h


//---------------------------------------------------------------------------------

#ifndef USER_INPUT_H_INCLUDED
#define USER_INPUT_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "user_input_validator.h"

//---------------------------------------------------------------------------------
	/**
	 * @brief Prompts and validates user input for a month
	 *
	 * Reads a month number from the console, ensuring it is a valid integer between
	 * 1 and 12.
	 * Repeats the prompt until valid input is provided.
	 *
	 * @return int - The validated month (1-12)
	 * @pre Console input must be available
	 * @post Returns a valid month number
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Handle std::cin failures and clear input buffer (e.g., using std::cin.ignore)
	 * @bug std::stoi may throw unhandled exceptions for invalid input
	 */
int inputMonth();

    /**
	 * @brief Prompts and validates user input for a year
	 *
	 * Reads a year from the console, ensuring it is a valid non-negative integer
	 * (0 to 999999).
	 * Repeats the prompt until valid input is provided.
	 *
	 * @return int - The validated year (0-999999)
	 * @pre Console input must be available
	 * @post Returns a valid year
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Handle std::cin failures and clear input buffer (e.g., using std::cin.ignore)
	 * @bug std::stoi may throw unhandled exceptions for invalid input
	 */
int inputYear();

    /**
	 * @brief Prompts and validates user input for a menu option
	 *
	 * Reads a menu option from the console, ensuring it is a valid integer between
	 * 1 and 5 (menu range)
	 * Repeats the prompt until valid input is provided.
	 *
	 * @return int - The validated menu option (1-5)
	 * @pre Console input must be available
	 * @post Returns a valid menu option
	 * @throw None
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 * @date 2025-04-25 Minh Khang Nguyen, Started
	 *
	 * @todo Handle std::cin failures and clear input buffer (e.g., using std::cin.ignore)
	 * @bug std::stoi may throw unhandled exceptions for invalid input
	 */
int inputOption();

#endif // USER_INPUT_H
