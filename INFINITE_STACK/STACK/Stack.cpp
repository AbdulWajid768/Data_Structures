#include <iostream>
#include "Stack.h"
using namespace std;

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
	min = new T[size];
	max = new T[size];
	sp = -1;
}

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
	T * temp1 = new T[size];
	T * temp2 = new T[size];
	T * temp3 = new T[size];
	for (int i = 0; i <= sp; i = i + 1)
	{
		temp1[i] = stack[i];
		temp2[i] = min[i];
		temp3[i] = max[i];
	}
	delete[] stack;
	delete[] min;
	delete[] max;
	stack = temp1;
	min = temp2;
	max = temp3;
}

template<typename T>
void Stack<T>::shrink()
{
	size = size / 2;
	T * temp1 = new T[size];
	T * temp2 = new T[size];
	T * temp3 = new T[size];
	for (int i = 0; i <= sp; i = i + 1)
	{
		temp1[i] = stack[i];
		temp2[i] = min[i];
		temp3[i] = max[i];
	}
	delete[] stack;
	delete[] min;
	delete[] max;
	stack = temp1;
	min = temp2;
	max = temp3;
}


template<typename T>
void Stack<T>::push(T value)
{
	if (isFull())
	{
		resize();
	}
	sp = sp + 1;
	stack[sp] = value;
	if (sp == 0)
	{
		min[sp] = value;
		max[sp] = value;
	}
	else
	{
		T x = min[sp - 1];
		if (value < x)
		{
			min[sp - 1] = x;
			min[sp] = value;
		}
		else
		{
			min[sp - 1] = min[sp] = x;
		}

		x = max[sp - 1];
		if (value > x)
		{
			max[sp - 1] = x;
			max[sp] = value;
		}
		else
		{
			max[sp - 1] = max[sp] = x;
		}
	}
}

template<typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		if (sp <= size / 4 - 1)
		{
			shrink();
		}
		return stack[sp--];
	}
	else
	{
		cout << "=>STACK IS EMPTY<==";
		return 0;
	}
}

template<typename T>
T Stack<T>::getMin()
{
	if (!isEmpty())
	{
		return min[sp];
	}
	cout << "=>STACK IS EMPTY<==";
	return 0;
}

template<typename T>
T Stack<T>::getMax()
{
	if (!isEmpty())
	{
		return max[sp];
	}
	cout << "=>STACK IS EMPTY<==";
	return 0;
}

template<typename T>
Stack<T>::~Stack()
{
	if (stack)
	{
		delete[] stack;
		delete[] min;
		delete[] max;
		size = 0;
		sp = -1;
	}
}
