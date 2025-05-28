// menu.h

//---------------------------------------------------------------------------------

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>

#include "data_structure.h"
#include "menu_controller.h"

//---------------------------------------------------------------------------------

void menu(SensorlogType1& sensorData);

void displayMenuBoard();

bool menuOptionInteraction(SensorlogType1& sensorData);

#endif // MENU_H
