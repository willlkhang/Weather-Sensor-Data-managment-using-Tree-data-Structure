#include "menu_controller.h"

void SPEEDAvgVsStdDeviForSPECMonthvsYear(SensorlogType& sensorData) {
	int y = inputYear();
	int m = inputMonth();

	try {
		if (!sensorData.at(y).findValue(m)) {
			throw std::runtime_error("No Data found for the specific month of the year from the data source\nPlease check again\n");
		}
		outputSPEEDtoCMDprocessing(sensorData, m, y);
	}
	catch (std::out_of_range& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
}

void TEMPAvgVsStdDeviForEACHMonthvsYear(SensorlogType& sensorData) {
	int y = inputYear();
	
	try {
		if (!sensorData.findValue(y)) {
			throw std::runtime_error("No Data found for the specific year from the data source\nPlease check again\n");
		}
		outputTEMPtoCMDprocessing(sensorData, y);
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
}

void S_T_R_SPCC_Combination(SensorlogType& sensorData) {
	int m = inputMonth();

	try {
		outputToCMDforS_T_R_SPCC_CombinationProcessing(sensorData, m);
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error: --> " << e.what() << "\n";
	}
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
