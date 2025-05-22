#include "menu_operator.h"

void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType1& sensorData) {
	int y = inputYear();
	int m = inputMonth();

	Vector<SensorRecType> newData;

	dataFilter(sensorData, newData, m, y);
	double avg = calAvg(newData, S_XTR);
	double stdev = calStardDeviation(newData, avg, S_XTR);

	outputSPEEDtoCMD(newData, avg, stdev);
}

void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType1& sensorData) {
	int y = inputYear();
	outputTEMPtoCMD(sensorData, y);
}

void S_T_R_SPCC_Combination(SensorlogType1& sensorData) {
	int m = inputMonth();
	outputToCMDforS_T_R_SPCC_Combination(sensorData, m);
}

void AnnualSensorReportToCSV(SensorlogType1& sensorData) {
	int y = inputYear();

	try {
		if (!sensorData.findValue(y)) {
			throw std::runtime_error("No Data found for the year from the data source\nPlease check again\n");
		}

		outputWholeDATAtoCMD(sensorData, y);
		outputWholeDATAtoCSV("WindTempSolar.csv", sensorData, y);
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
}
