#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<typename T>
struct Node{
  int ListSize;
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
int search(T data) const ;
int size() const ;
void display() const ;
~LinkedList();

private:
   Node* head;      

};

#endif