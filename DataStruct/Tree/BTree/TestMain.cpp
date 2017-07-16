
#include"./Tree.h"

int main()
{
	BinaryTree<char> BTree('#');
	cout<<"please input a tree:";
	BTree.CreateBinTree();
	//A(B(D,E(G,)),C(,F))#

	cout<<"PreOrder:";
	BTree.preOrder();
	cout<<endl;

	cout<<"InOrder:";
	BTree.inOrder();
	cout<<endl;
	
	cout<<"PostOrder:";
	BTree.postOrder();
	cout<<endl;
	
	if(BTree.IsEmpty())
		cout<<"Tree is Empty"<<endl;
	else
		cout<<"Tree is not Empty"<<endl;

	cout<<"The Heght of Tree is "<<BTree.Height()<<endl;
	cout<<"The Size of Tree is "<<BTree.Size()<<endl;

	BinaryTree<char> BTree1(BTree);
	cout<<"BTree1 preOrder为:";
	BTree1.preOrder();
	cout<<endl;
	
	if(!(BTree == BTree1))
		cout<<"两棵树相等"<<endl;
	else
		cout<<"两棵树不相等"<<endl;
	return 0;
}
