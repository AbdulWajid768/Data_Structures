#include "Queue.h"

#include<iostream>
using namespace std;


template<typename T>
bool Queue<T>::isEmpty()
{
	if (noe==0)
	{
		front = -1;
		back = 0;
		return true;
	}
	return false;
}

template<typename T>
bool Queue<T>::isFull()
{
	if (noe == size)
	{
		return true;
	}
	return false;
}

template<typename T>
Queue<T>::Queue(int n)
{
	if (n > 0)
	{
		size = n;
	}
	else
	{
		size = 10;
	}
	queue = new T[size];
	front = -1;
	back = 0;
	noe = 0;
}

template<typename T>
void Queue<T>::enqueue(T value)
{
	if (!isFull())
	{
		cout << "Enqueue = " << value << endl;
		queue[back] = value;
		back = back + 1;
		back = back%size;
		noe = noe + 1;
	}
	else
	{
		cout << "Queue is Full\n";
	}
}

template<typename T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		cout << "Dequeue = ";
		front = front + 1;
		front = front % size;
		noe = noe - 1;
		return queue[front];
	}
	else
	{
		cout << "Queue is Empty\n";
		return 0;
	}
}

template<typename T>
void Queue<T>::reverse()
{
	if (isEmpty())
	{
		return;
	}
	T val = dequeue();
	reverse();
	enqueue(val);
}

template<typename T>
Queue<T>::~Queue()
{
	if (queue)
	{
		delete[] queue;
	}
	queue = nullptr;
	size = back = noe = front = 0;
}


