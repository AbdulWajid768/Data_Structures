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
	l.deleteAtHead();
	l.displayAll();
	l.deleteAtTail();
	l.displayAll();
	l.insertAfter(31,78);
	l.displayAll();
	l.insertAtHead(1);
	l.displayAll();
	l.insertBefore(114,56);
	l.displayAll();
	l.deleteBefore(31);
	l.displayAll();
}