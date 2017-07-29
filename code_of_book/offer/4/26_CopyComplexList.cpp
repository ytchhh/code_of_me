/*
	请实现函数ComplexListNode* Clone(ComplexListNode *pHead)，复制一个复杂链表。在复杂链表中，每个节点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL。结点的定义为：
	struct ComplexListNode
	{
		int 				Value;
		ComplexListNode* 	Next;
		ComplexListNode*	Sibling;
	};
	a->b->c->d->e
	第一步根据原始链表的每个结点N创建对应的N'，将N'链接在N的后面，
	a->a'->b->b'->c->c'->d->d'->e->e'
	第二部设置复制出来的Sibling。假设原始链表上的N的Sibling指向结点S，那么其对应复制出来的N'是N的Next结点，同样S'也是S的Next指向的结点。
	第三部a就是将这个长链表拆分成为两个链表：把奇数位置的结点用Next链接起来就是原始链表，把偶数位置的结点用Next链接起来就是复制出来的链表。
*/

void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode *pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode *pCloned = new ComplexListNode();
		pCloned->Value = pNode->Value;
		pCloned->Next = pNode->Next;
		pCloned->Sibling = NULL;
		pNode->Next = pCloned;
		pNode = pCloned->Next;
	}
}

void ConnectSiblingNodes(ComplexListNode *pHead)
{
	ComplexListNode *pNode = pHead;
	while(pNode != NULL)
	{
		ComplexListNode *pCloned = pNode->Next;
		if(pNode->Sibling != NULL)
		{
			pCloned->Sibling = pNode->Sibling->Next;
		}
		pNode = pCloned->Next;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode *pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	while(pNode != NULL)
	{
		pClonedHead = pClonedHead = pNode->Next;
		pNode->Next = pClonedNode->Next;
		pNode = pNode->Next;
	}
	while(pNode != NULL)
	{
		pClonedNode->Next = pNode->Next;
		pClonedNode = pClonedNode->Next;
		pNode->Next = pClonedNode->Next;
		pNode = pNode->Next;
	}
	return pClonedHead;

}

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

