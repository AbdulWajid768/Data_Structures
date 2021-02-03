#include<iostream>
#include "Stack.h"
using namespace std;
//USING STACK
//int postfix()
//{
//	Stack<int> stack;
//	int x, y, z;
//	char ch;
//	cout << "Enter the expression: ";
//	do
//	{
//		cin.get(ch);
//		if (ch >= '0' && ch <= '9')
//		{
//			stack.push(ch - 48);
//		}
//		else if (ch == '+')
//		{
//			x = stack.pop();
//			y = stack.pop();
//			stack.push(x + y);
//		}
//		else if (ch == '-')
//		{
//			y = stack.pop();
//			x = stack.pop();
//			stack.push(x - y);
//		}
//	} while (ch != '\n');
//	return stack.pop();
//}

void infixToPostfix(string s)
{
	Stack<char> stack;
	char p[100], ch;
	int i = 0, j = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			p[j] = s[i];
			j = j + 1;
		}
		if (s[i] == '^')
		{
			stack.push(s[i]);
		}
		if (s[i] == '+' || s[i] == '-')
		{
			ch = stack.pop();
			while (ch != 0)
			{
				p[j] = ch;
				j = j + 1;
				ch = stack.pop();
			}
			stack.push(s[i]);
		}
		if (s[i] == '*' || s[i] == '/')
		{
			ch = stack.pop();
			while (ch != 0 && ch != '+' && ch != '-')
			{
				p[j] = ch;
				j = j + 1;
				ch = stack.pop();
			}
			if (ch != 0)
			{
				stack.push(ch);
			}
			stack.push(s[i]);
		}
		i = i + 1;
	}
	ch = stack.pop();
	while (ch != 0)
	{
		p[j] = ch;
		j = j + 1;
		ch = stack.pop();
	}
	p[j] = '\0';
	cout << p << endl;
}

void main()
{
	string s = "1+2*4/8";
	infixToPostfix(s);
}