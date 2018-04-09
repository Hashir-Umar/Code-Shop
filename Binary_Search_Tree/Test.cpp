#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;

	bst.insert(bst.getRoot(), 9);
	bst.insert(bst.getRoot(), 12);
	bst.insert(bst.getRoot(), 13);

	std::cout << "Tree:-" << std::endl;
	bst.display(bst.getRoot());

	std::cout << "\n\nTree After Deleteing 13:-" << std::endl;
	bst.deleteNode(bst.getRoot(), 13);
	
	bst.display(bst.getRoot());

	std::cout << std::endl;
	return 0;
}