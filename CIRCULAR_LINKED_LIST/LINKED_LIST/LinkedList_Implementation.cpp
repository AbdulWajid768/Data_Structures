#include "LinkedList.cpp"
template class LinkedList<int>;



//#include "LinkedList.h"
//#include <iostream>
//using namespace std;
//template<typename T>
//LinkedList<T>::LinkedList()
//{
//	head = tail = nullptr;
//}
//
//template<typename T>
//void LinkedList<T>::insertAtHead(T value)
//{
//	Node<T> * newNode = new Node<T>(value);
//	if (isEmpty())
//	{
//		head = tail = newNode;
//	}
//	else
//	{
//		newNode->next = head;
//		head->prev = newNode;
//		head = newNode;
//	}
//}
//
//template<typename T>
//void LinkedList<T>::insertAtTail(T value)
//{
//	Node<T> * newNode = new Node<T>(value);
//	if (isEmpty())
//	{
//		head = tail = newNode;
//	}
//	else
//
//	{
//		tail->next = newNode;
//		newNode->prev = tail;
//		tail = newNode;
//	}
//}
//
//template<typename T>
//Node<T> * LinkedList<T>::search(T key)
//{
//	if (!isEmpty())
//	{
//		Node<T> * temp = head;
//		while (temp != nullptr)
//		{
//			if (temp->data == key)
//			{
//				return temp;
//			}
//			temp = temp->next;
//		}
//	}
//	return nullptr;
//}
//
//template<typename T>
//bool LinkedList<T>::isEmpty()
//{
//	if (head == nullptr)
//	{
//		return true;
//	}
//	return false;
//}
//
//template<typename T>
//bool LinkedList<T>::insertAfter(T key, T value)//
//{
//	Node<T> * temp = search(key);
//	if (temp == nullptr)
//	{
//		return false;
//	}
//	Node<T> * newNode = new Node<T>(value, temp, temp->next);
//	temp->next->prev = newNode;
//	temp->next = newNode;
//	return true;
//}
//
//template<typename T>
//bool LinkedList<T>::insertBefore(T key, T value)//
//{
//	if (!isEmpty())
//	{
//		if (head->data == key)
//		{
//			insertAtHead(value);
//			return true;
//		}
//		else
//		{
//			Node<T> * temp1 = head;
//			Node<T> * temp2 = head->next;
//			while (temp2 != nullptr)
//			{
//				if (temp2->data == key)
//				{
//					Node<T> * newNode = new Node<T>(value, temp1, temp2);
//					temp1->next = newNode;
//					temp2->prev = newNode;
//					return true;
//				}
//				temp1 = temp2;
//				temp2 = temp2->next;
//			}
//		}
//	}
//	return false;
//}
//
//template<typename T>
//T LinkedList<T>::deleteBefore(T key)//
//{
//	if (!isEmpty())
//	{
//		if (head->data == key)
//		{
//			return T();
//		}
//		if (head->next != nullptr)
//		{
//			Node<T> * temp1 = search(value);
//			if (temp)
//			{
//				Node<T> * temp2 = temp1->prev;
//				T val = temp2->data;
//				temp1->prev = temp2->prev;
//				temp2->prev->next = temp1;
//				delete temp2;
//				return val;
//			}
//		}
//	}
//	return T();
//}
//
//template<typename T>
//T LinkedList<T>::deleteAfter(T key)//
//{
//	Node<T> * temp = search(key);
//	if (temp == tail)
//	{
//		return T();
//	}
//	if (temp->next != nullptr)
//	{
//		Node<T> * temp1 = temp->next;
//		temp1->next->prev = temp;
//		temp->next = temp1->next;
//		delete temp1;
//		temp1 = nullptr;
//	}
//	return T();
//}
//
//template<typename T>
//T LinkedList<T>::deleteAtHead()
//{
//	if (!isEmpty())
//	{
//		T val = head->data;
//		if (head == tail)
//		{
//			delete head;
//			head = tail = nullptr;
//		}
//		else
//		{
//			Node<T> * temp = head->next;
//			delete head;
//			head = temp;
//			head->prev = nullptr;
//		}
//		return val;
//	}
//	return T();
//}
//
//template<typename T>
//T LinkedList<T>::deleteAtTail()
//{
//	if (!isEmpty())
//	{
//		T val = tail->data;
//		if (head == tail)
//		{
//			delete head;
//			head = tail = nullptr;
//		}
//		else
//		{
//			Node<T> * temp = tail;
//			tail = tail->prev;
//			tail->next = nullptr;
//			delete temp;
//			temp = nullptr;
//		}
//		return val;
//	}
//	return T();
//}
//
//template<typename T>
//void LinkedList<T>::displayAll()
//{
//	if (!isEmpty())
//	{
//		Node<T> * temp = head;
//		while (temp != nullptr)
//		{
//			cout << temp->data << " ";
//			temp = temp->next;
//		}
//		cout << endl;
//	}
//}
//
//template<typename T>
//LinkedList<T>::~LinkedList()
//{
//	if (!isEmpty())
//	{
//		Node<T> * temp1 = head;
//		Node<T> * temp2 = head;
//		while (temp1 != nullptr)
//		{
//			temp1 = temp1->next;
//			delete temp2;
//			temp2 = temp1;
//		}
//		head = tail = nullptr;
//	}
//}
