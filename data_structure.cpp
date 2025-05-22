#ifndef DATA_STRCTURE_H
#define DATA_STRCTURE_H

#include "data_structure.h"

////----------------------------------------------------------------------------
//
//// Greater than operator for WeatherRecord.
//bool operator>(const WeatherRecord& lhs, const WeatherRecord& rhs) {
//	if (lhs.date > rhs.date) return true;
//	if (lhs.date < rhs.date) return false;
//	return (lhs.time > rhs.time);
//}
//
////----------------------------------------------------------------------------
//
//// Equality operator for WeatherRecord.
//bool operator==(const WeatherRecord& lhs, const WeatherRecord& rhs) {
//	return lhs.date == rhs.date &&
//		lhs.time == rhs.time;
//}

//// Less than operator for WeatherRecord.
//bool operator<(const WeatherRecord& lhs, const WeatherRecord& rhs) {
//	if (lhs.date < rhs.date) return true;
//	if (lhs.date > rhs.date) return false;
//	return (lhs.time < rhs.time);
//}

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

#endif //DATA_STRCTURE_H