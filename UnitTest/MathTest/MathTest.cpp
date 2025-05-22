#include "../../math.h"

#include <iostream>
#include <cmath>

void test_calSum();
void test_calAvg();
void test_calStandardDeviation();
void test_emptyVector();


int main(){
    test_calSum();
    test_calAvg();
    test_calStandardDeviation();
    test_emptyVector();

    return 0;
}

void test_calSum() {
    Vector<int> vec;
    vec.add_to_back(1);
    vec.add_to_back(2);
    vec.add_to_back(3);

    Math<int> math;
    double result = math.calSum(vec);

    if (std::fabs(result - 6.0) < 1e-6)
        std::cout << "test_calSum: PASS\n";
    else
        std::cout << "test_calSum: FAIL (expected 6, got " << result << ")\n";
}

void test_calAvg() {
    Vector<int> vec;
    vec.add_to_back(10);
    vec.add_to_back(20);
    vec.add_to_back(30);

    Math<int> math;
    double result = math.calAvg(vec);

    if (std::fabs(result - 20.0) < 1e-6)
        std::cout << "test_calAvg: PASS\n";
    else
        std::cout << "test_calAvg: FAIL (expected 20, got " << result << ")\n";
}

void test_calStandardDeviation() {
    Vector<int> vec;
    vec.add_to_back(2);
    vec.add_to_back(4);
    vec.add_to_back(4);
    vec.add_to_back(4);
    vec.add_to_back(5);
    vec.add_to_back(5);
    vec.add_to_back(7);
    vec.add_to_back(9);

    Math<int> math;
    double result = math.calStandardDeviation(vec);

    // From textbook example, sample standard deviation = ~2.138
    if (std::fabs(result - 2.138089935) < 1e-4)
        std::cout << "test_calStandardDeviation: PASS\n";
    else
        std::cout << "test_calStandardDeviation: FAIL (expected ~2.138, got " << result << ")\n";
}

void test_emptyVector() {
    Vector<int> vec;
    Math<int> math;

    if (math.calSum(vec) == 0.0 && math.calAvg(vec) == 0.0 && math.calStandardDeviation(vec) == 0.0)
        std::cout << "test_emptyVector: PASS\n";
    else
        std::cout << "test_emptyVector: FAIL (expected 0 for all methods)\n";
}
