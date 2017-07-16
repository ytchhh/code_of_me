#include"./AVLTree.h"

int main()
{
	AVLTree<int,int> avl(0);
	int ar[] = {16,3,7,11,9,26,18,14,15};
	int n = sizeof(ar)/sizeof(int);
	for(int i = 0; i < n; ++i)
	{
		avl.Insert(ar[i]);
	}
	
	avl.Remove(11);

	return 0;
}
