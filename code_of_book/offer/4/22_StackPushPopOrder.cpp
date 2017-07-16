/*
	题目：输入两个证书序列，第一个 序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1，2，3，4，5是某栈的压栈序列，序列4，5，3，2，1是该压栈序列对应的一个弹出序列，但4，3，5，1，2就不可能是该压栈序列的弹出序列。
	解决这个问题很直观的方法就是建立一个辅助栈，把输入的第一个序列中的数字一次压入该辅助栈，并按照第二个序列的顺序一次从该栈中弹出数字
	规律如下：
		如果下一个弹出的数字刚好是栈顶元素，那么直接弹出。如果下一个要弹出的数字不在栈顶，我们把压栈序列中还没有入栈的数字压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。如果所有的数字都压入栈了任然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列
*/

bool IsPopOrder(const int* pPush,const int* pPop,int nLength)
{
	bool bPossible = false;

	if(pPush != NULL && pPop != NULL && nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		std::stack<int> stackData;

		while(pNextPop - pPop < nLength)
		{
			while(stackData.empty() || stackData.top() != *pNextPop)
			{
				if(pNextPush - pPush == nLength)
					break;

				stackData.push(*pNextPush);
				pNextPush++;
			}

			if(stackData.top() != *pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}
		if(stackData.empty() && pNextPop - pPop == nLength)
			bPossible = true;
	}
	return bPossible;
}
