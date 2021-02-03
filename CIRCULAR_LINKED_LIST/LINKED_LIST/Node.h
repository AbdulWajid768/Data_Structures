#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
public:
	T data;
	Node * prev;
	Node * next;
public:
	Node(T info, Node * ptr1 = nullptr, Node * ptr2 = nullptr);
};
#endif // !NODE_H
