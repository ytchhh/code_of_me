/*
   数组中有一个胡啥子出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,25,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
   数组中有一个数字的次数超过数组长度的一半，也就是说它出现的次数比其他所有数字出现的数字出现的次数的和还要多。因此我们可以考虑在遍历数组的时候保存两个值：一个是数组中的一个数字，一个是次数。当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1；如果下一个数字和我们之前保存的数字不同，则次数减1.如果次数为0，我们需要保存下一个数字，并把次数设为1。由于我们要找的数字肯定是最后一次把次数设为1时对应的数字。
 */
#include <iostream>
#include <vector>
using namespace std;


int MoreThanHalfNum_Solution(vector<int> &numbers) {
		if(numbers.size() == 0)
				return 0;
		int result = numbers[0];
		int times = 1;
		for(int i = 0; i < numbers.size(); ++i)
		{
				if(times == 0)
				{
						result = numbers[i];
						times = 1;
				}
				else if(result == numbers[i])
						++times;
				else if(result != numbers[i])
						--times;
		}
		times = 0;
		for(int i = 0; i < numbers.size(); ++i)
		{
				if(numbers[i] == result)
						times++;
		}
		if(times*2 > numbers.size())
				return result;
		return 0;
}


int main()
{
		int v[] = {1,2,3,2,2,2,5,4,2};
		vector<int> ve(&v[0],&v[9]);
		cout<< "MoreThanHalfNum_Solution(ve)"<<MoreThanHalfNum_Solution(ve);
}
