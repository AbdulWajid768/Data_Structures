#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
using namespace std; 
#include "TreeNode.h"
#include "Stack.h"


template<typename T>
class BinaryTree
{
	TreeNode<T> * root;
public:
	BinaryTree(TreeNode<T> * r = nullptr);
	void recursivePreOrder(TreeNode<T> * r);
	void recursiveInOrder(TreeNode<T> * r);
	void recursivePostOrder(TreeNode<T> * r);
	void preOrder();
	void inOrder();
	void postOrder(); 
	~BinaryTree();
};
#endif // !BINARYTREE

