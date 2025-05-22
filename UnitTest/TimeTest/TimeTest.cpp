#include "../../time.h"
#include "../../time.cpp"

void testDefaultConstructor();
void testParameterizedConstructor();
void testSetValidHour();
void testSetInvalidHour();
void testSetValidMinute();
void testSetInvalidMinute();

int main() {
    testDefaultConstructor();
    testParameterizedConstructor();
    testSetValidHour();
    testSetInvalidHour();
    testSetValidMinute();
    testSetInvalidMinute();

    return 0;
}


void testDefaultConstructor() {
    Time t;
    if (t.GetHour() == 0 && t.GetMinute() == 0) {
        std::cout << "testDefaultConstructor: PASS\n";
    }
}

void testParameterizedConstructor() {
    Time t(10, 45);
    if (t.GetHour() == 10 && t.GetMinute() == 45) {
        std::cout << "testParameterizedConstructor: PASS\n";
    }
}

void testSetValidHour() {
    Time t;
    t.SetHour(15);
    if (t.GetHour() == 15) {
        std::cout << "testSetValidHour: PASS\n";
    }
}

void testSetInvalidHour() {
    Time t;
    t.SetHour(25); // invalid, should reset to 0
    if (t.GetHour() == 0) {
        std::cout << "testSetInvalidHour: PASS\n";
    }
}

void testSetValidMinute() {
    Time t;
    t.SetMinute(30);
    if (t.GetMinute() == 30) {
        std::cout << "testSetValidMinute: PASS\n";
    }
}

void testSetInvalidMinute() {
    Time t;
    t.SetHour(10);    // set hour first
    t.SetMinute(70);  // invalid, should reset hour to 0 and leave minute unchanged
    if (t.GetHour() == 0) {
        std::cout << "testSetInvalidMinute: PASS\n";
    }
}
