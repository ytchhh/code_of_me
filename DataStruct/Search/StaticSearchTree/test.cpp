#include"./searchList.h"

#if 0
int main()
{
	/*
	dataList<int,int> my_list1;
	cin>>my_list1;
	cout<<my_list1;
	*/
	const int Size = 10;
	searchList<int,int> L1(Size);		//定义int型搜索表L1
	int Target;
	int Location;
	cin>>L1;							//输入L1
	cout<<L1;
	cout<<"Search for a integer:";
	cin>>Target;						//输入要搜索的数据
	
	/*
	if((Location = L1.SeqSearch(Target)) != (L1.Length() + 1))	//搜索成功
		cout<<"Found at index "<<Location<<endl;
	else								//搜索不成功
		cout<<"Not Found!"<<endl;
	*/
	int loc = 1;
	int Pos = L1.SeqSearch1(Target,loc);
	if(Pos != 0)
		cout<<"Found at index "<<Pos<<endl;
	else
		cout<<"Not Found"<<endl;
	return 0;
}
#endif

#if 1
int main()
{
	SortList<int,int> my_sort;
	cin>>my_sort;
	cout<<my_sort;
	int Target;
	int Location;
	cout<<"Search for a number:";
	cin>>Target;
	if((Location = my_sort.SequentSearch(Target)) != 0)
		cout<<"Found at index "<<Location<<endl;
	else
		cout<<"Not Found"<<endl;
	return 0;
}

#endif
