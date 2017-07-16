#include"utili.h"
#include"seqlist.h"

class BigInt
{
public:
	void LoadData(size_t sz);
	void PrintData()const;
public:
	size_t size()const;
	u_char& operator[](int pos);
	const u_char& operator[](int pos)const;
	void push_back(u_char x);
public:
	//bt = bt1 + bt2;
	static void Add(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	//static void Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	//static void Mul(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	//static void Div(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	//static void Mod(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
private:
	SeqList<u_char> big;
};
