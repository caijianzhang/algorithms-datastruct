#include "binary-tree.h"

int main() {

	BinaryTree<int> tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	tree.add(4);
	tree.add(5);
	tree.add(6);
	tree.add(7);
	//tree.add(8);
	//tree.add(9);
	//tree.add(10);

	cout << "tree height is " << tree.getHeight() << endl;
	tree.print();
	return 0;
}