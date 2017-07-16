#ifndef _MINHEAP_H
#define _MINHEAP_H

#define DefaultSize	10
enum bool{false,true}

template<class E>
class MinHeap
{
public:
	MinHeap(int sz = DefaultSize);			//构造函数 创建空堆
	MinHeap(T arr[],int n);					//构造函数 通过一个数组建堆
	~MinHeap()							//析构函数
	{
		delete []heap;
	}
	bool Insert(const T& x);			//将x插入到最小堆中
	bool RemoveMin(T& x);			//删除堆顶的最小元素
	bool IsEmpty()const				//判断空否？空返回1，否则0
	{
		return (currentSize == 0) ? true : false;
	}
	bool IsFull()const			//判断满否？满则返回1，否则返回0
	{
		return (currentSize == maxHeapSize) ? true : false;
	}
	void MakeEmpty()		//置空堆
	{
		currentSize = 0;
	}
private:
	T		*heap;						//存放在最小堆中元素的数组
	int		currentSize;				//最小堆中当前元素个数
	int		maxHeapSize;				//最小堆最多允许元素个数
	void	siftDown(int start,int m);	//从start到m下滑调整成为最小堆
	void 	siftUp(int start);			//从start到0上滑调整成为最小堆1
};

template<class T>
MinHeap<T>::MinHeap(int sz)
{
	maxHeapSize = (DefaultSize < sz) ? sz : DefaultSize;
	heap = new T[maxHeapSize];			//创建堆内存空间
	if(heap == NULL)
	{
		cerr<<"堆内存分配失败"<<endl;
		exit(1);
	}
	currentSize = 0;			//建立当前大小
}

template<class T>
MinHeap<T>::MinHeap(T arr[],int n)
{
	maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
	heap = new T[maxHeapSize];
	if(heap == NULL)
	{
		cerr<<"堆内存分配失败"<<endl;
		exit(1);
	}
	for(int i = 0; i < n; ++i)
		heap[i] = arr[i];
	currentSize = n;								//复制堆数组
	int currentPos = (currentSize-2)/2;				//找最初调整位置，最后分支结点
	while(currentPos >= 0)							//自底向上逐步扩大成堆
	{
		siftDown(currentPos,currentSize - 1);		//局部自上向下下滑调整
		currentPos--;								//再向前换一个分支结点
	}
}

template<class T>
MinHeap<T>::siftDown(int start,int m)
{	//从结点start开始到m为止，自上向下比较，如果子女的值小于父结点的值
	//则关键码小的上浮，继续向下层比较，这样讲一个集合调整成为局部最小堆
	int i = start,j = 2*i + 1;		//j是i的左子女位置
	T temp = heap[i];
	while(j <= m)					//检查是否到最后位置
	{
		if(j < m && heap[j] > heap[j+1])		//让j指向两个子女中最小的位置
			j++;
		if(temp <= heap[i])			//小的话就不做调整
			break;
		else
		{
			heap[i] = heap[j];		//否则小者上移，i，j下降
			i = j;
			j = 2*i + 1;
		}
	}
	heap[i] = temp;			//回放temp中暂存的元素
}

template<class T>
MinHeap<T>::siftUp(int start)		//从结点start开始到结点0为止，自下向上比较，如果子女的值小于父结点的值
{									//则相互交换，这样集合重新调整为最小堆。
	int j = start,i = (j-1)/2;
	T temp = heap[j];
	while(j > 0)			//沿父结点路径向上直达根
	{
		if(heap[i] <= temp)		//父结点值小，不调整
			break;
		else
		{
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;			//回送
}

template<class T>
MinHeap<T>::Insert(const T& x)
{
	if(currentSize == maxHeapSize)		//堆满
	{
		cerr<<"Heap Full"<<endl;
		return false;
	}
	heap[currentSize] = x;		//插入
	siftUp(currentSize);		//向上调整
	currentSize++;				//堆计数加一
	return true;
}

template<class T>
MinHeap<T>::RemoveMin(T& x)	
{
	if(!currentSize)					//堆空，返回false
	{
		cout<<"Heap empty"<<endl;
		return false;
	}
	x = heap[0];
	heap[0] = heap[currentSize - 1];		//最后元素补到根结点
	currentSize--;
	siftDown(0,currentSize-1);				//自上向下调整为堆
	return true;			//返回最小元素
}
#endif
