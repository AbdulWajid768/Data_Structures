#include "Node.h"
template<typename T>
inline Node<T>::Node(T info, Node * ptr)
{
	data = info;
	next = ptr;
}
