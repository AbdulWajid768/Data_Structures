#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
	T * queue;
	int size;
	int front;
	int back;
	int noe;
	bool isEmpty();
	bool isFull();
public:
	Queue(int n = 10);
	void enqueue(T value);
	T dequeue();
	void reverse();
	~Queue();

};
#endif
