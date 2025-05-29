#include "file_reader.h"

void loadSource(SensorlogType& sensorData, std::string fileName) {

    std::ifstream sourceFile(fileName);

    if (!sourceFile) throw std::runtime_error("There is no data_source.txt\n");

    std::string csvName = "";

    while (std::getline(sourceFile, csvName)) {
        std::string dataCSVName = "data/" + csvName;
        loadCSV(sensorData, dataCSVName);
    }
}