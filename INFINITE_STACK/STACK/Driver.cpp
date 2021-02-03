#include <iostream>
#include "Stack.h"
using namespace std;
void main()
{
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(1);
	stack.push(-1);
	stack.push(5);
	stack.push(8);
	stack.push(7);
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMax() << endl;	
	stack.pop();
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMax() << endl;
	stack.pop();
	cout << stack.getMin() << endl;

}