#if 0
 /*
 ***二维数组的查找
 	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否有该整数。
	在查找一个数字的时候，可以先从数组的右上角选取数字来和查找的数字进行比较，如果该数字等于要查找的数字，查找过程结束，如果该数字大于要查找的数字，剔除这个数字所在的列；如果该数字小于要查找的数字，剔除这个数字所在的行。也就是说如果要查找的数字不在数组的右上角，则每一次都在数组的查找范围中剔除一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。
 */
#include<iostream>

using namespace std;

bool Find(int *matrix,int rows,int colums,int number)
{
	bool found = false;

	if(matrix != NULL && rows > 0 && colums > 0)
	{
		int row = 0;
		int colum = colums-1;
		while(row < rows && column > 0)
		{
			if(matrix[row * colums + column] == number)//刚好是查找的那个数字
			{
				found = true;
				break;
			}
			else if(matrix[row * colums + column] > number)//比查找的那个数字大
				--column;	//将列数减1
			else
				++row;		//将行数加1
		}
	}
	return found;
}

int main()
{
	int a[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	cout<<"input a number";
	int number;
	cin>>number;
	if(Find(*a,4,4,7))
		cout<<"找到"<<endl;
	else
		cout<<"未找到"<<endl;
	return 0;
}
#endif

#if 0
 /*
 *请实现一个函数，把字符串中的每个空格替换成"%20".例如输入"We are happy".
 则输出"We%20are%20happy."
 
 	我们可以先遍历一次字符串，这样就可以统计出字符串中空格的个数，并可以由此计算出替换之后的字符串的总长度。每替换一个空格，长度增加2，因此替换后字符串的长度等于原来的长度加上2乘以空格数目。我们还是以前面的字符串"We are happy."为例，"We are happy"这个字符串的长度是14（包括结尾符号'\0'），里面有两个空格，因此替换之后的字符串长度是18。
 */

#include<iostream>
using namespace std;

/* length为字符数组的总容量*/
void ReplaceBlank(char string[],int length)
{
	if(string == NULL && length <= 0)
		return;
	/* originalLength为字符串string的实际长度*/
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(string [i] != '\0')
	{
		++originalLength;

		if(string[i] == ' ')
			++numberOfBlank;

		++i;
	}
	
	/* newLength为把空格替换为'%20'后的长度*/
	int newLength = originalLength + 2 * numberOfBlank;
	if(newLength > length)
		return;
	
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
			string[indexOfNew--] = string[indexOfOriginal];
		--indexOfOriginal;
	}
}
int main()
{
	char str[40] = "We are happy";
	cout<<str<<endl;
	ReplaceBlank(str,40);
	cout<<str<<endl;
}
#endif


#if 0
 /*
 *输入一个链表的头结点，从尾到头反过来打印每个结点的值
 */

//可以利用栈的结构来存储，每经过一个结点的时候，把该结点放到一个栈当中去，当遍历完整个链表后，再从栈顶开始主格输出结点的值

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> = pHead;

	ListNode* pNode = pHead;
	while(pNode != NULL)
	{
		nodes.push_back(pNode);
		pNode = pNode->m_pNext;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		cout<<pNode->m_nValue<<"-->";
		nodes.pop();
	}
	cout<<endl;
}

//由此可以想到使用递归的方法，我们每访问到一个结点的时候，先递归输出它后面的结点，再输出该结点本身，这样输出结果自然就反过来的。

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if(pHead != NULL)
	{
		if(pHead->m_pNext != NULL)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout<<pHead->m_nValue<<"-->";
	}
}


#endif

#if 0
 /*
 *重建二叉树
 题目:输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6},则重建出原来的二叉树并输出它的头结点。二叉树结点的定义如下:

 struct BinaryTreeNode
 {
 	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
 };
 	再二叉树的前序遍历中，第一个数字总是树的根结点的值。但在中序遍历序列中，根结点的值在序列的中间，左子树的结点的值位于根结点的值的左边，而右子树的结点的值位于根结点的值的右边。因此我们需要中序遍历序列，就能确定根结点的位置。
 	如图所示，前序遍历序列的第一个数字1就是根结点的值。扫描中序遍历序列，就能确定根结点的值的位置。根据中序遍历的特点，在根结点的值1前面的3个数字都是左子树结点的值，位于1后面的数字都是右子树结点的值
 	由于在中序遍历中，有3个数字是左子树结点的值，因此左子树总共有3个左子结点。同样，在前序遍历的序列中，根结点后面的3个数字就是3个左子树结点的值，再后面的所有数字都是右子树结点的值。
	既然分别找到的左右子树的前序遍历和中序遍历序列，我们可以用同样的方法分别去构建左右子树。也就是说，后面的事可以用递归的方法去完成。
*/

#include<iostream>
#include<assert.h>
using namespace std;

struct BinaryTreeNode
{
	int				m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder);

BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	
	return ConstructCore(preorder,preorder + length -1,inorder,inorder + length -1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
	//前序遍历的第一个数字是根结点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if(startPreorder == endPreorder)
	{
		if(startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception();
	}
	
	//再中序遍历中找到根结点的值
	int* rootInorder = startInorder;
	while(rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if(leftLength > 0)
	{
		//构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1,leftPreorderEnd,startInorder,rootInorder - 1);
	}
	if(leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1,endPreorder,rootInorder + 1,endInorder);
	}
	return root;
}

void Preorder(BinaryTreeNode* root)
{
	if(root != NULL)
	{
		cout<<root->m_nValue;
		Preorder(root->m_pLeft);
		Preorder(root->m_pRight);
	}
	else
		return;
}

int main()
{
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};

	BinaryTreeNode* nodes = Construct(preorder,inorder,8);
	Preorder(nodes);
	cout<<endl;
}
#endif

#if 0

/*
*用两个栈实现一个队列
	用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail和deleteHead，分别完成再队列尾部插入结点和在队列头部删除结点的功能
*
	删除一个元素的步骤是：当stack2中不存在元素的时候，在stack2中的栈顶元素是最先进入队列的元素，可以弹出来，当stack2中为空的时候，我们把stack1中的元素逐个弹出并压入stack2.由于先进入队列的元素被压到stack1的底端，经过弹出和压入之后就处于stack2的顶端了，又可以直接弹出。
	插入一个元素的，可以直接压入stack1中就行了，因为下次删除的时候才会影响到顶端元素。
*/


#include<iostream>
#include<stack>
using namespace std;

template<class Type>
class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const Type& elements);
	Type deleteHead();
private:
	stack<Type> stack1;
	stack<Type> stack2;
};

template<class Type>
CQueue<Type>::CQueue()
{
	
}

template<class Type>
CQueue<Type>::~CQueue()
{
	
}

template<class Type>
void CQueue<Type>::appendTail(const Type& elements)
{	//因为从尾部插入只需要放入到第一个栈当中即可
	stack1.push(elements);
}

template<class Type>
Type CQueue<Type>::deleteHead()
{	//删除头结点需要借助第二个栈来 先把第一个栈当中的元素全部弹入到第二个栈当中，这样就实现队列的结构
	if(stack2.size()  <= 0)
	{//stack2中没有元素 就可以向其中插入元素
		while(stack1.size() > 0)
		{
			Type& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if(stack2.size() == 0)
		throw new exception();
	
	Type head = stack2.top();	//保留头部并且返回
	stack2.pop();

	return head;
}

int main()
{
	CQueue<int> qe;
	qe.appendTail(1);
	qe.appendTail(2);
	qe.appendTail(3);
	qe.deleteHead();
	qe.deleteHead();
	cout<<"Hello World"<<endl;
}
#endif

#if 0

 /*
 *通过两个队列实现一个栈
 和两个栈模拟一个队列的原理差不多，弹出一个元素的时候，根据栈先进后出的原则，最后入栈的元素应该最先被弹出。由于每次只能从队列的头部删除元素，因此我们可以先从队列1中删除元素并且插入到队列2中去，
 */


#include<iostream>
#include<queue>
using namespace std;

template<class Type>
class CStack
{
 public:
 	void appendTail(const Type& elements);
	Type deleteHead();
 private:
 	queue<Type> queue1;
	queue<Type> queue2;
};


template<class Type>
void CStack<Type>::appendTail(const Type& elements)
{
	queue1.push(elements);
}

template<class Type>
Type CStack<Type>::deleteHead()
{
	Type tail;
 	if(queue2.size() <= 0)
	{
		while(queue1.front() != queue1.back())
		{
			Type& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}

		if(queue2.size() == 0)
			throw new exception();
	
		tail = queue1.front();
		queue1.pop();
	}
	else
	{
		while(queue2.front() != queue2.back())
		{
			Type& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}

		if(queue1.size() == 0)
			throw new exception();

		tail = queue2.front();
		queue2.pop();
	}
	return tail;
}

int main()
{
	CStack<int> st;
	st.appendTail(1);
	st.appendTail(2);
	st.appendTail(3);
	st.deleteHead();
	st.deleteHead();
	cout<<"Hello World!"<<endl;
}
#endif


 /*
 *旋转数字的最小数字
 	题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2},为{1,2,3,4,5}的一个旋转，该数组的最小值为1
	这道题目最直观的解法并不难，从头到尾遍历数组一次，我们就能找出最小的元素。这种思路的时间复杂度显然是O(n)。但是这个思路没有利用输入的旋转数组的特性，肯定达不到要求。
	我们注意到旋转之后的数组实际上可以划分为两个排序的子数组，且前面的子数组的元素都大于或者等于后面子数组的元素。我们还注意到最小的元素刚好是这两个子数组的分界线。在排序的数组中我们可以用二分查找法实现O(logn)的查找。这道题目也可以用二分查找的思路来寻找这个最小的元素。
	和二分查找法一样，我们用两个指针分别指向数组的第一个元素和最ihou一个元素。按照题目中旋转的规则，第一个元素应该是大于或者等于最后一个元素的。接着我们可以找到数组中间的元素。如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素。此时数组中最小的元素应该位于该中间元素的后面。我们可以把第一个指针指向该中间元素，这样可以缩小寻找的范围。移动之后的指针仍然位于前面的递增子数组之中。
	同样，如果中间元素位于后面的递增子数组中，那么它应该小于或者等于第二个指针指向的元素。此时该数组中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样也可以缩小寻找的范围。移动之后的第二个指针仍然位于后面的递增子数组中。
	按照前面的思路，第一个指针总是指向前面递增数组的元素，而第二个指针总是指向后面递增数组的元素。最终第一个指针将指向前面子数组的最后一个元素，而第二个指针会指向后面子数组的第一个元素。也就是说它们最终会指向两个相邻的元素，而第二个指针指向的刚好是最小的元素。这就是循环结束的条件。
 */

#if 0
#include<iostream>
using namespace std;

int Min(int* numbers,int length)
{
	if(numbers == NULL || length <= 0)	//判断传入数组是否存在
		throw new std::exception();
	
	int index1 = 0;		//指向开头
	int index2 = length - 1;	//指向结尾
	int indexMid = index1;		//在出现0旋转的情况下依然正确

	while(numbers[index1] >= numbers[index2])	//循环结束条件
	{
		if(index2 - index1 == 1)	//两个指针相邻
		{
			indexMid = index2;		//第二个递增数组的开头就是最小的数字
			break;
		}

		indexMid = (index1 + index2) / 2;
		if(numbers[indexMid] >= numbers[index1])		//中间数字在第一个递增数组中
			index1 = indexMid;
		else if(numbers[indexMid] < numbers[index2])	//中间数字在第二个递增数组中
			index2 = indexMid;
	}
	return numbers[indexMid];
}
	
int main()
{
	int numbers[5] = {3,4,5,1,2};
	int min = Min(numbers,5);
	cout<<"min = "<<min<<endl;
	return 0;
}

#endif
 /*
 *	但是上述代码依然存在着缺陷，就是当index1和index2下标所对应的数相同时，并且它们所对应的中间数字也相同时。
 数组{1,0,1,1,1}和{1,1,1,0,1}可以看成是递增数组的情况。
	因为第一个指针和第二个指针以及中间指针所指向的数字都相同的情况下，上面的方法就不再适合，所以只有采用顺序查找的方法才行。
 */

#if 0
#include<iostream>
using namespace std;

int MinInorder(int* numbers,int index1,int index2);

int Min(int numbers[],int length)
{
	if(numbers == NULL || length <= 0)
		throw new std::exception();
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while(numbers[index1] >= numbers[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}

		indexMid = (index1 + index2) / 2;
		
		//如果下标index1和index2和indexMid所指向的下标对应的数字都相等
		//则只能顺序查找
		if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInorder(numbers,index1,index2);

		if(numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;

	}
	return numbers[indexMid];
}

//顺序查找
int MinInorder(int* numbers,int index1,int index2)
{
	int result = numbers[index1];
	for(int i = index1 + 1; i <= index2; ++i)
	{
		if(result > numbers[i])
			result = numbers[i];
	}
	return result;
}

int main()
{
	int numbers[] = {1,0,1,1,1};
	int min = Min(numbers,sizeof(numbers)/sizeof(numbers[0]));
	cout<<"Min = "<<min<<endl;
	return 0;
}
#endif

#if 0
/*
*面试题9：斐波那切数列
	写一个函数，输入n，求斐波那切数列的第n项。斐波那切数列的定义如下：f(n) = (0 n = 0; 1 n = 1; f(n-1) + f(n-2))
	效率太低的解法，挑剔的面试官可能不会喜欢
	long long Fibonacci(unsigned int n)
	{
		if(n <= 0)
			return 0;

		if(n == 1)
			return 1;

		return Fibonacci(n-1) + Fibonacci(n-2);
	}
	递归函数的效率太低 并且会调用大量的堆栈，而且递归里面的堆栈调用是特别大的，所以这种解法是不被推荐的。
	其实改进的方法就是避免了重复计算，我们可以把已经得到的数列中间项保存起来，如果下次需要计算的时候直接先查找一下，如果已经重复计算过的就不用重复计算了。
	更简单的方法是从下往上计算，首先根据f(0)和f(1)算出f(2),再根据f(1)和f(2)算出f(3),依次类推就可以算出第n项了。很容易理解，这种算法的复杂度是O(n)。实现代码如下：
	*/

	#include<iostream>
	using namespace std;
	
	long long Fibonacci(unsigned n)
	{
		int result[2] = {0,1};
		if(n < 2)
			return result[n];

		long long FibNMinusOne = 1;
		long long FibNMinusTwo = 0;
		long long fibN = 0;
		for(unsigned int i = 2; i <= n; ++i)
		{
			fibN = FibNMinusOne + FibNMinusTwo;

			FibNMinusTwo = FibNMinusOne;
			FibNMinusOne = fibN;
		}
		return fibN;
	}

	int main()
	{
		int n;
		cin>>n;
		cout<<" end = "<<Fibonacci(n)<<endl;
		return 0;
	}

#endif

#if 1

/*
 *	二进制的位运算并不是很难掌握，因为位运算总共只有5种运算：与，或，异或，左移，和右移。与，或，和异或运算的规律我们可以用下表总结
 *	与(&)   0 & 0 = 0	1 & 0 = 0	0 & 1 = 0	1 & 1 = 1
 *	或(|)	0 | 0 = 0	1 | 0 = 1	0 | 1 = 1	1 | 1 = 1
 *	异或(^)	0 ^ 0 = 0	1 ^ 0 = 1	0 ^ 1 = 1	1 ^ 1 = 0
 *	左移运算符m<<n表示把m左移n位。左移n位的时候，最左边的n位被丢弃，同时再最最右边补上n个0
 *	0000 1010 << 2	= 0010 1000
 *	1000 1010 << 3	= 0101 0000
 *	右移运算符m>>n表示把m右移n位，右移n位的时候，最右边的n位将被抛弃。但右移时处理最左边位的情形要稍微复杂一些。如果数字时一个右符号数值，则用数字的符号位填补最左边的n位。也就是说如果数字是一个有符号数值，则用数字的符号位填补最左边的n位。如果数字原先是一个正数，则右移之后再最左边补n个0；如果数字原先是负数，则右移之后再最左边补n个1，
 *	0000 1010 >> 2 = 0000 0010
 *	1000 1010 >> 3 = 1111 0001
 *
*/


 /*
 *请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如把9表示成二进制是1001，右2位是1.因此如果输入9，该函数输出2.
	解法一：先判断整数二进制表示中最右边一位是不是1.接着把输入的整数右移一位，此时原来处于从右边数起的第二位被移到最右边了，再判断是不是1.这样每移动一位，直到整个整数变成0为止。


	int Numerof1(int n)
	{
		int count = 0;
		while(n)
		{
			if(n & 1)
				count++;
			n = n >> 1;
		}
		return count;
	}
	这种解法在遇到负数的时候，就会形成死循环。所以并不是最优的解法。
	常规的解法为:为了避免死循环，我们可以不右移输入的数字n。首先把n和1做与运算，判断n的最低位是不是1.接着把1左移一位得到2，再和n做与运算，就能判断n的次低位是不是1，....这样反复左移，每次都能判断n的其中一位是不是1。
	int NumberOf1(int n)
	{
		int count = 0;
		unsigned int flag = 1;
		while(flag)
		{
			if(n & flag)
				count++;

			flag = flag>>1;
		}
		return count;
	}

	把一个整数减去1，再和原来的整数做与运算，会把该整数最右边一个1变成0。那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作。
	int NumberOf1(int n)
	{
		int count = 0;

		while(n)
		{
			++count;
			n = (n-1) & n;
		}
		return coutn;
	}
 */

 int main()
 {
 	int n;
	cin>>n;
	cout<<"NumberOf1 = "<<NumberOf1(n)<<endl;
 	return 0;
 }
#endif
