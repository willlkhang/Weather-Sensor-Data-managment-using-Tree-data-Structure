#include "menu.h"

void menu(SensorlogType& sensorData) {
	bool stop = false;

	while (!stop) {
		displayMenuBoard();
		stop = menuOptionInteraction(sensorData);
	}
}

void displayMenuBoard() {
	std::cout << "------------------------------------- Menu --------------------------------------\n";
	std::cout << "1. Average Speed and standard deviation for a month of a year.\n";
	std::cout << "2. Average temperature and standard deviation for a month of a year.\n";
	std::cout << "3. sPCC between temperature, speed, and solar radiation for a specific month for all uploaded years.\n";
	std::cout << "4. Annual Report print to CSV.\n";
	std::cout << "5. Exit program\n";
	std::cout << "------------------------------------- End. --------------------------------------\n";
}

bool menuOptionInteraction(SensorlogType& sensorData) {
	int option = inputOption();

	switch (option) {
		case 1:
			SPEEDAvgVsStdDeviForSPECMonthvsYear(sensorData);
			return false;
		case 2:
			TEMPAvgVsStdDeviForEACHMonthvsYear(sensorData);
			return false;
		case 3:
			S_T_R_SPCC_Combination(sensorData);
			return false;
		case 4:
			AnnualSensorReportToCSV(sensorData);
			return false;
		case 5:
			std::cout << "You are existing the program...";
			std::cout << "Good Bye......\n\n\n";
			return true;
		default:
			std::cout << "Please enter a number on the menu\n";
			return false;
	}
}