/*
	输入两课二叉树A和B，判断B是不是A的子结构。二叉树的定义如下：
	struct BinaryTreeNode
	{
		int				 m_nValue;
		BinaryTreeNode*  m_pLeft;
		BinaryTreeNode*  m_pRight;
	};
	第一步在树A中查找与根结点的值一样的结点，这实际上就是树的遍历。对二叉树这种数据结构熟悉的读者自然知道可以用递归的方法去遍历，也可以用循环的方法去遍历。由于递归的代码实现比较简洁，面试时如果没有特别的要求，我们通常都会采用递归的方式，
	第二步是判断树A中以R为根结点的子树是不是和树B具有相同的结构，同样也是用递归的方法来解决，如果，结点R的值和树B的根结点不相同，则以R为根结点的子树和树B肯定不具有相同的结点。如果它们的值相同，则递归地判断它们各自的左右结点的值是不是相同。递归的终止条件是我们到达了树A和树B的叶结点。
*/

bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	bool result = false;

	if(pRoot1 != NULL && pRoot2 != NULL)
	{
		/如果根节点对应的值刚好是B树根节点的值
		if(pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoesTree1HaveTree2(pRoot1,pRoot2);
		if(!result)
			result = HasSubtree(pRoot1->m_pLeft,pRoot2);	//去A树的左子树寻找
		if(!result)
			result = HasSubtree(pRoot1->m_Right,pRoot2);	//去A树的右子树寻找
	}
	return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	if(pRoot2 == NULL)//考虑边界条件
		return true;
	
	if(pRoot1 == NULL)
		return false;
	
	if(pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	
	return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}
