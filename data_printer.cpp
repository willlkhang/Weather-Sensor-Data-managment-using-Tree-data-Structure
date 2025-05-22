#include "data_printer.h"

void outputSPEEDtoCMD(const Vector<SensorRecType>& sensorData, double avg, double stdev) {
	try {
		if (sensorData.size() == 0) {
			throw std::runtime_error("No Data found for the specific month of the year from the data source\nPlease check again\n");
		}

		std::cout << "\n" << monthList[(sensorData[1].d.GetMonth() - 1)] << " " << sensorData[1].d.GetYear() << ": \n"
			<< "Average speed: " << avg << " km/h\n"
			<< "Sample dev: " << stdev << "\n\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\nError: " << e.what() << "\n";
	}
}

void outputTEMPtoCMD(SensorlogType1& sensorData, int year) {
	try {
		for (int i = 1; i <= monthNum; ++i) {
			Vector<SensorRecType> newDataX;
			dataFilter(sensorData, newDataX, i, year);
			double avg = calAvg(newDataX, T);
			double stddvi = calStardDeviation(newDataX, avg, T);

			std::cout << monthList[i - 1];

			if (avg == 0.0 || stddvi == 0.0) {
				std::cout << ": No Data\n";
			}
			else {
				std::cout << ": average: " << avg << " degree C,  stdev: " << stddvi << "\n";
			}
		}
		std::cout << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\nError: " << e.what() << "\n";
	}
}

void outputToCMDforS_T_R_SPCC_Combination(SensorlogType1& sensorData, int month) {
	Vector<SensorRecType> newDataX;
	dataFilter(sensorData, newDataX, month, -1);

	std::cout << "\nsample Pearson Correlation Coefficient for " + monthList[month - 1] << ":\n";

	double S_T = calsPCC(newDataX, S_XTR, T);
	double S_R = calsPCC(newDataX, S_XTR, SR_XTR);
	double T_R = calsPCC(newDataX, T, SR_XTR);

	std::cout << "S_T " << std::fixed << std::setprecision(2) << S_T << "\n";
	std::cout << "S_R " << std::fixed << std::setprecision(2) << S_R << "\n";
	std::cout << "T_R " << std::fixed << std::setprecision(2) << T_R << "\n\n";
}

void outputWholeDATAtoCMD(SensorlogType1& sensorData, int year) {
	try {
		std::cout << "\n" << year << "\n";

		std::cout << "Month,Average Wind Speed(stdev, mad), Average Ambient Temperature(stdev, mad), Solar Radiation\n\n";

		for (int i = 1; i <= monthNum; ++i) {
			SensorlogType newDataX = Vector<SensorRecType>();
			dataFilter(sensorData, newDataX, i, year);

			double SRsum = calSumForSolar(newDataX, SR_XTR);

			double SPEEDavg = calAvg(newDataX, S_XTR);
			double SPEEDstddvi = calStardDeviation(newDataX, SPEEDavg, S_XTR);
			double SPEEDmad = calMAD(newDataX, S_XTR);

			double TEMPavg = calAvg(newDataX, T);
			double TEMPstddvi = calStardDeviation(newDataX, TEMPavg, T);
			double TEMPmad = calMAD(newDataX, T);


			if (SRsum == 0.0 || SPEEDavg == 0.0 || TEMPavg == 0.0) {
				continue;
			}
			else {
				std::cout << monthList[i - 1] << ": " << SPEEDavg << "(" << SPEEDstddvi << ", " << SPEEDmad << ")," << TEMPavg << "(" << TEMPstddvi << ", " << TEMPmad << ")," << (SRsum) << "\n";
			}
		}
		std::cout << "\n";
	}
	catch (const std::exception& e) {
		std::cerr << "\nError: " << e.what() << "\n";
	}
}


void outputWholeDATAtoCSV(std::string name, SensorlogType1& wholeData, int year) {
	std::ofstream outFile(name);
	if (!outFile.is_open()) {
		throw std::runtime_error("Cannot open the output file. Please check again.\n");
	}

	outputToCSV(outFile, wholeData, year);
}

void outputToCSV(std::ofstream& outFile, SensorlogType1& sensorData, const int year) {
	outFile << "Year" << "," << year << "\n";
	outFile << "Month,"
		<< "\"Average Wind Speed(stdev, mad)\","
		<< "\"Average Ambient Temperature(stdev, mad)\","
		<< "Solar Radiation\n";


	for (int i = 1; i <= monthNum; ++i) {
		SensorlogType newDataX = Vector<SensorRecType>();
		dataFilter(sensorData, newDataX, i, year);

		double SRsum = calSumForSolar(newDataX, SR_XTR);

		double SPEEDavg = calAvg(newDataX, S_XTR);
		double SPEEDstddvi = calStardDeviation(newDataX, SPEEDavg, S_XTR);
		double SPEEDmad = calMAD(newDataX, S_XTR);

		double TEMPavg = calAvg(newDataX, T);
		double TEMPstddvi = calStardDeviation(newDataX, TEMPavg, T);
		double TEMPmad = calMAD(newDataX, T);

		if (SRsum == 0.0 || SPEEDavg == 0.0 || TEMPavg == 0.0) {
			continue;
		}
		else {
			outFile
				<< monthList[i - 1] << ","
				<< "\""
				<< SPEEDavg
				<< "(" << SPEEDstddvi << ", " << SPEEDmad << ")"
				<< "\","
				<< "\""
				<< TEMPavg
				<< "(" << TEMPstddvi << ", " << TEMPmad << ")"
				<< "\","
				<< SRsum
				<< "\n";

		}
	}
	outFile.close();
	std::cout << "Exporting to CSV successfully!!!\n\n";
}

