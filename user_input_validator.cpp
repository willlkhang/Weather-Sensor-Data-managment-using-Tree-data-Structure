#include "user_input_validator.h"

bool isNumber(const std::string str){
    if(str.empty()) return false;

    for(int i = 0; i < str.length(); i++){
        if(!isdigit(str[i]))
            return false;
    }

    return true;
}


bool isValidMonth(const int m){
    return (m > 0 && m <= monthNum);
}

bool isValidYear(const int y){
    return (y >= 0 && y <= 999999); //assume year of 999999 is program updated.
}


bool isInRangeMenu(const int c) {
    return (c > 0 && c <= menuItem);
}