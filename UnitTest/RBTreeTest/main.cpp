// hash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "hashMap.h"
#include "RBTree.h"
#include "vector.h"
#include "DataExtractor.h"

void testInsertPair();
void testRmoveByKey();
void testCopyConstructor();
void testPassByValue(HashMap<int, int> map);
void testPassByReference(HashMap<int, int>& map);
void testPassByConstReference(const HashMap<int, int>& map);
void testFindValue();
void testAssignmentCopy();
void testGetterOperator();
void testSetterOperator();
void testAtMethod();
void test2DMap();
void testExtractingMapAndTreeToVector();
void testExtractingMapAndTreeToVectorWithScopeDimension1();
void testExtractingMapAndTreeToVectorWithScopeDimension2();



int main()
{
    testInsertPair();
    testRmoveByKey();
    testCopyConstructor();

    HashMap<int, int> map;

    testPassByValue(map);
    if(map.empty()) std::cout << "testPassByValue: Passed\n";

    testPassByReference(map);
    if (!map.empty()) std::cout << "testPassByReference: Passed\n";
    else std::cout << "testPassByReference: Failed\n";

    testPassByConstReference(map);
    testFindValue();
    testAssignmentCopy();
    testGetterOperator();
    testSetterOperator();

    testAtMethod();

    test2DMap();

    testExtractingMapAndTreeToVector();
    testExtractingMapAndTreeToVectorWithScopeDimension1();
    testExtractingMapAndTreeToVectorWithScopeDimension2();
}

void testFindValue() {
    HashMap<int, std::string> map;

    for (int i = 1; i < 10; i++) {
        map.addItem(i, "hello " + std::to_string(i));
    }

    if (!map.findValue(90)) {
        std::cout << "testFindValue: Passed\n"; return;
    }

    std::cout << "testFindValue: Failed\n";
}

void testExtractingMapAndTreeToVectorWithScopeDimension2() {

    RBTree<std::string> tree;
    for (int i = 0; i < 5; i++) {
        tree.insert("hello" + std::to_string(i));
    }

    RBTree<std::string> tree1;
    for (int i = 0; i < 5; i++) {
        tree1.insert("hi" + std::to_string(i));
    }

    RBTree<std::string> tree2;
    for (int i = 0; i < 5; i++) {
        tree2.insert("Xin Chao" + std::to_string(i));
    }

    HashMap<int, HashMap<int, RBTree<std::string>>> map;

    map[0][0] = tree;
    map[0][1] = tree;
    map[1][0] = tree1;
    map[1][1] = tree1;
    map[1][2] = tree1;
    map[1][3] = tree1;
    map[2][0] = tree2;
    map[2][1] = tree;

    map[2][0].inOrder(DataExtractor::extractData);

    Vector<std::string> vec = DataExtractor::getExtractedData();

    int count = 0;
    for (int i = 0; i < vec.size(); i++) {

        std::cout << vec[i] << " ";

        count++;
        if (count % 5 == 0) std::cout << "\n";
    }

    DataExtractor::clearExtractedData();

    std::cout << "testExtractingMapAndTreeToVectorWithScopeDimension1: Passed\n\n";

}

void testExtractingMapAndTreeToVectorWithScopeDimension1() {

    RBTree<std::string> tree;
    for (int i = 0; i < 5; i++) {
        tree.insert("hello" + std::to_string(i));
    }

    RBTree<std::string> tree1;
    for (int i = 0; i < 5; i++) {
        tree1.insert("hi" + std::to_string(i));
    }

    HashMap<int, HashMap<int, RBTree<std::string>>> map;

    map[0][0] = tree;
    map[0][1] = tree;
    map[1][0] = tree1;
    map[1][1] = tree1;
    map[1][2] = tree1;
    map[1][3] = tree1;
    map[2][0] = tree;
    map[2][1] = tree;

    for (int i = 0; i < map[1].size(); i++) {
        map[1][i].inOrder(DataExtractor::extractData);
    }

    Vector<std::string> vec = DataExtractor::getExtractedData();

    int count = 0;
    for (int i = 0; i < vec.size(); i++) {

        std::cout << vec[i] << " ";

        count++;
        if (count % 5 == 0) std::cout << "\n";
    }

    DataExtractor::clearExtractedData();

    std::cout << "testExtractingMapAndTreeToVectorWithScopeDimension1: Passed\n\n";

}

void testExtractingMapAndTreeToVector() {

    RBTree<std::string> tree;
    for (int i = 0; i < 5; i++) {
        tree.insert("hello" + std::to_string(i));
    }

    HashMap<int, HashMap<int, RBTree<std::string>>> map;

    map[0][0] = tree;
    map[0][1] = tree;
    map[1][0] = tree;
    map[1][1] = tree;
    map[2][0] = tree;
    map[2][1] = tree;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            map[i][j].inOrder(DataExtractor::extractData);
        }
    }

    Vector<std::string> vec = DataExtractor::getExtractedData();

    int count = 0;
    for (int i = 0; i < vec.size(); i++) {

        std::cout << vec[i] << " ";

        count++;
        if (count % 5 == 0) std::cout << "\n";
    }

    DataExtractor::clearExtractedData();

    std::cout << "testExtractingMapAndTreeToVector: Passed\n\n";
}

void test2DMap() {
    HashMap<int, HashMap<int, int>> map;
    map[0][0] = 2;

    if (!map.empty()) {
        std::cout << "test2DMap: Passed\n"; return;
    }
    std::cout << "test2DMap: Failed\n";
}

void testAtMethod() {
    HashMap<int, std::string> map;
    map.addItem(1, "hello Minh\n");
    if (map.at(1) == "hello Minh\n") {
        std::cout << "testAtMethod: Passed\n"; return;
    }
    std::cout << "testAtMethod: Failed\n";
}

void testSetterOperator() {
    HashMap<int, std::string> map;

    map.addItem(1, "hello Minh");
    map[1] = "34739531";
    map[2] = "Minh Khang";
    if (map[1] == "34739531" && map[2] == "Minh Khang") {
        std::cout << "testSetterOperator: Passed\n"; return;
    }
    std::cout << "testSetterOperator: Failed\n";
}

void testGetterOperator() {
    HashMap<int, std::string> map;

    map.addItem(1, "hello Minh");
    if (map[1] == "hello Minh") {
        std::cout << "testSetterOperator: Passed\n"; return;
    }
    std::cout << "testSetterOperator: Failed\n";
}

void testAssignmentCopy() {
    HashMap<int, std::string> map1, map2;
    for (int i = 0; i < 10; i++) {
        map1.addItem(i, "hello my name is Minh Khang Nguyen\n");
    }

    map2 = map1;

    if (map2.findValue(5)) {
        std::cout << "testAssignmentCopy: Passed\n"; return;
    }
    std::cout << "testAssignmentCopy: Failed\n";
}

void testPassByConstReference(const HashMap<int, int>& map) {
    if (!map.empty()) {
        std::cout << "testPassByConstReference: Passed\n"; return;
    }
    std::cout << "testPassByConstReference: Failed\n";
}

void testPassByReference(HashMap<int, int>& map) {
    for (int i = 0; i < 10; i++) {
        map.addItem(i, i + 2);
    }
}

void testPassByValue(HashMap<int, int> map) {
    map.addItem(1, 2);
}

void testRmoveByKey() {

    HashMap<int, int> map;

    for (int i = 0; i < 10; i++) {
        map.addItem(i, i + 2);
    }

    map.removeItem(5);

    if (!map.findValue(5)) {
        std::cout << "testRmoveByKey: Passed\n"; return;
    }
    std::cout << "testRmoveByKey: Faield\n";
}

void testInsertPair() {
    HashMap<int, int> map;

    map.addItem(1, 2);
    if (!map.empty()) {
        std::cout << "testInsertPair: Passed\n"; return;
    }

    std::cout << "testInsertPair: Faield\n";
}

void testCopyConstructor() {
    HashMap<int, std::string> map;

    for (int i = 0; i < 10; i++) {
        map.addItem(i, "hello");
    }

    HashMap<int, std::string> test(map);

    if (!test.empty()) {
        std::cout << "testCopyConstructor: Passed\n"; return;
    }
    std::cout << "testCopyConstructor: Faield\n";
}
