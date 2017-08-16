
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>* getGray(int n) 
{
		if(n == 1)
		{
				vector<string> *ve = new vector<string>;
				ve->push_back("0");
				ve->push_back("1");
				return ve;
		}
		else
		{
			vector<string> *ve = getGray(n-1);
			vector<string> *v2 = new vector<string>;
			int vesize = ve->size();
			for(int i = 0; i < vesize; ++i)
			{
				if(i%2 == 0)
				{
					v2->push_back((*ve)[i]+"0");
					v2->push_back((*ve)[i]+"1");
				}
				else
				{
					v2->push_back((*ve)[i]+"1");
					v2->push_back((*ve)[i]+"0");
				}
			}
			return v2;
		}
}

int main()
{
		vector<string> *ve;
		ve = getGray(3);
		vector<string>::iterator it;
		for(it = ve->begin(); it != ve->end(); ++it)
		{
			cout<<*it<<endl;
		}
		return 0;
}
