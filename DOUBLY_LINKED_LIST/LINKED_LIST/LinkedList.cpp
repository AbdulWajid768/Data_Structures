#include "LinkedList.h"
#include <iostream>
using namespace std;
template<typename T>
LinkedList<T>::LinkedList()
{
	head = tail = nullptr;
}

template<typename T>
void LinkedList<T>::insertAtHead(T value)
{
	Node<T> * newNode = new Node<T>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

template<typename T>
void LinkedList<T>::insertAtTail(T value)
{
	Node<T> * newNode = new Node<T>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else

	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template<typename T>
Node<T> * LinkedList<T>::search(T key)
{
	if (!isEmpty())
	{
		Node<T> * temp1 = head;
		Node<T> * temp2 = tail;
		do
		{
			if (temp1->data == key)
			{
				return temp1;
			}
			if (temp2->data == key)
			{
				return temp2;
			}
			temp1 = temp1->next;
			temp2 = temp2->prev;
		} while (temp1 != nullptr && temp1->prev != temp2 &&  temp1->prev != temp2->next);
	}
	return nullptr;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
bool LinkedList<T>::insertAfter(T key, T value)//
{
	if (!isEmpty())
	{
		if (tail->data == value)
		{
			insertAtTail(value);
			return true;
		}
		Node<T> * temp = search(key);
		if (temp == nullptr)
		{
			return false;
		}
		Node<T> * newNode = new Node<T>(value, temp, temp->next);
		temp->next->prev = newNode;
		temp->next = newNode;
		return true;
	}
	return false;
}

template<typename T>
bool LinkedList<T>::insertBefore(T key, T value)//
{
	if (!isEmpty())
	{
		if (head->data == key)
		{
			insertAtHead(value);
			return true;
		}
		Node<T> * temp = search(key);
		if (temp == nullptr)
		{
			return false;
		}
		Node<T> * newNode = new Node<T>(value, temp->prev, temp);
		temp->prev->next = newNode;
		temp->prev = newNode;
	}
	return false;
}

template<typename T>
T LinkedList<T>::deleteBefore(T key)//
{
	if (!isEmpty())
	{
		if (head->data == key)
		{
			return T();
		}
		if (head->next->data == key)
		{
			return deleteAtHead();
		}
		Node<T> * temp = search(key);
		if (temp == nullptr)
		{
			return T();
		}
		Node<T> * temp1 = temp->prev;
		temp1->prev->next = temp;
		temp->prev = temp->prev;
		T val = temp1->data;
		delete temp1;
		return val;
	}
	return T();
}

template<typename T>
T LinkedList<T>::deleteAfter(T key)//
{
	if (!isEmpty())
	{
		Node<T> * temp = search(key);
		if (temp == nullptr || temp == tail)
		{
			return T();
		}
		if (temp->next == tail)
		{
			return deleteAtTail();
		}
		Node<T> * temp1 = temp->next;
		temp->next = temp1->next;
		temp1->next->prev = temp;
		T val = temp1->data;
		delete temp1;
		return val;
	}
	return T();
}

template<typename T>
T LinkedList<T>::deleteAtHead()
{
	if (!isEmpty())
	{
		T val = head->data;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node<T> * temp = head->next;
			delete head;
			head = temp;
			head->prev = nullptr;
		}
		return val;
	}
	return T();
}

template<typename T>
T LinkedList<T>::deleteAtTail()
{
	if (!isEmpty())
	{
		T val = tail->data;
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else 
		{
			Node<T> * temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
			temp = nullptr;
		}
		return val;
	}
	return T();
}

template<typename T>
void LinkedList<T>::displayAll()
{
	if (!isEmpty())
	{
		Node<T> * temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	if (!isEmpty())
	{
		Node<T> * temp1 = head, temp2;
		while (temp1 != nullptr)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			delete temp2;
		}
		head = tail = nullptr;
	}
}

