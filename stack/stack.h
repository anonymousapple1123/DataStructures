#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* array;           // Dynamic array to store stack elements
    int topIndex;       // Index of top element
    int capacity;       // Current capacity of stack
    static const int DEFAULT_CAPACITY = 10;  // Initial default capacity

    // Private helper methods
    void resize(int newCapacity);
    void expandCapacity();

public:
    // Constructors and Destructor
    Stack();
    Stack(int initialCapacity);
    Stack(const Stack& other);  // Copy constructor
    Stack& operator=(const Stack& other);  // Assignment operator
    ~Stack();

    // Core Stack Operations
    void push(const T& element);
    void pop();
    T& top();
    const T& top() const;

    // Utility Methods
    bool isEmpty() const;
    int size() const;
    int getCapacity() const;
    void clear();

    // Additional Utility Methods
    void display() const;
};

#endif // STACK_H
