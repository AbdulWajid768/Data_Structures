#ifndef STACK_H
#define STACK_H
template<typename T>
class Stack
{
private:
	T * stack;
	T * min;
	T * max;
	int sp;//stack ptr
	int size;




	bool isEmpty();
	bool isFull();
	void resize();
	void shrink();
public:
	Stack(int n = 10);
	void push(T value);
	T pop();
	T getMin();
	T getMax();
	~Stack();
};
#endif STACK_H