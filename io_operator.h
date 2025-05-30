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
