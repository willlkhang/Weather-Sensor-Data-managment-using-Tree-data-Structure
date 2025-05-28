// input_processor.h

//---------------------------------------------------------------------------------

#ifndef INPUT_PROCESSOR2_H_INCLUDED
#define INPUT_PROCESSOR2_H_INCLUDED

//---------------------------------------------------------------------------------

#include "data_structure.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "RBmap.h"

//---------------------------------------------------------------------------------


void loadSource(SensorlogType& sensorData);

void loadCSV(SensorlogType& sensorData, std::string csvName);

void processCSVtoSensorData(SensorlogType& sensorData, std::istream& inFile);

Vector<std::string> readHeader(std::istream& input);

SensorRecType rowExtraction(const Vector<std::string>& row, const Vector<std::string>& header);

void readDateTime(Date& date, Time& time, const std::string& field);

void readTime(std::string& data, Time& time);

void readDate(std::string& data, Date& date);

int getColIndex(const Vector<std::string>& data, const std::string& target);


#endif 
