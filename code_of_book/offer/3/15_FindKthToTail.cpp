/*
链表中的倒数第k个结点
	题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个立案表皮有6个结点，从头结点开始它们的值以此是1，2，3，4，5，6.这个链表的倒数第三个结点是指为4的结点。
	struct ListNode
	{
		int			m_nValue;
		ListNode* 	m_pNext;
	};
*/

/*
	为了实现只遍历一次就能找到倒数第k个结点，我们可以定义两个指针。第一个指针从链表的头指针开始遍历向前走k-1,
	第二个指针保持不动；从第k步开始，第二个指针也开始从链表的头指针开始遍历。由于两个指针的距离保持在k-1，当第一个(走在前面的)
	指针到达链表的尾结点时，第二个指针(走在后面的)指针正好是倒数第k个结点。

*/

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
	//如果输入的链表头结点为空 或者输入的k为0
	if(pListHead == NULL || k == 0)
		return NULL;
	
	ListNode* pAhead = pListHead;
	ListNode* pBehind = NULL;

	for(unsigned int i = 0; i < k-1; ++i)
	{
		if(pAhead->m_pNext != NULL)
			pAhead = pAhead->m_pNext;
		else
			return NULL;		//如果链表的结点数少于k，在for循环的遍历中加入一个if判断语句
	}

	pBehind = pListHead;
	while(pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}
