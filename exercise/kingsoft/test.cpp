#include <iostream>
using namespace std;

int main()
{
	char *c[] = {"ENTER","NEW","POINT","FIRST"};
	char **cp[] = {c+3,c+2,c+1,c};
	char ***cpp = cp;

	printf("%s\n",**++cpp);
	printf("%s\n",*--*++cpp+3);
	printf("%s\n",*cpp[-2]+3);
	printf("%s\n",cpp[-1][-1]+1);
	return 0;
}


/*
	**++cpp
	cpp刚开始指向cp的首地址，++cpp指向C+2的地址，*(C+2)得到C的第三个的地址，再解引用得到"POINT"
	*--*++cpp+3
	cpp由于自加之后现在指向了C+2的地址，根据优先级，先执行*++cpp，指向了C+1的地址并且解引用即为"NEW"的地址，再执行--为"ENTER"的地址，在执行+3指针指到了E的地址。
	*cpp[-2]+3
	cpp现在指向了C+1的地址，cpp[-2]即*(cpp-2)即C+3所指向的"FIRST"的地址，再解引用就得到了"FIRST",+3指向了S的位置。
	cpp[-1][-1]+1
	cpp[-1]即，*(cpp-1),即C+2所指向的"POINT"的地址，*((C+2)-1)就指向了"NEW"的位置，再加1就指向了E的位置.
*/
