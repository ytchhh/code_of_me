#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <cstdlib>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
  当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
 ******************************开始写代码******************************/
bool Ishuiwen(string& temp)
{
		for(int i = 0; i < temp.size()/2; ++i)
		{
				if(temp[i] != temp[temp.size()-i-1])
						return false;
		}
		return true;
}

string NearestNum(string& n) {
		long long val;
		val = std::stoll(n);
		long long val1 = val, val2 = val;
		while(1)
		{
				val1++;
				string temp = to_string(val1);
				if(Ishuiwen(temp))
						break;
		}
		while(1)
		{
				val2--;
				string temp = to_string(val2);
				if(Ishuiwen(temp))
						break;
		}
		if((val-val2) <= (val1-val))
				return to_string(val2);
		else
				return to_string(val1);
}
/******************************结束写代码******************************/


int main() {
		string res;

		string _n;
		getline(cin, _n);

		res = NearestNum(_n);
		cout << res << endl;

		return 0;

}

