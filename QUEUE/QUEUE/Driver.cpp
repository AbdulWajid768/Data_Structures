#include <iostream>
#include"Queue.h"
using namespace std;
void main()
{
	Queue<int> q(3);
	for (int i = 0; i <= 2; i++)
	{
		q.enqueue(i);
	}
	q.dequeue();
	q.enqueue(14);
	q.enqueue(6);
	cout << endl;
	for (int i = 1; i <= 3; i = i + 1)
	{
		cout << q.dequeue() << endl;
	}
	
}