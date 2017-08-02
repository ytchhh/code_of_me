/*
	题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。比如输入如图所示的左边的二叉搜索树，则输出转换后的排序双向链表。
*/
	struct BinaryTreeNode
	{
		int				value;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
	}:

///////////////
	在二叉树中，每个结点都有两个指向子结点的指针。在双向链表中，每个结点也有两个指针，他们分别指向前一个结点和后一个结点。由于这两种结点的结构很相似，同时二叉搜索树也是一种排序的数据结构，因此在理论上有可能实现二叉搜索树和排序的双向链表的转换。在搜索二叉树中，左子结点的值总是小于父结点的值，右子结点的值总是大于父结点的值。因此我们在转换成排序双向链表时，原先指向左子结点的指针调整为链表中指向前一个结点的指针，原先指向右子结点的指针调整为链表中指向后一个结点的指针，原先指向右子结点的指针调整为链表中后一个结点指针。接下来我们考虑该如何转换。
/////////////////
BinaryTreeNode* Convert(BinaryTreeNode* pRootofNode)
{
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootofNode,&pLastNodeInList);

	//pLastNodeInList指向双向链表的尾结点
	//我们返回头结点
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while(pHeadOfList != NULL && pHeadOfList->left != NULL)
		pHeadOfList = pHeadOfList->left;
	
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
	if(pNode == NULL)
		return;
	BinaryTreeNode* pCurrent = pNode;
	if(pCurrent->left != NULL)
		ConvertNode(pCurrent->left,pLastNodeInList);
	
	pCurrent->left = *pLastNodeInList;
	if(*pLastNodeInList != NULL)
		(*pLastNodeInList)->right = pCurrent;
	
	*pLastNodeInList = pCurrent;
	if(pCurrent->right)
		ConvertNode(pCurrent->right,pLastNodeInList);
}
