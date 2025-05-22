#include "../../date.h"
#include "../../date.cpp"

#include <iostream>

void testDefaultConstructor();
void testParameterizedConstructor();
void testSetAndGetDay();
void testSetAndGetMonth();
void testSetAndGetYear();

int main(){
    testDefaultConstructor();
    testParameterizedConstructor();
    testSetAndGetDay();
    testSetAndGetMonth();
    testSetAndGetYear();

    return 0;
}


void testDefaultConstructor() {
    Date d;
    if (d.GetDay() == 0 && d.GetMonth() == 0 && d.GetYear() == 0) {
        std::cout << "testDefaultConstructor: PASS\n";
    }
}

void testParameterizedConstructor() {
    Date d(15, 4, 2025);
    if (d.GetDay() == 15 && d.GetMonth() == 4 && d.GetYear() == 2025) {
        std::cout << "testParameterizedConstructor: PASS\n";
    }
}

void testSetAndGetDay() {
    Date d;
    d.SetDay(12);
    if (d.GetDay() == 12) {
        std::cout << "testSetAndGetDay: PASS\n";
    }
}

void testSetAndGetMonth() {
    Date d;
    d.SetMonth(8);
    if (d.GetMonth() == 8) {
        std::cout << "testSetAndGetMonth: PASS\n";
    }
}

void testSetAndGetYear() {
    Date d;
    d.SetYear(1999);
    if (d.GetYear() == 1999) {
        std::cout << "testSetAndGetYear: PASS\n";
    }
}

