#include <iostream>
#include "Stack.h"
using namespace std;
template<typename T>
bool Stack<T>::isEmpty()
{
	if (sp == -1)
		return true;
	else
		return false;
}

template<typename T>
bool Stack<T>::isFull()
{
	if (sp == size - 1)
		return true;
	else
		return false;
}

template<typename T>
void Stack<T>::resize()
{
	size = size * 2;
	T * temp = new T[size];
	for (int i = 0; i <= sp; i = i + 1)
	{
		temp[i] = stack[i];
	}
	delete[] stack;
	stack = temp;
}

template<typename T>
void Stack<T>::shrink()
{
	size = size / 2;
	T * temp = new T[size];
	for (int i = 0; i <= sp; i = i + 1)
	{
		temp[i] = stack[i];
	}
	delete[] stack;
	stack = temp;
}

template<typename T>
Stack<T>::Stack()
{
	size = 10;
	stack = new T[size];
	sp = -1;
}

template<typename T>
Stack<T>::Stack(int n)
{
	if (n > 0)
	{
		size = n;
	}
	else
	{
		size = 10;
	}
	stack = new T[size];
	sp = -1;
}

template<typename T>
void Stack<T>::push(T value)
{
	if (isFull())
		resize();
	stack[++sp] = value;
}

template<typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		if (sp <= size / 4 - 1)
			shrink();
		return stack[sp--];
	}
	else
	{
		return 0;
	}
}

template<typename T>
Stack<T>::~Stack()
{
	if (stack)
	{
		delete[] stack;
		size = 0;
		sp = -1;
	}
}