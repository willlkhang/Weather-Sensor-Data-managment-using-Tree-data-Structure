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


bool Time::operator<(const Time& other) const {
    if (hour < other.hour) return true;
    if (hour > other.hour) return false;
    return minute < other.minute;
}
bool Time::operator>(const Time& other) const {
    if (hour > other.hour) return true;
    if (hour < other.hour) return false;
    return minute > other.minute;
}

bool Time::operator==(const Time& other) const {
    return ((this->GetHour() == other.GetHour()) && (this->GetMinute() == other.GetMinute()));
}