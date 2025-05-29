#include <iostream>
#include <fstream>

#include "data_structure.h"

#include "menu.h"


#include "input_processor2.h"
#include "RBmap.h"


int main() {

    try
    {

        SensorlogType sensorData;
        loadSource(sensorData);

        //std::cout << sensorData.size() << "\n";
        menu(sensorData);
    }
    catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << "\n";
    }

    return 0;
}
