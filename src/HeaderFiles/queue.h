#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    bool isEmpty() const;
    T peek() const;
};

#include "queue.cpp" // Include the implementation file

#endif // QUEUE_H
