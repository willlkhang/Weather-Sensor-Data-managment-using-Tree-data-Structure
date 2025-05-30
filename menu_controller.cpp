#include "menu_controller.h"

void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType& sensorData) {
	int y = inputYear();
	int m = inputMonth();
	outputSPEEDtoCMDprocessing(sensorData, m, y);
}

void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType& sensorData) {
	int y = inputYear();
	outputTEMPtoCMDprocessing(sensorData, y);
}

void S_T_R_SPCC_Combination(SensorlogType& sensorData) {
	int m = inputMonth();
	outputToCMDforS_T_R_SPCC_CombinationProcessing(sensorData, m);
}

void AnnualSensorReportToCSV(SensorlogType& sensorData) {
	int y = inputYear();

	try {
		if (!sensorData.findValue(y)) {
			throw std::runtime_error("No Data found for the year from the data source\nPlease check again\n");
		}

		outputWholeDATAtoCMDprocessing(sensorData, y);
		outputWholeDATAtoCSVprocessing("WindTempSolar.csv", sensorData, y);
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
}
