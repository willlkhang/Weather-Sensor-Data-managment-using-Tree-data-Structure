#ifndef DATA_PRINTER_H
#define DATA_PRINTER_H

#include <iostream>
#include <iomanip>

#include "data_structure.h"

void displaySpeed(double avg, double stdev, int m, int y);

void displaySPCCforAllData(double S_T, double S_R, double T_R, int month);
void displayTEMPdata(double avg, double stddvi);

void displayHeaderForWholeData(int year);
void displayAllWholeData(double SPEEDavg, double SPEEDstddvi, double SPEEDmad, double TEMPavg, double TEMPstddvi, double TEMPmad, double SRsum, int month);


#endif // DATA_PRINTER_H
