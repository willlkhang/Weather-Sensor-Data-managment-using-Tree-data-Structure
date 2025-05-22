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

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}

//----------------------------------------------------------------------------

bool Date::operator==(const Date& other) const {
    return year == other.year && month == other.month && day == other.day;
}
