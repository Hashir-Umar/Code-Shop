#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	destroy(root);
}

bool BinarySearchTree::isEmpty()
{
	return root == NULL;
}

Node* BinarySearchTree::getRoot()
{
	return root;
}

void BinarySearchTree::destroy(Node *current, Node *parrent)
{
	if (root)
	{
		if (current)
		{
			destroy(current->left, current);
			destroy(current->right, current);

			if (!current->left && !current->right)
			{
				if (root == current)
				{
					delete root;
					root = NULL;
				}
				else
				{
					if (parrent->left == current)
						parrent->left = NULL;
					else
						parrent->right = NULL;

					delete current;
					current = NULL;
				}
			}
		}
	}
}

void BinarySearchTree::insert(Node *current, int val)
{
	if (!root)
		root = new Node(val);
	else
	{
		if (val <= current->data)
		{
			if (!current->left)
				current->left = new Node(val);
			else
				insert(current->left, val);
		}
		else if (val > current->data)
		{
			if (!current->right)
				current->right = new Node(val);
			else
				insert(current->right, val);
		}

	}
}

Node* BinarySearchTree::search(Node *current, int value)
{
	if (root)
	{
		if (!current)
			return NULL;

		if (current->data == value)
			return current;
		else if (current->data > value)
			return search(current->left, value);
		else if (current->data < value)
			return search(current->right, value);
	}
	else
		cout << "Tree is Empty!!!";

}

Node* BinarySearchTree::findMinVal(Node*& current)
{
	Node* temp = current;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
}

void BinarySearchTree::deleteNode(Node *current, int value, Node*parrent)
{
	if (current == NULL)
		return;

	if (value < current->data)
		deleteNode(current->left, value, current);
	else if (value > current->data)
		deleteNode(current->right, value, current);
	else
	{
		if (!current->left && !current->right)
		{
			if (current == root)
			{
				delete root;
				root = NULL;
			}
			else
			{
				if (parrent->left == current)
					parrent->left = NULL;
				else
					parrent->right = NULL;
			}
		}
		else if (!current->right)
		{
			if (current == root)
			{
				root = current->left;
				delete current;
			}
			else
			{
				parrent->left = current->left;
				delete current;
				current = NULL;
			}
		}
		else if (!current->left)
		{
			if (current == root)
			{
				root = current->right;
				delete current;
			}
			else
			{
				parrent->right = current->right;
				delete current;
				current = NULL;
			}
		}
		else
		{
			Node* temp = findMinVal(current->right);
			current->data = temp->data;
			deleteNode(current->right, temp->data, current);
		}
	}
}

void BinarySearchTree::display(Node *current)
{
	if (!root)
		cout << "Tree is Empty!!!" << endl;
	{
		if (current)
		{
			display(current->left);
			cout << current->data << " ";
			display(current->right);
		}
	}
}