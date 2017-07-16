/*
	从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印例如输出图4.5中的二叉树，则依次打印出8、6、10、5、7、9、11。
	struct BinaryTreeNode
	{
		int m_nValue;
		BinaryTreeNode*	m_pLeft;
		BinaryTreeNode* m_pRight;
	};
		 8
	 6		 10
   5  7     9  11  
  每一次打印一个结点的时候，如果该结点右子节点，则把该结点的子节点放到一个队列的末尾。接下来到队列的头部取出最早进入队列的结点，重复前面的打印操作，直至队列中所有的结点都被但因出来为止。
  既然我们已经确定数据容器是一个队列了，现在的问题就是如何实现队列。实际上我们无须自己动手实现，因为STL已经为我们实现了一个很好的deque。
  现在是用deque实现的代码：
  void PrintFronTopBottom(BinaryTreeNode *pTreeRoot)		//二叉树的层次遍历
  {
  	if(!pTreeRoot)											//根结点不为空
		return;
	
	std::deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pTreeRoot);

	while(dequeTreeNode.size())
	{
		BinaryTreeNode *pNode = dequeTreeNode.front();		//当前队列中的头结点
		dequeTreeNode.pop_front();							//头删

		printf("%d ",pNode->m_nValue);						//打印出数据

		if(pNode->m_pLeft)									//左子树不为空，入队列
			dequeTreeNode.push_back(pNode-<m_pLeft);

		if(pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);		//右子女不为空，入队列
	}
  }
*/
