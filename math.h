//math.h

//---------------------------------------------------------------------------------

#ifndef MATH_H
#define MATH_H

//---------------------------------------------------------------------------------

#include "vector.h"
#include <cmath>

//-----------------------------------------------------------------------------
	/**
	 * @typename Math
	 * @brief A generic utility typename for statistical computations on a Vector
	 *
	 * This templated typename provides methods to calculate sum, average, and standard
	 * deviation on numerical data stored in a Vector.\n
	 * It is designed to work with numeric types such as int, float, or double.\n
	 *
	 * @tparam T The numeric data type stored in the vector
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add support for other statistical measures
	 * @bug Empty vectors may cause division by zero in some calculations
	 */
template <typename T>
class Math{
public:

        /**
		 * @brief Default constructor
		 *
		 * Initializes the internal vector as empty.
		 *
		 * @return void
		 * @post Internal vector is empty
		 */
    Math();

        /**
		 * @brief Constructor with input vector
		 *
		 * Initializes the typename with a provided vector of data.
		 *
		 * @param data A vector of type T used to initialize the typename
		 * @return void
		 * @pre data must be a valid vector
		 * @post Internal vector is a copy of data
		 */
    Math(Vector<T> data);

        /**
		 * @brief Calculates the sum of all elements in the given vector
		 *
		 * Sums all elements, converting them to double for precision.
		 *
		 * @param data The vector containing numeric elements
		 * @return double - The sum of the elements
		 * @pre data must be a valid vector
		 * @post Returns 0.0 if vector is empty
		 */
    double calSum(Vector<T> data);

        /**
		 * @brief Calculates the average of the elements in the given vector
		 *
		 * Computes the arithmetic mean of the vector’s elements.
		 *
		 * @param data The vector containing numeric elements
		 * @return double - The average of the elements
		 * @pre data must be a valid vector
		 * @post Returns 0.0 if vector is empty
		 */
    double calAvg(Vector<T> data);

        /**
		 * @brief Calculates the sample standard deviation of the vector
		 *
		 * Computes the sample standard deviation using the mean of the data.
		 *
		 * @param data The vector of numeric elements
		 * @return double - The sample standard deviation
		 * @pre data must have at least two elements for valid calculation
		 * @post Returns 0.0 if vector is empty
		 */
    double calStandardDeviation(Vector<T> data);

        /**
		 * @brief Calculates the standard deviation with a custom mean
		 *
		 * Computes the sample standard deviation using a provided mean value.
		 *
		 * @param data The vector of numeric elements
		 * @param mean The mean value to use in the calculation
		 * @return double - The sample standard deviation
		 * @pre data must have at least two elements for valid calculation
		 * @post Returns 0.0 if vector is empty
		 */
    double calStandardDeviationCustomParam(Vector<T> data, double mean);

	double sPPC(const Vector<T>& x, const Vector<T>& y);

	double MAD(const Vector<T>& x);

private:
    /// Internal vector storing the data
    Vector<T> data; //at this state first version using vector. It can also be updated to use different data type
};

//==========================================implementation=================================================
template <typename T>
Math<T>::Math(): data() {}

template <typename T>
Math<T>::Math(Vector<T> d) : data(d) {}

template <typename T>
double Math<T>::calSum(Vector<T> d){
    double sum = 0;
    for(int i = 0; i < d.size(); i++){
        sum += static_cast<double>(d[i]);
    }
    return sum;
}

template <typename T>
double Math<T>::calAvg(Vector<T> d){
    if(d.size() == 0)
        return 0.0;
    return calSum(d) /  d.size();
}

template <typename T>
double Math<T>::calStandardDeviation(Vector <T> d){
    if(d.size() == 0)
        return 0.0;

    double meanAllVal = calAvg(d);
    double sum = 0.0;

    for(int i = 0; i < d.size(); i++){
        sum += (static_cast<double>(d[i]) - meanAllVal) * (static_cast<double>(d[i]) - meanAllVal);
    }

    double variance = sum / (d.size() - 1);

    return std::sqrt(variance);
}

template <typename T>
double Math<T>::calStandardDeviationCustomParam(Vector <T> d, double mean){
    if(d.size() == 0)
        return 0.0;

    double sum = 0.0;

    for(int i = 0; i < d.size(); i++){
        sum += (static_cast<double>(d[i]) - mean) * (static_cast<double>(d[i]) - mean);
    }

    double variance = sum / (d.size() - 1);

    return std::sqrt(variance);
}


template<typename T>
double Math<T>::sPPC(const Vector<T>& x, const Vector<T>& y) {
	double x_mean = calAvg(x);
	double y_mean = calAvg(y);
	double sum = 0.0, x_sum = 0.0, y_sum = 0.0;
	for (int i = 0; i < x.size(); ++i) {
		double dx = static_cast<double>(x[i]) - x_mean;
		double dy = static_cast<double>(y[i]) - y_mean;
		sum += dx * dy;
		x_sum += dx * dx;
		y_sum += dy * dy;
	}

	double den = std::sqrt(x_sum * y_sum);
	return sum / den;
}

template<typename T>
double Math<T>::MAD(const Vector<T>& x) {
	double x_mean = calAvg(x);
	double sum = 0.0;
	for (int i = 0; i < x.size(); ++i) {
		sum += std::abs(static_cast<double>(x[i]) - x_mean);
	}
	return sum / x.size();
}

#endif // MATH_H
