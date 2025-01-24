#include "/home/fyodor/Working Directory/Git_v2/DataStructures/src/HeaderFiles/stack.h"

// Default Constructor
template <typename T>
Stack<T>::Stack() : 
    array(new T[DEFAULT_CAPACITY]), 
    topIndex(-1), 
    capacity(DEFAULT_CAPACITY) {}

// Parameterized Constructor
template <typename T>
Stack<T>::Stack(int initialCapacity) : 
    array(new T[initialCapacity]), 
    topIndex(-1), 
    capacity(initialCapacity) {
    if (initialCapacity <= 0) {
        throw std::invalid_argument("Capacity must be positive");
    }
}

// Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack& other) : 
    array(new T[other.capacity]), 
    topIndex(other.topIndex), 
    capacity(other.capacity) {
    // Deep copy elements
    for (int i = 0; i <= topIndex; ++i) {
        array[i] = other.array[i];
    }
}

// Assignment Operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    // Check for self-assignment
    if (this != &other) {
        // Delete existing array
        delete[] array;

        // Copy data
        capacity = other.capacity;
        topIndex = other.topIndex;
        array = new T[capacity];

        // Deep copy elements
        for (int i = 0; i <= topIndex; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

// Private Resize Method
template <typename T>
void Stack<T>::resize(int newCapacity) {
    T* newArray = new T[newCapacity];
    
    // Copy existing elements
    for (int i = 0; i <= topIndex; ++i) {
        newArray[i] = array[i];
    }

    // Delete old array and update
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}

// Private Expand Capacity Method
template <typename T>
void Stack<T>::expandCapacity() {
    int newCapacity = capacity * 2;
    resize(newCapacity);
}

// Push Operation
template <typename T>
void Stack<T>::push(const T& element) {
    // Check if stack is full
    if (topIndex + 1 >= capacity) {
        expandCapacity();
    }

    // Add element to top
    array[++topIndex] = element;
}

// Pop Operation
template <typename T>
void Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    topIndex--;
}

// Top Element
template <typename T>
T& Stack<T>::top() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return array[topIndex];
}

// Const Top Element
template <typename T>
const T& Stack<T>::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return array[topIndex];
}

// Check if Empty
template <typename T>
bool Stack<T>::isEmpty() const {
    return topIndex == -1;
}

// Get Current Size
template <typename T>
int Stack<T>::size() const {
    return topIndex + 1;
}

// Get Current Capacity
template <typename T>
int Stack<T>::getCapacity() const {
    return capacity;
}

// Clear Stack
template <typename T>
void Stack<T>::clear() {
    topIndex = -1;
}

// Display Stack Contents
template <typename T>
void Stack<T>::display() const {
    for (int i = 0; i <= topIndex; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
