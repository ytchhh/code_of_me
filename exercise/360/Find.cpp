/*
	有一个二维float数组，有m行n列，每一个行和列上都是递减序列，请编程实现在这个矩阵中查找值等于v的元素的函数，如果找到返回其下标。
*/

#include <math.h>

#include <iostream>
using namespace std;

int* Find(float matrix[][4], int rows, int columns, int numbers)
{
	if(matrix!=NULL && rows>0 && columns>0)
	{
		int *a = new int[2];
		int row = 0;
		int column = columns - 1;
		while(row < rows && column < columns)
		{
			if( (fabs(matrix[row][column]-numbers))<1e-7 )
			{
				a[0] = row;
				a[1] = column;
				return a;
			}
			else if(matrix[row][column] < numbers)
				column--;
			else
				row++;
		}
		return NULL;
	}
}

int main()
{
	float a[4][4] = {15,11,8,6,13,10,7,4,12,9,4,2,9,8,2,1};
	int *b = Find(a,4,4,9);
	cout<<b[0]<<" "<<b[1]<<endl;
	delete []b;
	return 0;
}
