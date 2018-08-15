#include "binary-tree.h"
#include "binary-search-tree.h"

int main() {
	BinarySearchTree<int>* tree = new BinarySearchTree<int>();
	tree->add(10);
	tree->add(6);
	tree->add(7);
	tree->add(8);
	tree->add(9);
	tree->add(1);
	tree->add(2);
	tree->add(3);
	tree->add(4);
	tree->add(5);
	tree->add(15);
	tree->add(16);
	tree->add(17);
	tree->add(11);
	tree->add(12);
	tree->add(13);
	tree->add(14);

	cout << "tree height is " << tree->getHeight() << endl;
	tree->print();
	int result = tree->find(10);
	cout << "result is : " << result << endl;
	delete tree;
	return 0;
}