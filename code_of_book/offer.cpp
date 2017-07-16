#if 0
/*
	链表是最容易考查的数据结构
*/
#include<iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
///////////////////////////////////////
void AddToTail(ListNode **pHead,int value);
void RemoveNode(ListNode **pHead,int value);

///////////////////////////////////////
int main()
{
	ListNode *pHead = NULL;
	AddToTail(&pHead,1);
	return 0;
}

void AddToTail(ListNode **pHead,int value)	//添加结点
{
	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL)
		*pHead = pNew;
	else
	{
		ListNode *pNode = *pHead;

		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode **pHead,int value)	//移除某个结点
{
	if(*pHead == NULL || *pHead == NULL)
		return;
	
	ListNode* pToBeDeleted = NULL;
	if( (*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode = *pHead;
		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
		if(pToBeDeleted != NULL)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
		}
	}
}

#endif
#if 0

/*
	题目:输入一个链表的头结点,从尾到头反过来打印出每个结点的值
	链表结点定义为:
	struct ListNode
	{
		int key;
		ListNode *next;
	};
	看到这道题,很多人的第一反应是从头到尾输出比较简单,于是我们很自然的想到把链表中链接结点的指针反转过来,改变链表的方向,然后就可以从头到尾输出了.但该方法会改变原来链表的结构.是否允许在打印链表的时候修改链表的结构,这个取决于面试官的要求,因此在面试的时候我们要询问面试官的要求
	通常打印只是一个只读操作,我们不希望打印时修改内容,假设面试官也要求这道题目不能改变链表的结构.
	接下来我们想到的解决这个问题肯定是要遍历链表.遍历的顺序是从头到尾的顺序,可输出的顺序确实从尾到头。也就是说第一个遍历到的结点最后一个输出,而最后一个遍历到的结点第一个输出，这就是典型的"后进先出",我们可以用栈实现这种结构,每经过一个结点的时候，把该结点的值放进一个栈中,当遍历完整个链表后,再从栈顶开始逐个输出结点的值,此时输出的结点的顺序已经反转过来了,z这种思路实现的代码如下:
*/


void PrintListReversing_Iteratively(ListNode *pHead)
{
	stack<ListNode*> nodes;

	ListNode *pNode = pHead;

	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		cout<<pNode->value<<" ";
		nodes.pop();
	}
	cout<<endl;
}

/*
	既然想到了用栈来实现这个函数,而递归本身就是一个栈结构,于是很自然的又想到了用递归来实现。要实现反过来输出链表,我们没访问到一个结点的时候,先递归输出它后面的结点,再输出该结点本身,这样链表的输出结果就翻过来了
*/

void PrintListReversing_Recursively(ListNode *pHead)
{
	if(pHead != NULL)
	{
		if(pHead->next != NULL)
		{
			PrintListReversing_Recursively(pHead->next);
		}
		cout<<pHead->value<<" ";
	}
}

/*
	上面的基于递归的代码看起来很简洁,但有个问题:当链表非常长的时候,就会导致函数调用的层级很深,从而有可能导致函数调用栈溢出.显式调用栈实现的代码稳定性要强一些.
*/
#endif

#if 0
/*
	旋转数组的最小字符
	把一个数组最开始的若干个元素搬到数组的末尾,我们称之为数组的旋转.输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}，该数组的最小值为1
	这道题最直观的解法并不难,从头到尾遍历数组一次,我们就能找到数组中最小的元素,这种思路的时间复杂度明显为O(n),但是这个思路并没有利用输入的旋转数组的特性,肯定达不到面试官的要求
	我们注意到旋转之后的数组实际上可以划分为两个排序的子数组，而且前面的子数组的元素都大于或者等于后面子数组的元素.我们还注意到最小的元素刚好是这两个子数组的分界线,在排序的数组中我们可以利用二分查找法来实现O(logn)的查找,本题给出的数组在一定程度上是排序的,因此我们可以试着用二分法的思路来查找这个最小的元素.
	和二分查找法一样,我们利用两个指针分别指向数组的第一个元素和最后一个元素。按照题目中旋转的规则,第一个元素应该是大于或者等于最后一个元素的。
	接着我们可以找到数组中间的元素，如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素.此时数组中最小的元素应该位于该中间元素的后面。我们可以把第一个指针指向该中间元素,这样可以缩小查找的范围.移动之后的第一个指针任然位于前面的递增数组中.
	同样如果中间元素位于后面的递增子数组,那么它应该小于或者等于第二个指针指向的元素.此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样也就缩小寻找的范围。移动之后的第二个指针任然位于后面的递增数组当中。
	不管是移动第一个指针还是第二个指针，查找范围都会缩小到原来的一半。接下来我们再用更新之后的两个指针，重复做一轮的查找。
	最终第一个指针会指向前面数组的最后一个元素，第二个指针会指向后面子数组的第一个元素，也就是他们最终会指向两个相邻的元素。这就是循环结束的条件。

*/

//实现的代码如下:

int Min(int *numbers,int length)
{
	if(numbers == NULL || length <= 0)
		return 0;
	
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2)/2;
		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid <= numbers[index2]])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

/*
	前面我们提到在旋转数组中，由于是把递增排序数组前面的若干个数字搬到数组的后面,因此第一个数字总是大于或者等于最后一个数字。但按规定还有一个特例:如果把排序数组的前面的0个元素搬到最后面，即排序数组本身，这任然是数组的一个旋转，我们的代码需要支持这种情况，此时数组的第一个数字就是最小的数字，可以直接返回。这就是在上面的代码中，把indexMid初始化为index1的原因。一旦发现数组中第一个数字小于最后一个数字，表明该数组是排序的，直接返回第一个数字。
*/
/*
	上面的代码是否就完美了呢,并不是，当处于这种情况的时候，可以分析一下，
{1,0,1,1,1}   {1,1,1,0,1}
	在这种情况下，第一个数字，最后一个数字，中间数字，是相同的，我们无法判断中间的数字是位于前面的子数组还是位于后面的子数组。也就无法移动两个指针来缩小查找的范围。此时，就只有用顺序查找的方法来实现。

*/

//所以将代码改为:

int Min(int *numbers,int length)
{
	if(numbers == NULL || length <= 0)
		return 0;
	
	int index1 = 0;
	int index2 = length -1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1+index2)/2;

		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInoeder(numbers,index1,index2);

		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinInoeder(int *numbers,int index1,int index2)
{
	int result = numbers[index1];

	for(int i = index1+1; i <= index2; ++i)
	{
		if(result > numbers[i])
			result = numbers[i];
	}
	return result;
}

#endif

