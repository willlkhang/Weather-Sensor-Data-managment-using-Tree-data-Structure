#include "menu_operator.h"

void outputSPEEDtoCMDprocessing(const SensorlogType& sensorData, int m, int y) {
	try {
		if (!sensorData[y].findValue(m)) {
			throw std::runtime_error("No Data found for the specific month of the year from the data source\nPlease check again\n");
		}

		Vector<SensorRecType> newData;

		dataFilter(sensorData, newData, m, y);
		double avg = generalAvgCalculation(newData, S_XTR);
		double stdev = generalStardDeviationCalculation(newData, avg, S_XTR);

		displaySpeed(avg, stdev, m, y);
	}
	catch (const std::exception& e) {
		std::cerr << "\nError: " << e.what() << "\n";
	}
}

void outputTEMPtoCMDprocessing(const SensorlogType& sensorData, int year) {
	for (int i = 1; i <= monthNum; ++i) {
		Vector<SensorRecType> newDataX;
		dataFilter(sensorData, newDataX, i, year);
		double avg = generalAvgCalculation(newDataX, T);
		double stddvi = generalStardDeviationCalculation(newDataX, avg, T);

		std::cout << monthList[i - 1];

		displayTEMPdata(avg, stddvi);
	}
	std::cout << "\n";
}

void outputToCMDforS_T_R_SPCC_CombinationProcessing(const SensorlogType& sensorData, int month) {
	Vector<SensorRecType> newDataX, newDataXX;
	dataFilter(sensorData, newDataX, month, -1);

	skipRowContainingUnacceptableDataBaseOnSR(newDataX, newDataXX);

	double S_T = generalsPCCcalculation(newDataX, S_XTR, T);
	double S_R = generalsPCCcalculation(newDataXX, S_XTR, SR_XTR);
	double T_R = generalsPCCcalculation(newDataXX, T, SR_XTR);

	displaySPCCforAllData(S_T, S_R, T_R, month);
}

void skipRowContainingUnacceptableDataBaseOnSR(const SensorlogTypeVector& data1, SensorlogTypeVector& data2) {
	for (int i = 0; i < data1.size(); i++) {
		if (data1[i].solarRadiation >= 100) {
			data2.add_to_back(data1[i]);
		}
	}
}

void outputWholeDATAtoCMDprocessing(const SensorlogType& sensorData, int year) {
	displayHeaderForWholeData(year);

	for (int i = 1; i <= monthNum; ++i) {
		SensorlogTypeVector newDataX = Vector<SensorRecType>();
		dataFilter(sensorData, newDataX, i, year);

		double SRsum = SumForSolarCalculation(newDataX, SR_XTR);

		double SPEEDavg = generalAvgCalculation(newDataX, S_XTR);
		double SPEEDstddvi = generalStardDeviationCalculation(newDataX, SPEEDavg, S_XTR);
		double SPEEDmad = generalMADCalculation(newDataX, S_XTR);

		double TEMPavg = generalAvgCalculation(newDataX, T);
		double TEMPstddvi = generalStardDeviationCalculation(newDataX, TEMPavg, T);
		double TEMPmad = generalMADCalculation(newDataX, T);

		displayAllWholeData(SPEEDavg, SPEEDstddvi, SPEEDmad, TEMPavg, TEMPstddvi, TEMPmad, SRsum, i);
	}
	std::cout << "\n";
}

void outputWholeDATAtoCSVprocessing(std::string name, const SensorlogType& wholeData, int year) {
	std::ofstream outFile(name);
	if (!outFile.is_open()) {
		throw std::runtime_error("Cannot open the output file. Please check again.\n");
	}

	outputToCSVprocessing(outFile, wholeData, year);
}

void outputToCSVprocessing(std::ofstream& outFile, const SensorlogType& sensorData, const int year) {
	writeDataHeaderToCSV(outFile, year);

	for (int i = 1; i <= monthNum; ++i) {
		SensorlogTypeVector newDataX = Vector<SensorRecType>();
		dataFilter(sensorData, newDataX, i, year);

		double SRsum = SumForSolarCalculation(newDataX, SR_XTR);

		double SPEEDavg = generalAvgCalculation(newDataX, S_XTR);
		double SPEEDstddvi = generalStardDeviationCalculation(newDataX, SPEEDavg, S_XTR);
		double SPEEDmad = generalMADCalculation(newDataX, S_XTR);

		double TEMPavg = generalAvgCalculation(newDataX, T);
		double TEMPstddvi = generalStardDeviationCalculation(newDataX, TEMPavg, T);
		double TEMPmad = generalMADCalculation(newDataX, T);

		writeWholeDataToCSV(outFile, SPEEDavg, SPEEDstddvi, 
			SPEEDmad, TEMPavg, TEMPstddvi, TEMPmad, SRsum, i);

	}
	outFile.close();
	std::cout << "Exporting to CSV successfully!!!\n\n";
}