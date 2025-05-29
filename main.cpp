#include <iostream>
#include <fstream>

#include "data_structure.h"

#include "menu.h"


#include "input_processor.h"
#include "RBmap.h"


int main() {

    try
    {
        SensorlogType sensorData;
        loadSource(sensorData, "data/data_source1.txt");
        menu(sensorData);
    }
    catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
