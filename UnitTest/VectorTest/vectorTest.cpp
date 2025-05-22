#include "../../vector.h"
#include "../../date.h"
#include "../../date.cpp"
#include "../../time.h"
#include "../../time.cpp"
#include <iostream>
#include <stdexcept>

// Function declarations
void testDefaultConstructorInt();

void testAddToBackInt();
void testCopyConstructorInt();
void testAssignmentOperatorInt();
void testElementAccessInt();

void testVectorWithDate();
void testVectorWithTime();
void testVectorResizingWithDate();
void testZeroSizedVectorWithTime();

void testEmptyVectorCopy();
void testSelfAssignment();

int main() {
    testDefaultConstructorInt();
    testAddToBackInt();
    testCopyConstructorInt();
    testAssignmentOperatorInt();
    testElementAccessInt();
    testVectorWithDate();
    testVectorWithTime();
    testVectorResizingWithDate();
    testZeroSizedVectorWithTime();
    testEmptyVectorCopy();
    testSelfAssignment();

    std::cout << "All tests completed.\n";
    return 0;
}

void testDefaultConstructorInt() {
    Vector<int> v;
    if (v.size() == 0) {
        std::cout << "testDefaultConstructorInt: PASS\n";
    } else {
        std::cout << "testDefaultConstructorInt: FAIL - Expected size 0, got " << v.size() << "\n";
    }
}


void testAddToBackInt() {
    Vector<int> v;
    v.add_to_back(10);
    v.add_to_back(20);
    v.add_to_back(30);
    if (v.size() == 3 && v[0] == 10 && v[1] == 20 && v[2] == 30) {
        std::cout << "testAddToBackInt: PASS\n";
    } else {
        std::cout << "testAddToBackInt: FAIL - ";
        if (v.size() != 3) {
            std::cout << "Expected size 3, got " << v.size();
        } else {
            std::cout << "Expected elements [10, 20, 30], got [" << v[0] << ", " << v[1] << ", " << v[2] << "]";
        }
        std::cout << "\n";
    }
}

void testCopyConstructorInt() {
    Vector<int> v1;
    v1.add_to_back(5);
    v1.add_to_back(6);
    Vector<int> v2(v1);
    v2[0] = 100;
    if (v2.size() == 2 && v2[0] == 100 && v2[1] == 6 && v1[0] == 5 && v1[1] == 6) {
        std::cout << "testCopyConstructorInt: PASS\n";
    } else {
        std::cout << "testCopyConstructorInt: FAIL - ";
        if (v2.size() != 2) {
            std::cout << "Expected size 2, got " << v2.size();
        } else if (v2[0] != 100 || v2[1] != 6) {
            std::cout << "Expected v2 [100, 6], got [" << v2[0] << ", " << v2[1] << "]";
        } else {
            std::cout << "Expected v1 [5, 6], got [" << v1[0] << ", " << v1[1] << "]";
        }
        std::cout << "\n";
    }
}

void testAssignmentOperatorInt() {
    Vector<int> v1;
    v1.add_to_back(5);
    v1.add_to_back(6);
    Vector<int> v2;
    v2 = v1;
    v2[0] = 100;
    if (v2.size() == 2 && v2[0] == 100 && v2[1] == 6 && v1[0] == 5 && v1[1] == 6) {
        std::cout << "testAssignmentOperatorInt: PASS\n";
    } else {
        std::cout << "testAssignmentOperatorInt: FAIL - ";
        if (v2.size() != 2) {
            std::cout << "Expected size 2, got " << v2.size();
        } else if (v2[0] != 100 || v2[1] != 6) {
            std::cout << "Expected v2 [100, 6], got [" << v2[0] << ", " << v2[1] << "]";
        } else {
            std::cout << "Expected v1 [5, 6], got [" << v1[0] << ", " << v1[1] << "]";
        }
        std::cout << "\n";
    }
}

void testElementAccessInt() {
    Vector<int> v;
    v.add_to_back(42);
    const Vector<int>& cv = v;
    v[0] = 43;
    if (cv[0] == 43 && v[0] == 43) {
        std::cout << "testElementAccessInt: PASS\n";
    } else {
        std::cout << "testElementAccessInt: FAIL - ";
        if (cv[0] != 43) {
            std::cout << "Expected const access 43, got " << cv[0];
        } else {
            std::cout << "Expected non-const access 43, got " << v[0];
        }
        std::cout << "\n";
    }
}


void testVectorWithDate() {
    Vector<Date> v;
    Date d1(15, 1, 2025);
    Date d2(20, 6, 2023);
    v.add_to_back(d1);
    v.add_to_back(d2);
    Vector<Date> v2(v); // Test copy constructor
    v2[0].SetDay(25);   // Modify copy
    if (v.size() == 2 &&
        v[0].GetDay() == 15 && v[0].GetMonth() == 1 && v[0].GetYear() == 2025 &&
        v[1].GetDay() == 20 && v[1].GetMonth() == 6 && v[1].GetYear() == 2023 &&
        v2[0].GetDay() == 25 && v2[0].GetMonth() == 1 && v2[0].GetYear() == 2025 &&
        v2[1].GetDay() == 20 && v2[1].GetMonth() == 6 && v2[1].GetYear() == 2023 &&
        v[0].GetDay() == 15) {
        std::cout << "testVectorWithDate: PASS\n";
    } else {
        std::cout << "testVectorWithDate: FAIL - ";
        if (v.size() != 2) {
            std::cout << "Expected size 2, got " << v.size();
        } else if (v[0].GetDay() != 15 || v[0].GetMonth() != 1 || v[0].GetYear() != 2025 ||
                   v[1].GetDay() != 20 || v[1].GetMonth() != 6 || v[1].GetYear() != 2023) {
            std::cout << "Expected v[0] = 15/1/2025, v[1] = 20/6/2023, got v[0] = "
                      << v[0].GetDay() << "/" << v[0].GetMonth() << "/" << v[0].GetYear()
                      << ", v[1] = " << v[1].GetDay() << "/" << v[1].GetMonth() << "/" << v[1].GetYear();
        } else {
            std::cout << "Expected v2[0] = 25/1/2025, v[0] = 15/1/2025, got v2[0] = "
                      << v2[0].GetDay() << "/" << v2[0].GetMonth() << "/" << v2[0].GetYear()
                      << ", v[0] = " << v[0].GetDay() << "/" << v[0].GetMonth() << "/" << v[0].GetYear();
        }
        std::cout << "\n";
    }
}

void testVectorWithTime() {
    Vector<Time> v;
    Time t1(9, 30);
    Time t2(14, 45);
    v.add_to_back(t1);
    v.add_to_back(t2);
    const Vector<Time>& cv = v;
    if (v.size() == 2 &&
        cv[0].GetHour() == 9 && cv[0].GetMinute() == 30 &&
        cv[1].GetHour() == 14 && cv[1].GetMinute() == 45) {
        std::cout << "testVectorWithTime: PASS\n";
    } else {
        std::cout << "testVectorWithTime: FAIL - ";
        if (v.size() != 2) {
            std::cout << "Expected size 2, got " << v.size();
        } else {
            std::cout << "Expected cv[0] = 9:30, cv[1] = 14:45, got cv[0] = "
                      << cv[0].GetHour() << ":" << cv[0].GetMinute() << ", cv[1] = "
                      << cv[1].GetHour() << ":" << cv[1].GetMinute();
        }
        std::cout << "\n";
    }
}

void testVectorResizingWithDate() {
    Vector<Date> v;
    for (int i = 0; i < 10; ++i) {
        v.add_to_back(Date(i + 1, (i % 12) + 1, 2025));
    }
    if (v.size() == 10 &&
        v[9].GetDay() == 10 && v[9].GetMonth() == 10 && v[9].GetYear() == 2025) {
        std::cout << "testVectorResizingWithDate: PASS\n";
    } else {
        std::cout << "testVectorResizingWithDate: FAIL - ";
        if (v.size() != 10) {
            std::cout << "Expected size 10, got " << v.size();
        } else {
            std::cout << "Expected v[9] = 10/10/2025, got "
                      << v[9].GetDay() << "/" << v[9].GetMonth() << "/" << v[9].GetYear();
        }
        std::cout << "\n";
    }
}

void testZeroSizedVectorWithTime() {
    Vector<Time> v(0);
    if (v.size() == 0) {
        std::cout << "testZeroSizedVectorWithTime: PASS\n";
    } else {
        std::cout << "testZeroSizedVectorWithTime: FAIL - Expected size 0, got " << v.size() << "\n";
    }
}


void testEmptyVectorCopy() {
    Vector<int> v1;
    Vector<int> v2(v1); // Copy empty vector
    Vector<int> v3;
    v3 = v1; // Assign empty vector
    if (v2.size() == 0 && v3.size() == 0) {
        std::cout << "testEmptyVectorCopy: PASS\n";
    } else {
        std::cout << "testEmptyVectorCopy: FAIL - Expected v2.size() = 0, v3.size() = 0, got v2.size() = "
                  << v2.size() << ", v3.size() = " << v3.size() << "\n";
    }
}

void testSelfAssignment() {
    Vector<int> v;
    v.add_to_back(1);
    v.add_to_back(2);
    v = v; // Self-assignment
    if (v.size() == 2 && v[0] == 1 && v[1] == 2) {
        std::cout << "testSelfAssignment: PASS\n";
    } else {
        std::cout << "testSelfAssignment: FAIL - Expected size 2 with [1, 2], got size " << v.size()
                  << " with [" << v[0] << ", " << v[1] << "]\n";
    }
}
