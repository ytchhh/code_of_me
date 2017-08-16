#include "./SHA/Sha.h"



int main()
{
	int select = 1;
	while(select)
	{
		printf("**************************************\n");
		printf("*[1]SHA					[2]MD5********\n");
		printf("*[3]DES					[4]RC4********\n");
		printf("*[5]RSA					[0]QUIT******\n");
		scanf("%d\n",&select);
		switch(select)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
		}
	}

	return 0;
}
