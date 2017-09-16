#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int sum(string exp)
{
		stack<int> num;
		int n=0,t1,t2;
		bool is_zero=false;//用来判断输入的数字是否为0
		for(int i=0;i<exp.size();i++)
		{
				if(exp[i]==' ')
				{
						//假如n不为0，直接入栈然后置0
						if(n!=0||is_zero)
						{
								num.push(n);
								n=0;
								is_zero=false;
						}
						continue;
				}
				if(exp[i]<='9'&&exp[i]>='0')//处理数字
				{
						n*=10;
						n+=(exp[i]-'0');
						is_zero=true;
				}
				else
				{
						//同上
						if(n!=0||is_zero)
						{
								num.push(n);
								n=0;
								is_zero=false;
						}
						t1=num.top();
						num.pop();
						t2=num.top();
						num.pop();
						//处理运算
						switch(exp[i])
						{
								case '+':
										t2+=t1;
										break;
								case '-':
										t2-=t1;
										break;
								case '*':
										t2*=t1;
										break;
								case '/':
										t2/=t1;
										break;
						}
						num.push(t2);
				}
		}
		return num.top();
}

//返回各个符号的优先级，数字最大
int priority(char c)
{
		if(c<='9'&&c>='0')
				return 10;
		else
		{
				switch(c)
				{
						case '+':
						case '-':
								return 1;
								break;
						case '*':
						case '/':
								return 2;
								break;
						case '(':
						case ')':
								return 3;
				}
		}
}

int main()
{
		string exp;
		getline(cin,exp);
		stack<char> oper;
		stringstream ss;
		for(int i=0;i<exp.size();i++)
		{
				if(exp[i]==' ')
						continue;
				int score=priority(exp[i]);
				if(score==10)//是数字的话就输出
				{
						ss<<exp[i];
				}
				else
				{
						while(!oper.empty()&&priority(oper.top())>=score&&((oper.top()=='('&&score==3)||(oper.top()!='(')))//把所有优先级大于当前符号都输出
						{
								if(oper.top()!='(')
										ss<<" "<<oper.top();
								oper.pop();
						}
						ss<<" ";//这里输出空格是为了防止两个数字粘在一起
						if(exp[i]!=')')
								oper.push(exp[i]);
				}
		}
		while(!oper.empty())//处理完整个字符串之后把栈所有符号都输出
		{
				if(oper.top()!='(')
						ss<<" "<<oper.top();
				oper.pop();
		}
		cout<<ss.str()<<endl;
		cout<<sum(ss.str())<<endl;
		return 0;
}

