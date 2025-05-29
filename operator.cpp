#include "operator.h"

//----------date
bool operator<(const Date& here, const Date& there) {
    if (here.GetYear() != there.GetYear()) return here.GetYear() < there.GetYear();
    if (here.GetMonth() != there.GetMonth()) return here.GetMonth() < there.GetMonth();
    return here.GetDay() < there.GetDay();
}

bool operator>(const Date& here, const Date& there) {
    return here < there;
}

bool operator==(const Date& here, const Date& there) {
    return here.GetYear() == there.GetYear() &&
    here.GetMonth() == there.GetMonth() && here.GetDay() == there.GetDay();
}


//--------------------time
bool operator<(const Time& here, const Time& there) {
    if(here.GetHour() != there.GetHour()) return here.GetHour() < there.GetHour();
    return here.GetMinute() < there.GetMinute();
}
bool operator>(const Time& here, const Time& there) {
    return there < here;
}

bool operator==(const Time& here, const Time& there) {
    return ((here.GetHour() == there.GetHour()) && (here.GetMinute() == there.GetMinute()));
}


//--------------------data structure sensor
bool operator<(const SensorRecType& here, const SensorRecType& there) {
	if (here.d < there.d) return true;
	if (here.d > there.d) return false;
	return (here.t < there.t);
}

bool operator>(const SensorRecType& here, const SensorRecType& there) {
	if (here.d > there.d) return true;
	if (here.d < there.d) return false;
	return (here.t > there.t);
}

bool operator==(const SensorRecType& here, const SensorRecType& there) {
	return ((here.d == there.d) && (here.t == there.t));
}
