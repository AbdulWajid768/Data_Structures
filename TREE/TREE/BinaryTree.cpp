#include "BinaryTree.h" 

template<typename T>
BinaryTree<T>::BinaryTree(TreeNode<T> * r = nullptr)
{
	root = r;
}

template<typename T>
void BinaryTree<T>::recursivePreOrder(TreeNode<T> * r)
{
	if (r)
	{
		cout << r->data << " ";
		recursivePreOrder(r->left);
		recursivePreOrder(r->right);
	}
}

template<typename T>
void BinaryTree<T>::recursiveInOrder(TreeNode<T> * r)
{
	if (r)
	{
		recursivePreOrder(r->left);
		cout << r->data << " ";
		recursivePreOrder(r->right);
	}
}

template<typename T>
void BinaryTree<T>::recursivePostOrder(TreeNode<T> * r)
{
	if (r)
	{
		recursivePreOrder(r->left);
		recursivePreOrder(r->right);
		cout << r->data << " ";
	}
}

template<typename T>
void BinaryTree<T>::preOrder()
{
	if (root)
	{
		TreeNode<T> * temp;
		Stack<TreeNode<T> *> stack;
		stack.push(root);
		while (!stack.isEmpty())
		{
			temp = stack.pop();
			cout << temp->data << " ";
			if (temp->right)
			{
				stack.push(temp->right);
			}
			if (temp->left)
			{
				stack.push(temp->left);
			}
		}
	}
	cout << endl;
}

template<typename T>
void BinaryTree<T>::inOrder()
{
	TreeNode<T> * temp = root;
	Stack<TreeNode<T> *> stack;
	while (temp)
	{
		while (temp)
		{
			if (temp->right)
			{
				stack.push(temp->right);
			}
			stack.push(temp);
			temp = temp->left;
		}
		temp = stack.pop();
		while (!stack.isEmpty() && temp->right != nullptr)
		{
			cout << temp->data << " ";
			temp = stack.pop();
		}
		cout << temp->data << " ";
		if (!stack.isEmpty())
		{
			temp = stack.pop();
		}
		else
		{
			temp = nullptr;
		}
	}

}

template<typename T>
void BinaryTree<T>::postOrder()
{
	TreeNode<T> * temp = root, *temp1 = root;
	Stack<TreeNode<T> *> stack;
	while (temp)
	{
		while (temp->left)
		{
			stack.push(temp);
			temp = temp->left;
		}
		while (temp!=nullptr && (temp->right==nullptr||temp->right==temp1))
		{
			cout << temp->data << " ";
			temp1 = temp;
			if (stack.isEmpty())
			{
				return;
			}
			temp = stack.pop();
		}
		stack.push(temp);
		temp = temp->right;
	}
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
}
