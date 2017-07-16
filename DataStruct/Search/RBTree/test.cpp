#include"./rbtree.h"

int main()
{
	
	RBTree<int> rb;
	int ar[] = {100,70,80,50,40,75,73,72,74,71};
	int n = sizeof(ar)/sizeof(int);

	for(int i = 0; i < n; ++i)
	{
		rb.Insert(ar[i]);
	}
	return 0;
}
