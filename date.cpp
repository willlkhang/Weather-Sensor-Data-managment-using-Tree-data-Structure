#include "date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::SetDay(int d) {
    day = d;
}
int Date::GetDay() const {
    return day;
}

void Date::SetMonth(int m) {
    month = m;
}
int Date::GetMonth() const {
    return month;
}

void Date::SetYear(int y) {
    year = y;
}
int Date::GetYear() const {
    return year;
}


