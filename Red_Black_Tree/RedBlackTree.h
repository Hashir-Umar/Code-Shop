#pragma once

#include "Node.h"

class RedBlackTree
{

	Node* root;
	Node* insertBST(Node *current, int x);
	void insert_in_RBT(Node *, int x);
	Node* search(Node*, int);
	void destroy(Node*&);
	void fix(Node*&);
	void leftRotate(Node*);
	void rightRotate(Node*);
	int heightOfTheTree(Node*);
	void currentLevel(Node*, int);
	void displayLevel(Node *);

public:
	RedBlackTree();
	~RedBlackTree();
	bool isEmpty();
	void insert(int);
	Node* searchData(int);
	void display();
};