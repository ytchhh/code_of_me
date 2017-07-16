#pragma once

template<class Type>
class SeqList
{
public:
	typedef Type& reference;
	typedef const Type& const_reference;
private:
	enum{DEFAULT_SIZE = 10,INC_SIZE = 5};
	Type *base;			//顺序表的长度
	size_t capacity;	//容量
	size_t len;			//长度
public:
	SeqList(size_t sz = DEFAULT_SIZE);	//构造函数
	~SeqList();							//析构函数
	SeqList<Type>& operator=(const SeqList<Type> &st);//赋值函数
	SeqList(const SeqList<Type> &st);//拷贝函数
public:
	
public:
	void push_back(const Type &item);		//后插函数
	void push_front(const Type &item);		//前插函数
	void pop_back();				//尾删函数
	void pop_front();				//头删函数
	reference back();				//返回最后一个元素
	const_reference	back()const;		//常方法
	reference front();				//返回第一个元素
	const_reference front()const;		//常方法
	void clear();					//清空顺序表
	void sort();					//对顺序表进行排序
	void reverse();					//逆序
	size_t	size()const;			//求大小
	int find(const Type &key)const;	//查找函数
	void erase(const Type &key);		//删除函数
public:
	void SetSymbol(Symbol sign);
	Symbol GetSymbol()const;
public:
	reference operator[](int pos);
	const_reference operator[](int pos)const;
protected:
	bool Inc()	//空间不够时 自动增加 因为其在成员函数内部调用 所以声明为保护
	{
		capacity += INC_SIZE;
		Type *new_base = new Type[capacity+1];
		if(NULL == new_base)
			return false;
		memset(new_base,0,sizeof(Type)*(capacity+1));
		memcpy(new_base,base,sizeof(Type)*(capacity-INC_SIZE+1));
		delete []base;
		base = new_base;
		return true;
	}
};

template<class Type>
SeqList<Type>::SeqList(size_t sz)
{
	capacity = sz > DEFAULT_SIZE ? sz : DEFAULT_SIZE;
	base = new Type[capacity+1];
	memset(base,0,sizeof(Type)*(capacity+1));
	len = 0;
}

template<class Type>
SeqList<Type>::~SeqList()
{
	delete []base;
	base = NULL;
	capacity = len = 0;
}

template<class Type>
SeqList<Type>::SeqList(const SeqList<Type> &st)
{
	capacity = st.capacity;
	base = new Type[capacity+1];
	memset(base,0,sizeof(Type)*(capacity+1));
	memcpy(base,st.base,sizeof(st.len+1));
	len = st.len;
}

template<class Type>
SeqList<Type>& SeqList<Type>::operator=(const SeqList<Type> &st)
{
	if(this != &st)
	{
		if(capacity < st.len)
		{
			delete []base;
			base = new Type[st.capacity+1];
			capacity = st.capacity;
		}
		memcpy(base,st.base,sizeof(Type)*(st.len+1));
		len = st.len;
	}
	return *this;
}

template<class Type>
void SeqList<Type>::push_back(const Type& item)
{
	
	//assert(len < capacity);
	if(len >= capacity && !Inc())
	{
		cout<<"Out of Memory."<<endl;
		return;
	}
	base[++len] = item;
}

template<class Type>
void SeqList<Type>::push_front(const Type& item)
{
	assert(len < capacity);
	for(int i = len+1; i > 1; --i)
		base[i] = base[i-1];
	base[1] = item;
	++len;
}

template<class Type>
void SeqList<Type>::pop_back()
{
	assert(len > 0);
	--len;
}

template<class Type>
void SeqList<Type>::pop_front()
{
	assert(len > 0);
	for(int i = 1; i < len; ++i)
		base[i] = base[i+1];
	--len;
}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::back()
{
	assert(len > 0);
	return base[len];
}

template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::back()const
{
	assert(len > 0);
	return base[len];
}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::front()
{
	assert(len > 0);
	return base[1];
}

template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::front()const
{
	assert(len > 0);
	return base[1];
}

template<class Type>
void SeqList<Type>::clear()
{
	if(len == 0)
		return;
	delete []base;
	base = NULL;
	capacity = len = 0;
}

template<class Type>
void SeqList<Type>::sort()
{
	if(len == 1)
		return;
	int temp;
	for(int i = 0; i < len; ++i)
		for(int j = 0; j < len-1; ++j)
		{
			if(base[j] < base[j+1])
			{
				temp = base[j];
				base[j] = base[j+1];
				base[j+1] = temp;
			}
		}
}

template<class Type>
void SeqList<Type>::reverse()
{
	if(len == 1)
		return;
	int low = 1,high = len;
	Type temp;
	while(low < high)
	{
		temp = base[low];
		base[low] = base[high];
		base[high] = temp;
	}
}

template<class Type>
size_t SeqList<Type>::size()const
{
	return len;
}

template<class Type>
int SeqList<Type>::find(const Type &key)const
{
	assert(len > 0);
	for(int i = 1; i <= len; ++i)
		if(base[i] == key)
			return i;
	return -1;
}

template<class Type>
void SeqList<Type>::erase(const Type &key)
{
	int pos = find(key);
	if(pos == -1)
		return;
	for(int i = pos;i < len; ++i)
		base[i] = base[i+1];
	--len;
}

template<class Type>
void SeqList<Type>::SetSymbol(Symbol sign)
{
	base[0] = sign;
}

template<class Type>
Symbol SeqList<Type>::GetSymbol()const
{
	return (Symbol)base[0];
}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::operator[](int pos)
{
	assert(pos >= 1 && pos <= len);
	return base[pos];
}

template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::operator[](int pos)const
{
	assert(pos >= 1 && pos <= len);
	return base[pos];
}
