
template<typename T>
LinkedList<T>::LinkedList() : head(nullptr) {}

template<typename T>
void LinkedList<T>::insert(T value, int index) {
    // Create new node
    Node<T>* newNode = new Node<T>(value);

    // If list is empty
    if (head == nullptr) {
        if (index != 0) {
            throw std::out_of_range("Invalid index for empty list");
        }
        head = newNode;
        return;
    }

    // Insert at beginning
    if (index == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // Traverse to insertion point
    Node<T>* current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }

    // Check if index is valid
    if (current == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }

    // Link new node
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

template<typename T>
void LinkedList<T>::remove(int index) {
    if (head == nullptr) {
        throw std::out_of_range("Cannot remove from empty list");
    }

    // Remove first element
    if (index == 0) {
        Node<T>* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
        return;
    }

    // Traverse to node before removal
    Node<T>* current = head;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    // Validate index
    if (current == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }

    // Adjust links
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

template<typename T>
int LinkedList<T>::search(T data) const {
    Node<T>* current = head;
    int index = 0;

    while (current != nullptr) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; // Not found
}

template<typename T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T>* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

template<typename T>
void LinkedList<T>::display() const {
    Node<T>* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}
