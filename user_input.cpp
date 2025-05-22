#include "user_input.h"

int inputMonth(){
    std::string m = " ";
    bool check = false;

    while(!check){ //false of false is true
        std::cout << "Please enter a month (1-12): ";
        std::cin >> m;

        check = isNumber(m);

        if(!check){
            std::cout << "Please enter a valid and positive number.\n\n";
        }
        else{
            check = isValidMonth(std::stoi(m));
            if(!check){
                std::cout<< "please enter a valid month in range (1-12).\n\n";
            }
        }
    }

    return std::stoi(m);
}


int inputYear(){
    std::string y = " ";
    bool check = false;

    while(!check){ //false of false is true
        std::cout << "Please enter a year (From 0s): ";
        std::cin >> y;

        check = isNumber(y);

        if(!check){
            std::cout << "Please enter a valid and positive number.\n\n";
        }
        else{
            check = isValidYear(std::stoi(y));
            if(!check){
                std::cout<< "please enter a valid year in range FROM 0.\n\n";
            }
        }
    }

    return std::stoi(y);
}


int inputOption() {
    std::string c = " ";
    bool check = false;

    while (!check) { //false of false is true
        std::cout << "Please enter an option by number shown on the menu: ";
        std::cin >> c;

        check = isNumber(c);

        if (!check) {
            std::cout << "\nPlease enter a valid and positive number.\n";
        }
        else {
            check = isInRangeMenu(std::stoi(c)); 
            if (!check) {
                std::cout << "\nError:\n";
            }
        }
    }

    return std::stoi(c);
}