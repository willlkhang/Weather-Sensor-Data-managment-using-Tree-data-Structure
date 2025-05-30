#include <iostream>
#include <fstream>

#include "data_structure.h"

#include "menu.h"


#include "input_processor.h"


int main() {

    try
    {
        SensorlogType sensorData;
        loadSource(sensorData, "data/data_source.txt");
        menu(sensorData);
    }
    catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
