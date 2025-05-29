#include "data_printer.h"

void displaySpeed(double avg, double stdev, int m, int y) {
	std::cout << "\n" << monthList[m - 1] << " " << y << ": \n"
		<< "Average speed: " << avg << " km/h\n"
		<< "Sample stdev: " << stdev << "\n\n";
}

void displayTEMPdata(double avg, double stddvi) {
	if (avg == 0.0 || stddvi == 0.0) {
		std::cout << ": No Data\n";
	}
	else {
		std::cout << ": average: " << avg << " degree C,  stdev: " << stddvi << "\n";
	}
}

void displaySPCCforAllData(double S_T, double S_R, double T_R, int month) {

	std::cout << "\nsample Pearson Correlation Coefficient for " + monthList[month - 1] << ":\n";

	std::cout << "S_T " << std::fixed << std::setprecision(2) << S_T << "\n";
	std::cout << "S_R " << std::fixed << std::setprecision(2) << S_R << "\n";
	std::cout << "T_R " << std::fixed << std::setprecision(2) << T_R << "\n\n";
}

void displayHeaderForWholeData(int year) {
	std::cout << "\n" << year << "\n";

	std::cout << "Month,Average Wind Speed(stdev, mad), Average Ambient Temperature(stdev, mad), Solar Radiation\n\n";
}

void displayAllWholeData(double SPEEDavg, double SPEEDstddvi, double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month) {
	if (SRsum != 0.0 || SPEEDavg != 0.0 || TEMPavg != 0.0) {
		std::cout << monthList[month - 1] << ": " << SPEEDavg << "(" << SPEEDstddvi << ", " << SPEEDmad << ")," << TEMPavg << "(" << TEMPstddvi << ", " << TEMPmad << ")," << SRsum << "\n";
	}
}