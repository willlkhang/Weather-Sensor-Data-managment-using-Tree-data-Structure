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

void outputSPEEDtoCMD(const Vector<SensorRecType>& sensorData, double avg, double stdev);

void outputTEMPtoCMD(SensorlogType& wholeData, int year);

void outputToCMDforS_T_R_SPCC_Combination(SensorlogType& sensorData, int month);

void outputWholeDATAtoCMD(SensorlogType& wholeData, int year);

void outputWholeDATAtoCSV(std::string name, SensorlogType& wholeData, int year);

void outputToCSV(std::ofstream& outFile, SensorlogType& wholeData, const int year);

#endif // DATA_PRINTER_H
