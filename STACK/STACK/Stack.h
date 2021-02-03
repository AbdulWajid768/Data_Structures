#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
private:
	T * stack;
	int sp;//stack ptr
	int size;
	bool isEmpty();
	bool isFull();
public:
	Stack();
	Stack(int n);
	void push(T value);
	T pop();
	~Stack();
};
#endif STACK_H