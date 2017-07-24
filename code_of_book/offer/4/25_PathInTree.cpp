struct BinaryTreeNode
{
	int				value;
	BinaryTreeNode  *left;
	BinaryTreeNode  *right;
}:

/*
	题目:输入一棵二叉树和一个整数，打印出二叉树中结点值得和为输入整数的所有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

		10
	5		12
 4	   7

 例如在上图中二叉树和整数22，则打印出两条路径，第一条路径包含结点10、12，第二条路径包含结点10、5和7。

 分析后可以知道，用前序遍历的方式访问到某一结点的时候，我们把该结点添加到路径中，并累加该结点的值，如果该结点为叶子结点并且路径中结点值得和刚好等于输入的整数，则当前的路径符合要求，我们把它打印出来。如果当前结点不是叶结点，则继续访问它的子结点。当前结点访问结束后，递归函数将自动回到它的父结点。因此我们在函数退出之前要在路径上删除当前结点并减去当前结点的值，以确保返回父结点时路径刚好是从根结点到父结点的路径。
*/

void FindPath(BinaryTreeNode *pRoot,int expectedSum)
{
	if(pRoot == NULL)
		return;
	std::vector<int> path;
	int currentSum = 0;
	FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath(BinaryTreeNode *pRoot,int expectedSum,std::vector<int> path,int currentSum)
{
	currentSum += pRoot->value;
	path.push_back(pRoot->value);

	//如果是叶子结点并且和满足条件
	bool IfLeaf = pRoot->left == NULL && pRoot->right == NULL;

	if(currentSum == expectedSum && IfLeaf)
	{
		printf("A path is found:");
		std::vector<int>::iterator it = path.brgin();
		while(it != path.end())
		{
			printf("%d\t",*it);
			++it;
		}
	}

	if(pRoot->left != NULL)
		FindPath(pRoot->left,expectedSum,path,currentSum);
	if(pRoot->right != NULL)
		FindPath(pRoot->right,expectedSum,path,currentSum);
	
	currentSum -= path.top();
	path.pop();
}
