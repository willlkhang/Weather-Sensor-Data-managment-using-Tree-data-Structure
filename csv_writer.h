#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <iostream>
#include "data_structure.h"

void writeDataHeaderToCSV(std::ofstream& outFile, const int year);
void writeWholeDataToCSV(std::ostream& outFile, double SPEEDavg, double SPEEDstddvi,
	double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month);

#endif // CSV_WRITER_H
