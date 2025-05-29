#ifndef DATA_STRCTURE_H
#define DATA_STRCTURE_H

#include "data_structure.h"

////----------------------------------------------------------------------------

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