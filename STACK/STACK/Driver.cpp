#include <iostream>
#include "Stack.h"
using namespace std;
void main()
{
	Stack<int> stack(3);
	cout << stack.pop() << endl;
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;	
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	stack.push(4);
	stack.push(5);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
}