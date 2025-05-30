//---------------------------------------------------------------------------------

#ifndef EXTRACTOR_H
#define EXTRACTOR_H

//---------------------------------------------------------------------------------

#include "vector.h"
#include "data_structure.h"

//---------------------------------------------------------------------------------

	/**
	 * @class DataExtractor
	 * @brief Utility class for extracting and storing sensor data records
	 *
	 * This class provides static methods to collect and manage extracted data
	 * using a Vector. It supports storing temporary results during processing
	 * such as in-order traversals of trees.
	 *
	 * Designed as a generic utility using templates, allowing flexibility for
	 * different data types (e.g., SensorRecType).
	 *
	 * @tparam T The type of data to extract and store
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 * @date 2025-05-30 Minh Khang Nguyen, Created
	 *
	 * @bug No concurrency protection when used in multi-threaded contexts
	 */
template<typename T>
class DataExtractor {
public:

		/**
		 * @brief Adds an item to the extracted data
		 *
		 * Appends the given element to the static internal vector.
		 * Typically used during traversal callbacks.
		 *
		 * @param target The data item to extract
		 * @return void
		 * @post The item is added to the internal vector
		 */
	static void extractData(T& target);
		
		/**
		 * @brief Retrieves the internal extracted data vector
		 *
		 * Returns a constant reference to the internal Vector of extracted items.
		 *
		 * @return const Vector<T>& - The extracted data
		 */
	static const Vector<T>& getExtractedData();
		
	/**
	 * @brief Clears the extracted data
	 *
	 * Resets the internal Vector, removing all previously extracted items.
	 *
	 * @return void
	 * @post Internal vector is reset to empty
	 */
	static void clearExtractedData();

private:
	/// Stores the extracted data
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
