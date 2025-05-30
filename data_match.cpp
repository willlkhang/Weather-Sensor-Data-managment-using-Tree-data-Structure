#include "data_match.h"

Vector<double> dataFieldFilter(const Vector<SensorRecType>& data, const SensorDataField type) {
    Vector<double> extractedCol;

    for (int i = 0; i < data.size(); ++i) {
        switch (type) {
        case S:
            extractedCol.add_to_back(data[i].speed);
            break;
        case S_XTR:
            extractedCol.add_to_back((data[i].speed) * SPEEDconvertRate);
            break;
        case SR:
            extractedCol.add_to_back(data[i].solarRadiation);
            break;
        case SR_XTR:
            extractedCol.add_to_back((data[i].solarRadiation) * SOLARconvertRate);
            break;
        case T:
            extractedCol.add_to_back(data[i].temperature);
            break;
        default:
            std::cout << "No matched entered data field.\n\n";
        }
    }

    return extractedCol;
}

void dataFilter(const SensorlogType& sensorData, SensorlogTypeVector&newData,const int month = -1, const int year = -1) {
	Vector<SensorRecType> tmpVec;
	if (year != -1 && month != -1) {
		sensorData[year][month].inOrder(DataExtractor<SensorRecType>::extractData);
	}
	else if (year != -1 && month == -1) {
		for (int i = 0; i < sensorData[year].size(); i++) {
			sensorData[year][i].inOrder(DataExtractor<SensorRecType>::extractData);
		}
	}
    else if (year == -1 && month != -1) {
        for (int i = 0; i < sensorData.size(); i++) {
            sensorData[i][month].inOrder(DataExtractor<SensorRecType>::extractData);
        }
    }

	newData = DataExtractor<SensorRecType>::getExtractedData();

	DataExtractor<SensorRecType>::clearExtractedData();
}
