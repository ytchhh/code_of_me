#include"./ytcalloc.h"
#include<vector>


int main()
{
	/*
	int ia[5] = {0,1,2,3,4};
	unsigned int i;

	//调动自己所写的allocator
	vector<int,ytc::allocator<int>> iv(ia,ia+5);
	for(int i = 0; i < iv.size(); ++i)
		cout<<iv[i]<<' ';
	cout<<endl;
	*/

	String s1("abc");
	String s2("xyz");

	vector<String,ytc::allocator<String>> v(2);
	v.push_back(s1);
	v.push_back(s2);
	return 0;
}
