/*
	定义一个函数 输入一个链表的头结点 反转该链表并输出反转后链表的头结点
	struct ListNode
	{
		int			m_nKey;
		ListNode*	m_pNext;
	};
	解决链表相关的问题总是有大量的指针操作 而指针的操作的代码总是容易出错的 很多面试官喜欢出链表相关的问题 就是想通过指针操作来考察应聘者的编码功底 为了避免出错 我们最好先进行全面的分析 
	在调节结点的m_pNext指针时，除了徐亚知道结点本身之外，还需要知道结点的前一个结点 因为我们需要把结点的m_pNext指向其前一个结点，并且需要保存结点的后一个结点，以防止结点断开。所以我们需要定义3个指针，分别指向当前遍历到的结点、它的前一个结点及后一个结点
	最后试着找到反转后链表的头结点，不难分析出反转后链表的头结点是原始链表的尾结点。
*/

ListNode* ReverseList(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;	//反转后的头结点
	ListNode* pNode = pHead;	//当前结点
	ListNode* pPrev = NULL;		//当前结点的前一个结点
	while(pNode != NULL)		//循环结束条件
	{
		ListNode* pNext = pNode->m_pNext;	//当前结点的下一个结点

		if(pNext == NULL)		//原始链表的尾结点
			pReversedHead = pNode;		//反转之后的头结点
		pNode->m_pNext = pPrev;			//进行反转

		pPrev = pNode;		//
		pNode = pNode;		//
	}
	return pReversedHead;
}
