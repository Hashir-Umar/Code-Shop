#pragma once

#include "Node.h"

class BinarySearchTree
{
	Node *root;

public:

	BinarySearchTree();
	~BinarySearchTree();
	bool isEmpty();
	Node*getRoot();
	void destroy(Node*, Node* = NULL);
	void insert(Node*, int);
	Node* search(Node*, int);
	Node *findMinVal(Node*&);
	void deleteNode(Node*, int, Node* = NULL);
	void display(Node*);
};