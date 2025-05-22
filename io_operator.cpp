// Read date from input stream in the format "day/month/year"
#include "io_operator.h"

std::ostream & operator <<(std::ostream & os, const Date & D){
    os << D.GetDay() << monthList[D.GetMonth()-1]<< " " << D.GetYear();
    return os;
}

std::ostream & operator <<(std::ostream & os, const Time & T){
    os << "Time: " << std::setfill('0') << std::setw(2) << T.GetHour() << ":" << std::setfill('0') << std::setw(2) << T.GetMinute();

    return os;
}
