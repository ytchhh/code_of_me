/*
	请完成一个函数，输入一个二叉树，该函数输出它的镜像。
	二叉树的定义如下：
	struct BinaryTreeNode
	{
		int				m_nValue;
		BinaryTreeNode* m_pLeft;
		BinaryTreeNode* m_pRight;
	};
	通过画图分析可以得知，求一棵树的镜像的过程：我们先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就叫唤它的两个子结点。当交换所有非叶子结点的左右子结点之后，就得到了树的镜像
*/

void MirrorRecursively(BinaryTreeNode* pNode)
{
	if(pNode == NULL)	//如果当前结点为空 循环结束条件
		return;
	
	if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)	//左右子树皆为空
		return;
	
	BinaryTreeNode *pTemp = pNode->m_pLeft;		//交换左右子树
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if(pNode->m_pLeft)	
		MirrorRecursively(pNode->m_pLeft);		//递归调动
	
	if(pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}
