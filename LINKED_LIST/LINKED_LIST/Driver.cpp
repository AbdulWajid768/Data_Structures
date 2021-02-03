#include<iostream>
#include "LinkedList.h"
using namespace std;
void main()
{
	LinkedList<int> l;
	l.insertAtTail(1);
	l.insertAtTail(31);
	l.insertAtTail(14);
	l.insertAtTail(15);
	l.insertAtTail(11);
	l.displayAll();
	l.recReverse();
	l.displayAll();
}