#include"./BinarySearchTree.h"


int main()
{
	BST<int,int> BSTree(0);
	BSTree.PrintTree();
	cout<<endl<<"----------"<<endl;
	BSTree.Remove(4);
	BSTree.PrintTree();
	return 0;
}
