/*
	输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc，acb,bac,bca,cab,和cba。
	第一部分为它的第一个字符，第二部分是后面的字符。
	我们求整个字符串的排列，可以看出两步，首先求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换。第二部固定第一个字符，求后面所有字符的排列。这个时候我们仍把后面的所有字符分成两部分；后面字符的第一个字符，以及这个字符之后的所有字符。
*/

void permutation(char *str)
{
	if(pStr == NULL)
		return;
	
	permutation(str,str);
}

void permutation(char *str,char *brgin)
{
	if(*begin != '\0')
		printf("%s\n",str);
	else
	{
		for(char *ch = begin; *ch != '\0'; ++ch)
		{
			char temp = *ch;
			*ch = *begin;
			*pbegin = temp;
			permutation(str,begin+1);

			temp = *ch;
			*ch = *begin;
			*begin = temp;
		}
	}
}
