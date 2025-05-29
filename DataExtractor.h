#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include "vector.h"
#include "data_structure.h"

template<typename T>
class DataExtractor {
public:
	static void extractData(T& target);

	static const Vector<T>& getExtractedData();

	static void clearExtractedData();

private:
	static Vector<T> data;
};


template<typename T>
Vector<T> DataExtractor<T>::data;

template<typename T>
const Vector<T>& DataExtractor<T>::getExtractedData(){
	return data;
}

template<typename T>
void DataExtractor<T>::clearExtractedData() {
	data = Vector<T>();
}

template<typename T>
void DataExtractor<T>::extractData(T& target) {
	data.add_to_back(target);
}

#endif
