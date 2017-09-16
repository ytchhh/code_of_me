nclude <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
  当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
 ******************************开始写代码******************************/
bool IsPerfect(int num) {
		vector<int> ve;
		int sum = 0;
		for(int i = 1; i < num; ++i)
		{
				if(num%i == 0)
				{
						ve.push_back(i);
						sum += i;
				}
		}
		return sum == num;
}
/******************************结束写代码******************************/


int main() {
		bool res;

		int _num;
		cin >> _num;
		cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');



		res = IsPerfect(_num);
		cout << res << endl;

		return 0;

}
