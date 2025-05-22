// io_operator.h

//---------------------------------------------------------------------------------

#ifndef IO_OPERATOR_H_INCLUDED
#define IO_OPERATOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "date.h"
#include "time.h"
#include "data_structure.h"

//---------------------------------------------------------------------------------

	/**
	 * @brief Reads a Date object from an input stream
	 *
	 * Parses a date from the input stream in the format "day/month/year" (e.g., "15/01/2025")
	 * Updates the Date object with the parsed values.
	 *
	 * @param input The input stream to read from
	 * @param D The Date object to populate
	 * @return std::istream& - The modified input stream
	 * @pre input must contain a valid date in "day/month/year" format
	 * @post D is updated with parsed day, month, and year
	 * @throw std::istream::failure If the input format is invalid
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add robust validation for input format and value ranges
	 * @bug No handling for invalid month or day values
	 */
std::istream& operator>>(std::istream& input, Date& D);

    /**
     * @brief Overloads the output stream operator to display a Date object.
     * @param os Reference to the output stream.
     * @param D Constant reference to the Date object to be displayed.
     * @return Reference to the modified output stream.
     */
std::ostream& operator<<(std::ostream& os, const Date& D);

    /**
     * @brief Overloads the output stream operator to display a Date object.
     * @param os Reference to the output stream.
     * @param T Constant reference to the Time object to be displayed.
     * @return Reference to the modified output stream.
     */
std::ostream& operator<<(std::ostream& os, const Time& T);


#endif // DATE_HELPER_H_INCLUDED
