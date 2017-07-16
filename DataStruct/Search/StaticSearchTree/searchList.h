#ifndef _SEARCHLIST_H
#define _SEARCHLIST_H

#include<iostream>
#include<assert.h>
using namespace std;

const int defaultSize = 100;
template<class E,class K>
class dataList;

template<class E,class K>
class dataNode					//数据表中结点类的定义
{
friend class dataList<E,K>;		//声明其友元类为dataList
public:
	dataNode(const K x = 0):key(x)	//构造函数
	{}
	K	getKey() const			//读取关键码
	{
		return key;
	}
	void setKey(K k)			//修改关键码
	{
		key = k;
	}
public:
	K	key;					//关键码区

	friend ostream& operator << (ostream& out,const dataNode<E,K> &x)
	{
		out<<x.key;
		return out;
	}
	friend istream& operator >> (istream& in,dataNode<E,K> &x)
	{
		in>>x.key;
		return in;
	}
};

template<class E,class K>
class dataList
{
public:
	dataNode<E,K> *Element;			//数据表中存储数据的数组
	int	ArrySize,CurrentSize;		//数组最大长度和当前长度
public:
	dataList(int sz = defaultSize):ArrySize(sz),CurrentSize(0)
	{
		Element = new dataNode<E,K>[sz];
		assert(Element != NULL);
	}
	dataList(dataList<E,K>& R);			//拷贝构造函数
	virtual ~dataList()					//析构函数为虚函数 为了继承做准备
	{
		delete []Element;
	}
	virtual int Length()				//求表的当前长度
	{
		return CurrentSize;
	}
	virtual dataNode<E,K>* getElement()
	{
		return Element;
	}
	virtual int getCurrentSize()
	{
		return CurrentSize;
	}
	virtual K getKey(int i)const		//提取第i(从1开始)元素值
	{
		assert(i > 0 && i <= CurrentSize);
		return Element[i-1].key;
	}
	virtual void setKey(K x,int i)		//修改第i(1开始)元素值
	{
		assert(i > 0 && i <= CurrentSize);
		Element[i-1].key = x;
	}
	//virtual int SeqSearch(const K x)const;		//搜索
	virtual bool Insert(E& el);					//插入
	virtual bool Remove(const K x,E& el);		//删除
	friend ostream& operator << (ostream& out,dataList<E,K>& OutList)
	{
		out<<"Array Contents"<<endl;			//输出表的所有表项到out
		for(int i = 1; i <= OutList.CurrentSize; ++i)
			out<<OutList.Element[i-1]<<" ";
		out<<endl;
		out<<"Array Current Size:"<<OutList.CurrentSize<<endl;	//输出表的当前长度
		return out;

	}
	friend istream& operator >> (istream& in,dataList<E,K>& InList)
	{
		cout<<"Enter array Size:";			//从in输入当前表的长度
		in>>InList.CurrentSize;
		cout<<"Enter array elements:"<<endl;
		for(int i = 1; i <= InList.CurrentSize; ++i)	//从in输入当前表的全部表项
		{
			cout<<"Element"<<i<<":";
			in>>InList.Element[i-1];
		}
		return in;
	}
};

template<class E,class K>
class searchList:public dataList<E,K>	//搜索表searchList继承了dataList,并且增加了成员函数Search()
{
public:
	searchList(int sz = defaultSize):dataList<E,K>(sz){}
	virtual int SeqSearch(const K x)const;
	virtual int SeqSearch1(const K x,int loc)const;
};

template<class E,class K>
bool dataList<E,K>::Insert(E& el)	//在dataList的尾部插入新元素el，若插入失败则返回false，否则返回true
{
	if(CurrentSize == ArrySize)
		return false;
	Element[CurrentSize] = el;		//插入在尾部
	CurrentSize++;
	return true;
}

template<class E,class K>
bool dataList<E,K>::Remove(const K x,E& el)		//在dataList中删除关键码为x的元素，通过el返回。用尾元素填补被删除元素
{
	int i;
	if(CurrentSize == 0)
		return false;
	for(i = 0; i < CurrentSize && Element[i].key != x; ++i)
		;
	if(i == CurrentSize)		//未找到就返回
		return false;
	el = Element[i].key;			//找到，保存被删除的元素
	Element[i] = Element[CurrentSize-1];	//填补
	CurrentSize--;
	return true;
}

template<class E,class K>
int searchList<E,K>::SeqSearch(const K x)const	//在搜索表中顺序搜索其关键码为x的数据元素，要求数据元素在表中从下表0开始存放，第CurrentSize号位置作为控制搜索过程自动结束的“监视哨”使用，若找到则返回该元素在表中的位置i，否则返回CurrentSize
{
	this->Element[this->CurrentSize].key = x;		//将x设置为监视哨
	int i = 0;
	while(this->Element[i].key != x)
		++i;							//从前到后搜索
	return i+1;
}

template<class E,class K>
int searchList<E,K>::SeqSearch1(const K x,int loc)const	//顺序搜索的递归算法
{
	if(loc > this->CurrentSize)
		return 0;
	else if(this->Element[loc-1].key == x)
		return loc;
	else
		return SeqSearch1(x,loc+1);
}
////////////////////////////////////////////////////////

//基于有序顺序表的顺序搜索和折半搜索

template<class E,class K>
class SortList:public searchList<E,K>
{
private:
	
public:
	SortList(int sz = 100):searchList<E,K>(sz){}
	~SortList(){}
	int SequentSearch(const K x)const;		//顺序搜索
	int BinarySearch(const K x)const;		//折半搜索
	int BinarySearch1(const K x,int low,int high)const;		//折半搜索
	bool Insert(const E& el);				//有序插入
	int Begin()				//定位第一个
	{
		return (this->CurrentSize == 0) ? 0 : 1;
	}
	int Next(int i)					//定位下一个
	{
		return (i >= 1 && i <= this->CurrentSize) ? i+1 : 0;
	}
};

template<class E,class K>
int SortList<E,K>::SequentSearch(const K x)const	//顺序搜索关键码为x的数据元素
{
	for(int i = 1; i <= this->CurrentSize; ++i)
		if(this->Element[i-1].key == x)
			return i;				//成功 停止搜索
		else if(this->Element[i-1].key > x)		//不成功，停止搜索
			break;
	return 0;					//顺序搜索失败
}

template<class E,class K>
int SortList<E,K>::BinarySearch(const K x)const	//迭代算法
{
	int high = this->CurrentSize-1,low,mid;
	while(low <= high)
	{
		mid	= (low + high)/2;
		if(x > this->Element[mid].key)		//右搜索区间
			low = mid + 1;
		else if(x < this->Element[mid].key)	//左搜索区间
			high = mid - 1;
		else 
			return mid + 1;					//搜索成功
	}
	return 0;			//搜索失败
}

template<class E,class K>
int SortList<E,K>::BinarySearch1(const K x,int low,int high)const		//递归算法
{
	int mid = 0;
	if(low <= high)
	{
		mid = (low + high)/2;
		if(x > this->Element[mid-1].key)		//右搜索区间
			mid = BinarySearch1(x,mid+1,high);
		else if( x < this->Element[mid-1].key)	//左搜索区间
			mid = BinarySearch(x,low,mid-1);
	}
	return mid;
}

#endif
