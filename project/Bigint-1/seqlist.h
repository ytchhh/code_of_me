#pragma once

template<class Type>
class SeqList
{
public:
	typedef Type& reference;
	typedef const Type& const_reference;
public:
	SeqList(size_t sz = DEFAULT_SIZE);
	~SeqList();
public:
	void push_back(const Type &x);
	void push_front(const Type &x);
	void pop_back();
	void pop_front();
	reference back();
	const_reference back()const;
	//reference front();
	//const_reference front()const;
	reference front()
	{
		assert(len > 0);
		return base[1];
	}
	const_reference front()const
	{
		assert(len > 0);
		return base[1];
	}
	void clear();
	void sort();
	void reverse();
	size_t size()const;
	int find(const Type &key)const;
	void erase(const Type &key);
public:
	//list[]
	//reference operator[](int pos);
	//const_reference operator[](int pos)const;
	reference operator[](int pos)
	{
		assert(pos>=1 && pos<=len);
		return base[pos];
	}
	const_reference operator[](int pos)const
	{
		assert(pos>=1 && pos<=len);
		return base[pos];
	}
protected:
	bool Inc()
	{
		capacity += INC_SIZE;
		Type *new_base = new Type[capacity+1];
		if(NULL == new_base)
			return false;
		memset(new_base, 0, sizeof(Type)*(capacity+1));
		memcpy(new_base, base, sizeof(Type)*(capacity-INC_SIZE+1));
		delete []base;
		base = new_base;
		return true;
	}
protected:
	SeqList(const SeqList<Type> &);
	SeqList<Type>& operator=(const SeqList<Type> &);
private:
	enum{DEFAULT_SIZE = 10, INC_SIZE = 5};
	Type   *base;
	size_t capacity;
	size_t len;
};
//////////////////////////////////////////////////////////////
template<class Type>
SeqList<Type>::SeqList(size_t sz)
{
	capacity = sz > DEFAULT_SIZE ? sz : DEFAULT_SIZE;
	base = new Type[capacity+1];
	memset(base, 0, sizeof(Type)*(capacity+1));
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
void SeqList<Type>::push_back(const Type &x)
{
	//assert(len < capacity);
	if(len>=capacity && !Inc())
	{
		cout<<"Out Of Memory."<<endl;
		return;
	}
	base[++len] = x;
}
template<class Type>
void SeqList<Type>::push_front(const Type &x)
{
	//assert(len < capacity);
	if(len>=capacity && !Inc())
	{
		cout<<"Out Of Memory."<<endl;
		return;
	}
	for(int i=++len; i>1; --i)
	{
		base[i] = base[i-1];
	}
	base[1] = x;
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
	for(int i=1; i<len; ++i)
	{
		base[i] = base[i+1];
	}
	--len;
}
/*
template<class Type>
reference SeqList<Type>::back()
{
	assert(len > 0);
	return base[len];
}
template<class Type>
const_reference SeqList<Type>::back()const
{
	assert(len > 0);
	return base[len];
}
template<class Type>
reference SeqList<Type>::front()
{
	assert(len > 0);
	return base[1];
}
template<class Type>
const_reference SeqList<Type>::front()const
{
	assert(len > 0);
	return base[1];
}
*/
template<class Type>
void SeqList<Type>::clear()
{
	len = 0;
}

template<class Type>
void SeqList<Type>::sort()
{
	if(len == 1)
		return;
	for(int i=0; i<len-1; ++i)
	{
		for(int j=1; j<=len-i-1; ++j)
		{
			if(base[j] > base[j+1])
			{
				Type tmp = base[j];
				base[j] = base[j+1];
				base[j+1] = tmp;
			}
		}
	}
}
template<class Type>
void SeqList<Type>::reverse()
{
	if(len == 1)
		return;
	int low = 1;
	int high = len;
	while(low < high)
	{
		Type tmp = base[low];
		base[low] = base[high];
		base[high] = tmp;
		low++;
		high--;
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
	for(int i=1; i<=len; ++i)
	{
		if(base[i] == key)
			return i;
	}
	return -1;
}

template<class Type>
void SeqList<Type>::erase(const Type &key)
{
	int pos = find(key);
	if(pos == -1)
		return;
	for(int i=pos; i<len; ++i)
	{
		base[i] = base[i+1];
	}
	--len;
}

template<class Type>
typename SeqList<Type>::reference SeqList<Type>::operator[](int pos)
{
	assert(pos>=1 && pos<=len);
	return base[pos];
}
template<class Type>
typename SeqList<Type>::const_reference SeqList<Type>::operator[](int pos)const
{
	assert(pos>=1 && pos<=len);
	return base[pos];
}

