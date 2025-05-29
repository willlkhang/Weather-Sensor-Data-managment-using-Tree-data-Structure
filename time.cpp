#include "time.h"

#include <iostream>

Time::Time() : hour(0), minute(0) {}
Time::Time(int h, int m) : hour(h), minute(m) {}

void Time::SetHour(int h){
    if(h > 23 || h < 0){
        std::cout << "Invalid hour set to default hour = 0" << "\n";
        hour = 0;
    }
    else
        hour = h;
}

int Time::GetHour() const{
    return hour;
}

void Time::SetMinute(int m){
    if(m > 59 || m < 0){
        std::cout << "Invalid minute set to default hour = 0" << "\n";
        minute = 0;
    }
    else
        minute = m;
}

int Time::GetMinute() const{
    return minute;
}
