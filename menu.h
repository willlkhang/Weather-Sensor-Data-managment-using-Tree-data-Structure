// menu.h

//---------------------------------------------------------------------------------

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>

#include "data_structure.h"
#include "menu_controller.h"

//---------------------------------------------------------------------------------

void menu(SensorlogType& sensorData);

void displayMenuBoard();

bool menuOptionInteraction(SensorlogType& sensorData);

#endif // MENU_H
