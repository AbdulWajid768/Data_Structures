#ifndef NODE_H
#define NODE_H
template<typename T>
class Node
{
public:
	T data;
	Node * next;
public:
	Node(T info, Node * ptr = nullptr);
};
#endif // !NODE_H
