#include "DataExtractor.h"

Vector<SensorRecType> DataExtractor::data;

const Vector<SensorRecType>& DataExtractor::getExtractedData(){
	return data;
}

void DataExtractor::clearExtractedData() {
	data = Vector<SensorRecType>();
}

void DataExtractor::extractData(SensorRecType& target) {
	data.add_to_back(target);
}