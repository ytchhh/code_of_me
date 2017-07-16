/*
	调整数组顺序使奇数位于偶数前面
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
	如果不考虑时间复杂度，最简单的思路应该是从头扫描这个数组，没碰到一个偶数时，拿出这个数字，并把位于这个数字后面的所有数字往前挪动一位。挪完之后再数组的末尾有一个空位，这时把该偶数放入这个空位。由于每碰到一个偶数就需要移动O(n)个数字，因此总的时间复杂度是O(n^2)。但是，这种方法不能让面试官满意。不过如果我们在听到题目之后马上能说出这个解法，面试官至少会觉得我们的思维非常敏捷。
	因此我们可以维护两个指针，第一个指针初始化时指向数组的第一个数字，它只向后移动；第二个指针初始化时指向数组的最后一个数字，它只向前移动。在两个指针相遇之前，第一个指针总是位于第二个指针的前面。如果第一个指针指向的数字是偶数，并且第二个指针指向的数字是奇数，我们就交换这两个数字

*/
//基于以下分析，我们可以写出如下代码：

void ReorderOddEven(int* pData,unsigned int length)
{
	if(pData == NULL || length == 0)
		return;

	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin++;

		while(pBegin < pEnd && (*pEnd & 0x1) == 0)
			pEnd--;

		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

/*
	考虑可扩展性的解法	上面的题目是在奇数偶数的条件下 如果更改了条件的话，又要重新来写。
	因此我们可以将这个逻辑框架抽象出来，而把判断的标准变成一个函数指针，也就是用一个单独的函数来判断数字是不是符合标准。这样我们就把整个函数解耦和成两部分：一是判断数字应该在数组前半部分还是后半部分的标准，二是拆分数组的操作。
*/

bool isEven(int n)
{
	return (n & 1) == 0;
}

void Reorder(int* pData,unsigned int length,bool (*func) (int))
{
	if(pData == NULL || length == 0)
		return;
	
	int* pBegin = pData;
	int* pEnd = pData + length - 1;

	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && !func(*pBegin))
			pBegin++;

		while(pBegin < pEnd && func(*pEnd))
			pEnd--;

		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}
