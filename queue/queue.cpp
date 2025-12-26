#include <stdexcept>

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T value) {
    Node* newNode = new Node(value);
    if (rear) {
        rear->next = newNode;
    } else {
        front = newNode; // Queue was empty
    }
    rear = newNode;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = front;
    T value = front->data;
    front = front->next;
    if (!front) {
        rear = nullptr; // Queue is now empty
    }
    delete temp;
    return value;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data;
}
