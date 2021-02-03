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
		tail = newNode;
	}
}

template<typename T>
Node<T> * LinkedList<T>::search(T key)
{
	if (!isEmpty())
	{
		Node<T> * temp = head;
		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				return temp;
			}
			temp = temp->next;
		}
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
bool LinkedList<T>::insertAfter(T key, T value)
{
	if (!isEmpty())
	{
		Node<T> * temp = search(key);
		if (temp == tail)
		{
			Node<T> * newNode = new Node<T>(value);
			tail->next = newNode;
			tail = newNode;
			return true;
		}
		if (temp != nullptr)
		{
			Node<T> * newNode = new Node<T>(value, temp->next);
			temp->next = newNode;
			return true;
		}
	}
	return false;
}

template<typename T>
bool LinkedList<T>::insertBefore(T key, T value)
{
	if (!isEmpty())
	{
		if (head->data == key)
		{
			Node<T> * newNode = new Node<T>(value);
			newNode->next = head;
			head = newNode;
			return true;
		}
		else
		{
			Node<T> * temp1 = head;
			Node<T> * temp2 = head->next;
			while (temp2 != nullptr)
			{
				if (temp2->data==key)
				{
					Node<T> * newNode = new Node<T>(value, temp2);
					temp1->next = newNode;
					return true;
				}
				temp1 = temp2;
				temp2 = temp2->next;
			}
		}
	}
	return false;
}

template<typename T>
T LinkedList<T>::deleteBefore(T key)
{
	if (!isEmpty())
	{
		if (head->data == key)
		{
			return T();
		}
		if (head->next != nullptr)
		{
			if (head->next->data == key)
			{
				return deleteAtHead();
			}
		}
		if(head->next->next != nullptr)
		{
			Node<T> * temp1 = head;
			while (temp1->next->next != nullptr)
			{
				if (temp1->next->next->data == key)
				{
					Node<T> * temp2 = temp1->next;
					T val = temp2->data;
					temp1->next = temp2->next;
					delete temp2;
					return val;
				}
				temp1 = temp1->next;
			}
		}
	}
	return T();
}

template<typename T>
T LinkedList<T>::deleteAfter(T key)
{
	Node<T> * temp = search(key);
	if (temp == tail || temp==nullptr)
	{
		return T();
	}
	if (temp->next == tail)
	{
		delete temp->next;
		temp->next = nullptr;
		tail = temp;
	}
	else
	{
		Node<T> * temp1 = temp->next;;
		T val = temp1->data;
		temp->next = temp1->next;
		delete temp1;
		temp1 = nullptr;
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
			Node<T> * temp = head;
			while (temp->next != tail)
			{
				temp = temp->next;
			}
			delete tail;
			temp->next = nullptr;
			tail = temp;
		}
		return val;
	}
	return T();
}

template<typename T>
void LinkedList<T>::reverse()
{
	if (isEmpty())
	{
		return;
	}
	if (head->next == nullptr)
	{
		return;
	}
	Node<T> * temp = head;
	Node<T> * temp1 = temp->next;
	Node<T> * temp3;
	temp->next = nullptr;
	while (temp1)
	{
		temp3 = temp1->next;
		temp1->next = temp;
		temp = temp1;
		temp1 = temp3;
	}
	temp = head;
	head = tail;
	tail = temp;
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
		Node<T> * temp1 = head;
		Node<T> * temp2 = head;
		while (temp1 != nullptr)
		{
			temp1 = temp1->next;
			delete temp2;
			temp2 = temp1;
		}
		head = tail = nullptr;
	}
}

template<typename T>
void LinkedList<T>::recReverse()
{
	if (isEmpty())
	{
		return;
	}
	T val = deleteAtHead();
	recReverse();
	insertAtTail(val);
}
