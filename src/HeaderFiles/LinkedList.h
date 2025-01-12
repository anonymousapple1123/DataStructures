#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct Node{
  T data;
  Node* next;
  Node* prev;
  Node(T data) : data(data), next(nullptr), prev(nullptr) {}  
};
template<typename T>
class LinkedList{
public:
LinkedList();
void insert(T value, int index);
void remove(int index);
int search(T data);
int size();
void display();

~LinkedList();

private:
   Node* head;      

};

#endif