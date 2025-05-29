// data_printer.h

//---------------------------------------------------------------------------------

#ifndef DATA_PRINTER_H_INCLUDED
#define DATA_PRINTER_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

#include "io_operator.h"
#include "data_calculator.h"
#include "data_match.h"
#include "data_structure.h"
#include "data_printer.h"
#include "csv_writer.h"

//---------------------------------------------------------------------------------

void outputSPEEDtoCMDprocessing(SensorlogType& sensorData, int m, int y);

void outputTEMPtoCMDprocessing(SensorlogType& wholeData, int year);

void outputToCMDforS_T_R_SPCC_CombinationProcessing(SensorlogType& sensorData, int month);

void outputWholeDATAtoCMDprocessing(SensorlogType& wholeData, int year);

void outputWholeDATAtoCSVprocessing(std::string name, SensorlogType& wholeData, int year);

void outputToCSVprocessing(std::ofstream& outFile, SensorlogType& wholeData, const int year);


//make another .cpp and .h files for data printing

void writeDataHeaderToCSV(std::ofstream& outFile, const int year);
void writeWholeDataToCSV(std::ostream& outFile, double SPEEDavg, double SPEEDstddvi,
	double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month);

#endif // DATA_PRINTER_H
