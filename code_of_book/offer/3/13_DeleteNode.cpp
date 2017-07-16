/*
	在O(1)的时间删除链表结点
	给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。链表结点与函数的定义如下
	struct ListNode
	{
		int			m_nValue;
		ListNode* 	m_pNext;
	};

	void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted);
*/

/*
	在单向链表中删除一个结点，最常规的做法无疑是从链表的头结点开始，顺序遍历查找要删除的结点，并在链表中删除该结点。
	自然。这样的时间复杂度为O(n)，达不到题目的要求。需要遍历去查找到将要删除的结点的前面一个结点。在单向链表中，结点中没有指向前一个结点的指针，所以只能从头结点开始顺序查找。
	那是不是一定需要得到被删除的结点的前一个结点呢？答案是否定的。我们可以很方便得到要删除结点的下一个结点。如果我们把下一个结点的内容复制到需要删除的结点上覆盖原有的内容，再把下一个结点删除，那是不是就相当于把当前需要删除的结点删除了。
	但是如果要删除的结点位于链表的尾部，那么它就没有下一个结点，怎么办？我们任然从链表的头结点开始，顺序遍历得到该结点的前序结点，并完成删除操作。
	最后需要注意的是，如果链表中只有一个结点，而我们又要删除链表的头结点（也是尾结点），此时我们在删除结点之后，还需要把链表的头结点设置为NULL.
	对应的代码如下：
*/

void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
	if(!pListHead || !pToBeDeleted)
		return;
	
	//要删除的结点不是尾结点
	if(pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;
		delete pNext;
		pNext = NULL;
	}
	
	//只有一个结点
	else if(pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	
	//链表中有多个结点，删除尾结点。要删除的结点为尾结点。
	else
	{
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted)
			pNode = pNode->m_pNext;

		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
