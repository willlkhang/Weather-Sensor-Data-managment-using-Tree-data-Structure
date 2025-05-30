// menu.h

//---------------------------------------------------------------------------------

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//---------------------------------------------------------------------------------

#include <iostream>

#include "data_structure.h"
#include "menu_controller.h"

//---------------------------------------------------------------------------------

/**
 * @file menu.h
 * @brief Provides user interaction and menu control for sensor data analysis.
 *
 * This header declares functions for displaying the main menu, handling user selection,
 * and executing operations related to sensor data such as statistical calculations and report generation.
 *
 * @author Minh Khang Nguyen
 * @version 01
 * @date 2025-05-30
 */

 /**
  * @brief Main menu loop handler
  *
  * Repeatedly displays the menu and processes user choices until the user chooses to exit.
  *
  * @param sensorData The dataset of sensor records to be processed
  * @return void
  * @pre sensorData must be initialized
  */
void menu(SensorlogType& sensorData);

/**
 * @brief Displays the list of available menu options
 *
 * Prints out the menu choices for the user.
 *
 * @return void
 */
void displayMenuBoard();

/**
 * @brief Processes the user's selected menu option
 *
 * Reads the selected option from input and triggers the corresponding operation.
 *
 * @param sensorData The dataset of sensor records used in processing
 * @return true if the program should terminate; false otherwise
 * @pre sensorData must be populated or empty, but valid
 */
bool menuOptionInteraction(SensorlogType& sensorData);

#endif // MENU_H
