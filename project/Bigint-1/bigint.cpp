#include"bigint.h"

void BigInt::LoadData(size_t sz)
{
	srand(time(NULL));
	for(int i=0; i<sz; ++i)
	{
		big.push_back(rand() % 10);
	}
}
void BigInt::PrintData()const
{
	for(int i=big.size(); i>=1; --i)
	{
		cout<<(int)big[i];
	}
	cout<<endl;
}

size_t BigInt::size()const
{return big.size();}

u_char& BigInt::operator[](int pos)
{
	return big[pos];
}

const u_char& BigInt::operator[](int pos)const
{
	return big[pos];
}

void BigInt::push_back(u_char x)
{
	big.push_back(x);
}


void BigInt::Add(BigInt &bt,const BigInt &bt1,const BigInt &bt2)
{
	size_t i = 1,j = 1;
	u_char sign = 0,sum;
	while(i <= bt1.size() && j <= bt2.size())
	{
		sum = bt1[i] + bt2[i] + sign;
		if(bt1[i] + bt2[j] > 10)
		{
			sum = sum - 10;
			sign = 1;
		}
		else
			sign = 0;
		bt.push_back(sum);
		++i;
		++j;
	}
	
	while(i <= bt1.size())
	{
		sum = bt1[i] + sign;
		bt.push_back(bt1[i++]);
	}
	while(j <= bt2.size())
	{	
		sum = bt2[j] + sign;
		bt.push_back(bt2[j++]);
	}
}
