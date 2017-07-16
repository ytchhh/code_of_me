#include"./utili.h"
#include"bigint.h"

ostream& operator<<(ostream &out,const BigInt &bt)
{
	if(bt.GetSymbol() == NEGATIVE)
		cout<<"-";
	for(size_t i = bt.size(); i >= 1; --i)
	{
		cout<<(int)bt[i];
	}
	return out;
}

void BigInt::SetSymbol(Symbol sign)
{
	big.SetSymbol(sign);
}

Symbol BigInt::GetSymbol()const
{
	return big.GetSymbol();
}

BigInt::BigInt(long value)
{
	SetSymbol(POSITIVE);
	if(value == 0)
		push_back(0);
	else
	{
		if(value < 0)
		{
			SetSymbol(NEGATIVE);
			value = abs(value);
		}
		while(value > 0)
		{
			push_back(value % 10);
			value /= 10;
		}
	}
}

BigInt& BigInt::operator=(u_long value)
{
	clear();
	if(value == 0)
		push_back(0);
	else
	{
		while(value > 0)
		{
			push_back(value % 10);
			value /= 10;
		}
	}
	return *this;
}

void BigInt::LoadData(size_t sz)
{
	clear();
	srand(time(NULL));
	for(int i = 0; i < sz; ++i)
	{
		big.push_back(rand() % 10);
	}
	clear_head_zero();
}

void BigInt::PrintData()const
{
	for(int i = big.size(); i >= 1; --i)
	{
		cout<<(int)big[i];
	}
	cout<<endl;
}

u_char BigInt::back()const
{
	return big.back();
}

void BigInt::pop_back()
{
	big.pop_back();
}

void BigInt::clear()
{
	big.clear();
}

void BigInt::push_back(u_char x)
{
	big.push_back(x);
}

void BigInt::push_front(u_char x)
{
	big.push_front(x);
}

size_t BigInt::size()const
{
	return big.size();
}

void BigInt::clear_head_zero()
{
	while(size()>1 && back() == 0)
	{
		pop_back();
	}
}

u_char& BigInt::operator[](int pos)
{
	return big[pos];
}

const u_char& BigInt::operator[](int pos)const
{
	return big[pos];
}

u_char BigInt::AddItem(u_char a,u_char b,u_char &sign)
{
	u_char sum = a + b;
	if(sum >= 10)
	{
		sum -= 10;
		sign = 1;
	}
	else
		sign = 0;
	return sum;
}

void BigInt::Add(BigInt &bt,const BigInt &bt1,const BigInt &bt2)
{
	bt.clear();
	u_char sum,sign = 0;
	size_t i = 1,j = 1;
	while(i <= bt1.size() && j <= bt2.size())
	{
		sum = AddItem(bt1[i],bt2[j],sign);
		bt.push_back(sum);
		++i;
		++j;
	}
	while(i <= bt1.size())
	{
		sum = AddItem(bt1[i],0,sign);
		bt.push_back(sum);
		++i;
	}
	while(j <= bt2.size())
	{
		sum = AddItem(0,bt2[j],sign);
		bt.push_back(sum);
	}
	if(sign > 0)
		bt.push_back(sign);
}
