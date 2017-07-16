/*
	顺时针打印矩阵
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。例如：输入如下矩阵：
	1	2	3	4
	5	6	7	8
	9	10	11	12
	13	14	15	16
	则依次打印出数字1、2、3、4、8、12、16、15、14、13、9、5、6、7、11、10
	由于是以外圈到内圈的顺序依次打印，我们可以把矩阵想象成若干个圈，如图所示，我们可以用一个循环来打印矩阵，每一次打印矩阵中的一个圈。
	接下来分析循环结束的条件。假设这个矩阵的行数是rows，列数是columns。打印第一圈的左上角的坐标是(0,0)，第二圈的左上角的坐标是(1,1)，依次类推。我们注意到，左上角的坐标中行标和列标总是相同的，于是可以在矩阵中选取左上角为(start,start)的一圈作为我们分析的目标、
	对于一个5*5的矩阵而言，最后一圈只有一个数字，对应的坐标为(2,2)。我们发现5>2*2。对于一个6*6的矩阵而言，最后一圈有4个数字，其左上角的坐标任然是(2,2)。我们发现6>2*2依然成立，。于是我们可以得出，让循环继续的条件是columns>startX*2并且rows>startY*2。

*/

void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
	if(numbers == NULL || columns <= 0 || rows <= 0)
		return;
	
	int start = 0;

	while(columns > start*2 && rows > start*2)
	{
		PrinMatrixInCircle(numbers,columns,rows,start);
		++start;
	}
}

/*
	仔细分析打印每一步的条件，第一步总是需要的，因为打印一圈至少有一步。如果只有一行，那么就不用第二步了。
	也就是需要第二步的前提条件是终止行号大于起始行号。需要第三步打印的前提条件圈内至少有两行两列，也就是说除了要求终止行号大于起始行号之外，还要求终止列号大于起始列号。同理，需要打印出第四步的前提条件是至少有三行两列，因此要求终止行号比起始行号至少大2，同时终止列号大于起始列号。
*/

void PrinMatrixInCircle(int** numbers,int columns,int rows,int start)
{
	int endX = columns-1-start;
	int endY = rows-1-start;

	for(int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		printNumber(number);
	}

	if(start < endY)
	{
		for(int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			printNumber(number);
		}
	}

	if(start < endX && start < endY)
	{
		for(int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	if(start < endX && start < endY - 1)
	{
		for(int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			printNumber(numbers);
		}
	}
}
