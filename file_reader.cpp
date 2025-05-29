#include "file_reader.h"

void loadSource(SensorlogType& sensorData) {

    std::ifstream sourceFile("data/data_source1.txt");

    if (!sourceFile) throw std::runtime_error("There is no data_source.txt\n");

    std::string csvName = "";

    while (std::getline(sourceFile, csvName)) {
        std::string dataCSVName = "data/" + csvName;
        loadCSV(sensorData, dataCSVName);
    }
}