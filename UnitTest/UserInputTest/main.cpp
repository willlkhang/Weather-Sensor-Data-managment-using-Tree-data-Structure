#include <iostream>

#include "../../user_input.h"
#include "../../user_input.cpp"
#include "../../user_input_validator.h"
#include "../../user_input_validator.cpp"
#include "../../user_input_validator.h"


void testIsNumber();
void testIsValidMonth();
void testIsValidYear();
void testIsInRangeMenu();

int main() {
    std::cout << "Running tests...\n" << std::endl;

    testIsNumber();
    std::cout << std::endl;
    testIsValidMonth();
    std::cout << std::endl;
    testIsValidYear();
    std::cout << std::endl;
    testIsInRangeMenu();

    std::cout << "\nTests completed.\n";
    return 0;
}

void printResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}


void testIsNumber() {
    printResult("isNumber('123')", isNumber("123") == true);
    printResult("isNumber('0')", isNumber("0") == true);
    printResult("isNumber('')", isNumber("") == false);
    printResult("isNumber('abc')", isNumber("abc") == false);
    printResult("isNumber('12a')", isNumber("12a") == false);
}


void testIsValidMonth() {
    printResult("isValidMonth(1)", isValidMonth(1) == true);
    printResult("isValidMonth(12)", isValidMonth(12) == true);
    printResult("isValidMonth(0)", isValidMonth(0) == false);
    printResult("isValidMonth(13)", isValidMonth(13) == false);
}

void testIsValidYear() {
    printResult("isValidYear(0)", isValidYear(0) == true);
    printResult("isValidYear(2023)", isValidYear(2023) == true);
    printResult("isValidYear(-1)", isValidYear(-1) == false);
    printResult("isValidYear(1000000)", isValidYear(1000000) == false);
}

void testIsInRangeMenu() {
    printResult("isInRangeMenu(1)", isInRangeMenu(1) == true);
    printResult("isInRangeMenu(5)", isInRangeMenu(5) == true);
    printResult("isInRangeMenu(0)", isInRangeMenu(0) == false);
    printResult("isInRangeMenu(6)", isInRangeMenu(6) == false);
}

