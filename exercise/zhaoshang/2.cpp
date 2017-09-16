nclude <iostream>
using namespace std;

int main()
{
		int m;
		cin >> m;
		if(m < 0)
				return 0;
		int a[m];
		for(int i = 0; i < m; ++i)
				cin >> a[i];
		int numa = 0,numb = 0;
		for(int i = 0; i < m; )
		{
				numa += a[i];
				if(i+1 < m)
						numa += a[i+1];
				if(i+2 < m )
				{
						numb += a[i+2];
						if(i+3 < m)
								numb += a[i+3];
				}
				i += 4;
		}
		if(numa > numb)
				cout << "true" << endl;
		else
				cout << "false" << endl;
		return 0;
}
