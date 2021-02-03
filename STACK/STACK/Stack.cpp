#include <iostream>
#include "Stack.h"
using namespace std;
template<typename T>
bool Stack<T>::isEmpty()
{
	if (sp == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool Stack<T>::isFull()
{
	if (sp == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
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
		size = n;
	else
		size = 10;
		stack = new T[size];
		sp = -1;
}

template<typename T>
void Stack<T>::push(T value)
{
	if (!isFull())
	{
		cout << "PUSH=" << value << endl;
		stack[++sp] = value;
	}
	else
	{
		cout << "=>STACK IS FULL<=\n";
	}
}

template<typename T>
T Stack<T>::pop()
{
	if (!isEmpty())
	{
		cout << "POP=";
		return stack[sp--];
	}
	else
	{
		cout << "=>STACK IS EMPTY<=";
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
