#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
		int n;
		cin >> n;
		vector<vector<int> > pend(n, vector<int>(3, 0));
		vector<string> nums(n, string());
		for (int i = 0; i < n; i++) 
		{
				cin >> nums[i];
				for (int j = 0; j < 3; j++) 
				{
						cin >> pend[i][j];
				}
				sort(pend[i].begin(), pend[i].end());

				int k = 2;
				for (int j = 0; j < nums[i].length() && k >= 0; j++) 
				{
						if (nums[i][j] < pend[i][k] + '0') 
						{
								char temp = nums[i][j];
								nums[i][j] = pend[i][k] + '0';
								int m = j;
								while(++m < nums[i].length())
								{
									if(nums[i][m] == temp)
										nums[i][m] = pend[i][k]+'0';
								}
								k--;
						}
				}
		}

		for (int i = 0; i < n; i++) 
		{
				cout << nums[i] << endl;
		}
		return 0;
}
