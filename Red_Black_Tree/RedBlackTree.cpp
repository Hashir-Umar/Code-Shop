#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree()
{
	root = NULL;
}

RedBlackTree::~RedBlackTree()
{
	destroy(root);
}

bool RedBlackTree::isEmpty()
{
	return root == NULL;
}

void RedBlackTree::insert(int val)
{
	insert_in_RBT(root, val);
}

void RedBlackTree::insert_in_RBT(Node *current, int x)
{
	if (root == NULL)
		root = insertBST(root, x);
	else
	{
		current = insertBST(current, x);
		fix(current);
	}
}

Node* RedBlackTree::insertBST(Node*current, int x)
{
	if (!root)
	{
		root = new Node(x, NULL, NULL, NULL, 'B');
		return root;
	}
	else
	{
		if (x <= current->data)
		{
			if (current->left)
				return insertBST(current->left, x);
			else
			{
				current->left = new Node(x, current);
				return current->left;
			}
		}
		else if (x > current->data)
		{
			if (current->right)
				return insertBST(current->right, x);
			else
			{
				current->right = new Node(x, current);
				return current->right;
			}
		}

	}
}


void RedBlackTree::destroy(Node *&current)
{
	if (root)
	{
		if (current)
		{
			destroy(current->left);
			destroy(current->right);

			if (!current->left && !current->right)
			{
				if (root == current)
				{
					delete root;
					root = NULL;
				}
				else
				{
					if (current->parent->left == current)
						current->parent->left = NULL;
					else
						current->parent->right = NULL;

					delete current;
				}
			}
		}
	}
}


void RedBlackTree::fix(Node *&current)
{
	while (current)
	{
		if (current == root || (current->color == 'B' || current->parent->color == 'B'))
			return;

		if (current->parent == current->parent->parent->left)
		{
			if (current->parent->color == 'R')
			{
				Node *uncle = current->parent->parent->right;

				if (uncle && uncle->color == 'R')
				{
					uncle->color = 'B';
					current->parent->color = 'B';
					if (uncle->parent != root)
						current->parent->parent->color = 'R';
				}
				else
				{
					if (current->parent->right == current)
					{
						current = current->parent;
						leftRotate(current);
					}

					char colorOfTheParent = current->parent->color;
					current->parent->color = current->parent->parent->color;
					current->parent->parent->color = colorOfTheParent;
					rightRotate(current->parent->parent);

				}
			}
		}
		else
		{
			if (current->parent->color == 'R')
			{
				Node *uncle = current->parent->parent->left;

				if (uncle && uncle->color == 'R')
				{
					uncle->color = 'B';
					current->parent->color = 'B';
					if (uncle->parent != root)
						current->parent->parent->color = 'R';
				}
				else if (!uncle || uncle->color == 'B')
				{
					if (current->parent->left == current)
					{
						current = current->parent;
						rightRotate(current);
					}

					char colorOfTheParent = current->parent->color;
					current->parent->color = current->parent->parent->color;
					current->parent->parent->color = colorOfTheParent;
					leftRotate(current->parent->parent);

				}

			}
		}

		current = current->parent->parent;
	}
}


void RedBlackTree::leftRotate(Node *current)
{
	Node *temp = current->right;

	if (!temp)
		return;

	if (temp->left)
		temp->left->parent = current;

	current->right = temp->left;
	temp->left = current;

	if (temp->parent == root)
		root = temp;
	else
	{
		if (current->parent->right == current)
			current->parent->right = temp;
		else
			current->parent->left = temp;
	}

	temp->parent = current->parent;
	current->parent = temp;
}


void RedBlackTree::rightRotate(Node *current)
{
	Node *temp = current->left;

	if (!temp)
		return;

	if (temp->right)
		temp->right->parent = current;

	current->left = temp->right;
	temp->right = current;

	if (temp->parent == root)
		root = temp;
	else
	{
		if (current->parent->right == current)
			current->parent->right = temp;
		else
			current->parent->left = temp;
	}

	temp->parent = current->parent;
	current->parent = temp;

}


Node* RedBlackTree::searchData(int data)
{
	return search(root, data);
}


Node* RedBlackTree::search(Node *current, int x)
{
	if (root)
	{
		if (!current)
			return NULL;

		if (current->data == x)
			return current;
		else if (current->data > x)
			return search(current->left, x);
		else if (current->data < x)
			return search(current->right, x);
	}
	else
		cout << "Tree is Empty!!!\n\n";

}


int RedBlackTree::heightOfTheTree(Node*  current)
{
	if (current)
	{
		int leftHeight = heightOfTheTree(current->left);
		int rightHeight = heightOfTheTree(current->right);

		if (leftHeight < rightHeight)
			return(rightHeight + 1);
		else
			return(leftHeight + 1);
	}
	else
		return 0;
}


void RedBlackTree::currentLevel(Node*  current, int level)
{
	if (current)
	{
		if (level == 0)
			current->display();
		else if (level > 0)
		{
			currentLevel(current->left, level - 1);
			currentLevel(current->right, level - 1);
		}
	}
}


void RedBlackTree::displayLevel(Node *current)
{
	if (!root)
		cout << "Tree is Empty!!!" << endl;
	else
	{
		cout << endl;
		int height = heightOfTheTree(current);
		for (int i = 0; i <= height; i++)
		{
			currentLevel(current, i);
			cout << endl << endl;
		}
	}
}


void RedBlackTree::display()
{
	displayLevel(root);
}