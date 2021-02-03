#include "Node.h"
template<typename T>
inline Node<T>::Node(T info, Node * ptr1, Node * ptr2 = nullptr)
{
	data = info;
	prev = ptr1;
	next = ptr2;
}
