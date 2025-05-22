#include <iostream>
#include <fstream>

#include "data_structure.h"

#include "menu.h"


#include "input_processor2.h"
#include "RBmap.h"

#include <chrono>
#include <iostream>

template<typename K, typename V>
void print(K& key, V& value);

int main() {

    //RBMap<std::string, SensorlogType> store;

    auto t_start = std::chrono::high_resolution_clock::now();

    SensorlogType1 sensorData;
    loadSource(sensorData);

    auto t_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = t_end - t_start;
    std::cout << "Loading time: " << elapsed.count() << " s\n";


    std::cout << sensorData.size() << "\n";


    menu(sensorData);

    return 0;
}


template<typename K, typename V>
void print(K& key, V& value) {
    std::cout << key << "\n";
}