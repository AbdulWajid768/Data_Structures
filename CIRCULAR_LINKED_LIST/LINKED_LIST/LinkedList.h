#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
template<typename T>
class LinkedList
{
	Node<T> * head;
	Node<T> * tail;
public:
	LinkedList();
	void insertAtHead(T value);
	void insertAtTail(T value);
	Node<T> * search(T key);
	bool isEmpty();
	bool insertAfter(T key, T value);
	bool insertBefore(T key, T value);
	T deleteBefore(T key);//
	T deleteAfter(T key);//
	T deleteAtHead();
	T deleteAtTail();
	void displayAll();
	~LinkedList();
};
#endif // !LINKEDLIST_H

