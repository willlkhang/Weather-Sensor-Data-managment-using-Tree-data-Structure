// vector.h

//---------------------------------------------------------------------------------
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//---------------------------------------------------------------------------------

	/**
	 * @class Vector
	 * @brief A minimal dynamic array implementation using templates
	 *
	 * This class mimics a simplified version of std::vector, supporting dynamic resizing,
	 * element access, and basic operations like adding and removing elements.\n
	 * The vector automatically doubles its capacity when full to accommodate new elements.\n
	 *
	 * @tparam T The type of elements stored in the vector
	 *
	 * @author Minh Khang Nguyen
	 * @version 01
	 *
	 * @todo Add bounds checking for subscript operator
	 * @bug Subscript operator may access invalid memory if index is out of range
	 */
template <class T>
class Vector{
public:

        /**
		 * @brief Default constructor
		 *
		 * Initializes an empty vector with capacity 1.
		 *
		 * @return void
		 * @post Vector is empty with capacity 1
		 */
    Vector();

        /**
		 * @brief Parameterized constructor
		 *
		 * Initializes a vector with the specified size and capacity.
		 * If size is negative, initializes an empty vector with capacity 1.
		 *
		 * @param n Initial size of the vector
		 * @return void
		 * @post Vector has size n (or 0 if n < 0) and capacity n (or 1 if n <= 0)
		 */
    Vector(int n); // constructor

        /**
		 * @brief Destructor
		 *
		 * Deallocates the internal array and resets the vector's state.
		 *
		 * @return void
		 * @post Vector is empty and memory is freed
		 */
    ~Vector();

        /**
		 * @brief Copy constructor
		 *
		 * Creates a new vector as a deep copy of another vector.
		 *
		 * @param newVec The vector to copy from
		 * @return void
		 * @pre newVec must be a valid vector
		 * @post Vector is a deep copy of newVec
		 */
    Vector(const Vector<T> &newVec);

        /**
		 * @brief Copy assignment operator
		 *
		 * Assigns one vector to another, performing a deep copy.
		 *
		 * @param newVec The vector to copy from
		 * @return Vector<T>& - Reference to this vector
		 * @pre newVec must be a valid vector
		 * @post Vector is a deep copy of newVec
		 */
    Vector<T> &operator = (const Vector<T> &newVec); // assign vector to vector

        /**
		 * @brief Subscript operator (modifiable)
		 *
		 * Provides access to the element at the specified index.
		 *
		 * @param i Index of the element
		 * @return T& - Reference to the element at index i
		 * @pre i must be in range [0, size())
		 * @warning No bounds checking is performed
		 */
    T &operator[](int i); //modifiable

        /**
		 * @brief Subscript operator (read-only)
		 *
		 * Provides read-only access to the element at the specified index.
		 *
		 * @param i Index of the element
		 * @return const T& - Constant reference to the element at index i
		 * @pre i must be in range [0, size())
		 * @warning No bounds checking is performed
		 */
    const T &operator[](int i) const; // non modifiable

        /**
		 * @brief Gets the current size of the vector
		 *
		 * Returns the number of elements currently stored in the vector.
		 *
		 * @return int - The number of elements in the vector
		 */
    int size() const; // vector size

        /**
		 * @brief Adds an element to the end of the vector
		 *
		 * Appends the specified value to the vector, resizing if necessary.
		 *
		 * @param value The value to be added
		 * @return void
		 * @post Vector size is increased by 1
		 */
    void add_to_back(const T &value);

    //void remove_from_back();


private:
    /// Current number of elements in the vector
    int length;
    /// Current capacity of the internal array
    int cap;
    /// Pointer to the dynamically allocated array
    T* array;
};

//==========================================implementation=================================================

//capacity = 1 because the pointer is pointing to somewhere
template<class T>
Vector<T>::Vector() : length(0), cap(1), array(new T[1]) {}

//this vector address some corner cases such as n < 0 and capacity <= 0.
template<class T>
Vector<T>::Vector(int n) : length((n < 0) ? 0 : n), cap((n <= 0) ? 1 : n), array(new T[cap]) {}


//destructor
template<class T>
Vector<T>::~Vector(){
    delete[] array;
    length = 0;
    cap = 0;

}

template<class T>
Vector<T>::Vector(const Vector<T>& newVec) : length(newVec.length), cap(newVec.cap), array(new T[newVec.cap]) {
    for (int i = 0; i < length; ++i) {
        array[i] = newVec.array[i];
    }
}

template<class T>
Vector<T> &Vector<T>::operator = (const Vector<T> &newVec){
    if (this == &newVec) return *this;

    delete[] array;
    length = newVec.length;
    cap = newVec.cap;
    array = new T[cap];

    for(int i = 0; i < length; i++){
        array[i] = newVec.array[i];
    }

    return *this;
}

template<class T>
T &Vector<T>::operator[](int i){
    return array[i];
}

template<class T>
const T &Vector<T>::operator[](int i) const{
    return array[i];
}

template<class T>
int Vector<T>::size() const{
    return length;
}

template<class T>
void Vector<T>::add_to_back(const T& value){
    if(length >= cap){
        int newCap = (cap == 0) ? 1 : cap * 2;
        T* newArray = new T[newCap];
        for(int i = 0; i < length; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        cap = newCap;
    }
    array[length] = value;
    ++length;
}



#endif // VECTOR_H_INCLUDED
