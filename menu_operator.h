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

//---------------------------------------------------------------------------------

void outputSPEEDtoCMDprocessing(const Vector<SensorRecType>& sensorData, double avg, double stdev);

void outputTEMPtoCMDprocessing(SensorlogType& wholeData, int year);

void outputToCMDforS_T_R_SPCC_CombinationProcessing(SensorlogType& sensorData, int month);

void outputWholeDATAtoCMDprocessing(SensorlogType& wholeData, int year);

void outputWholeDATAtoCSVprocessing(std::string name, SensorlogType& wholeData, int year);

void outputToCSVprocessing(std::ofstream& outFile, SensorlogType& wholeData, const int year);


void displaySPCCforAllData(double S_T, double S_R, double T_R, int month);
void displayTEMPdata(double avg, double stddvi);

#endif // DATA_PRINTER_H
