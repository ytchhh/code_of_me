#include"utili.h"
#include"seqlist.h"

class BigInt;
ostream& operator<<(ostream &otu,const BigInt &bt);

class BigInt
{
	friend ostream& operator<<(ostream &out,const BigInt &bt);
private:
	SeqList<u_char> big;
public:
	BigInt(long value = 0);				//构造函数
	BigInt& operator=(u_long value);	//赋值运算符
public:
	void LoadData(size_t sz);			//随机加载数据
	void PrintData()const;				//打印数据
public:
	u_char back()const;			//获取最后一个元素
	void pop_back();			//尾删函数
	void clear();				//清空函数
	size_t size()const;			//求长度
	void push_back(u_char x);	//后插函数
	void push_front(u_char x);	//头插函数
	void clear_head_zero();		//清除头部多余的零
public:
	void SetSymbol(Symbol sign);
	Symbol GetSymbol()const;
public:
	u_char& operator[](int pos);
	const u_char& operator[](int pos)const;
public:
	static u_char AddItem(u_char a,u_char b,u_char &sign);
//	static u_char SubItem(u_char a,u_char b.u_char &sign);
//	static void MulItem(BigInt &bt,const BigInt &bt1,u_char x);
	static void Add(BigInt &bt,const BigInt &bt1,const BigInt &bt2);
};
