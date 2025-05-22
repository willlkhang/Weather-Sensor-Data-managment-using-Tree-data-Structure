#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "vector.h"
#include "data_structure.h"

class DataExtractor {
public:

	static void extractData(SensorRecType& target);

	static const Vector<SensorRecType>& getExtractedData();

	static void clearExtractedData();

private:
	static Vector<SensorRecType> data;
};

#endif 