cmake_minimum_required(VERSION 3.10)

project(MyProgram VERSION 1.0) 

include_directories(src)
include_directories(include)

add_executable(MyProgram 
             main.cpp
             date.cpp 
             "data_calculator.cpp"
             io_operator.cpp
             data_printer.cpp
             time.cpp
             user_input.cpp
             user_input_validator.cpp
             menu.cpp
             menu_operator.cpp
             data_match.cpp
             data_printer.cpp
             input_processor2.cpp
              "data_structure.cpp"
             DataExtractor.cpp "ICommand.h" "IFilter.h" "ICalcStrategy.h")