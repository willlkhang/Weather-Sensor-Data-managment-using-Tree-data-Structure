#include "csv_writer.h"

void writeDataHeaderToCSV(std::ofstream& outFile, const int year) {
	outFile << "Year" << "," << year << "\n";
	outFile << "Month,"
		<< "\"Average Wind Speed(stdev, mad)\","
		<< "\"Average Ambient Temperature(stdev, mad)\","
		<< "Solar Radiation\n";
}

void writeWholeDataToCSV(std::ostream& outFile, double SPEEDavg, double SPEEDstddvi,
	double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month) {
	if (SRsum != 0.0 || SPEEDavg != 0.0 || TEMPavg != 0.0) {
		outFile
			<< monthList[month - 1] << ","
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