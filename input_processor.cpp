#include "input_processor.h"

void loadCSV(SensorlogType& sensorData, std::string csvName) {

    std::ifstream inFile(csvName);

    processCSVtoSensorData(sensorData, inFile);

    std::cout << "Load " << csvName << " sucessfully\n";
}

void processCSVtoSensorData(SensorlogType& sensorData, std::istream& inFile) {

    Vector<std::string> headerVec = readHeader(inFile);

    std::string line = "";
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        Vector<std::string> row;
        std::string col = "";
        while (std::getline(ss, col, ',')) {
            row.add_to_back(col);
        }
        try {
            SensorRecType temp = rowExtraction(row, headerVec);
            sensorData[temp.d.GetYear()][temp.d.GetMonth()].insert(temp);
        }
        catch (std::invalid_argument& e) {
            std::cerr << "Invalid data found in the row --> IGNORE " << e.what() << "\n";
        }
        catch (std::runtime_error& e) {
            std::cerr << "Data on the line is not complete --> IGNORE " << e.what() << "\n";
        }
    }
}


Vector<std::string> readHeader(std::istream& input) {
    std::string line = " ";
    if (!std::getline(input, line)) throw std::runtime_error("Cannot data header.\n");

    std::stringstream ss(line);
    Vector<std::string> header;

    std::string col;
    while (std::getline(ss, col, ',')) {
        header.add_to_back(col);
    }
    return header;
}

SensorRecType rowExtraction(const Vector<std::string>& row, const Vector<std::string>& header) {
    Date date = Date();
    Time time = Time();

    double speed = 0.0, solarRadiation = 0.0, temperature = 0.0;

    int dateTimeIndx = getColIndex(header, "WAST");
    if (dateTimeIndx == -1) throw std::invalid_argument("Found missing data at WAST\n");
    readDateTime(date, time, row[dateTimeIndx]);

    int speedIndx = getColIndex(header, "S");
    if (speedIndx == -1) throw std::invalid_argument("Found missing data at Speed (S)\n");
    speed = std::stod(row[speedIndx]);

    int SRIndx = getColIndex(header, "SR");
    if (SRIndx == -1) throw std::invalid_argument("Found missing data at Solar Radiation (SR)\n");
    solarRadiation = std::stod(row[SRIndx]);

    int tempIndx = getColIndex(header, "T");
    if (tempIndx == -1) throw std::invalid_argument("Found missing data at Air ambient temperature (S)\n");
    temperature = std::stod(row[tempIndx]);

    return { date, time, speed, solarRadiation, temperature };
}


void readDateTime(Date& date, Time& time, const std::string& field) {
    std::stringstream ss(field);
    std::string tmp = " ";

    std::getline(ss, tmp, ' ');
    readDate(tmp, date);

    std::getline(ss, tmp);
    readTime(tmp, time);
}

void readTime(std::string& data, Time& time) {
    std::stringstream ss(data);
    std::string tmp = " ";

    std::getline(ss, tmp, ':');
    int h = std::stoi(tmp);

    std::getline(ss, tmp, ':');
    int m = std::stoi(tmp);

    time = Time(h, m);
}

void readDate(std::string& data, Date& date) {
    std::stringstream ss(data);
    std::string tmp = " ";

    std::getline(ss, tmp, '/');
    int d = std::stoi(tmp);

    std::getline(ss, tmp, '/');
    int m = std::stoi(tmp);

    std::getline(ss, tmp, '/');
    int y = std::stoi(tmp);

    date = Date(d, m, y);

}

int getColIndex(const Vector<std::string>& data, const std::string& target) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1;
}
