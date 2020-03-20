
#include<stdio.h>

unsigned char background[10][10] =
{
	{0,0,0,0,0,0,0,0,0,0},
	{1,1,1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0,0},
	{1,1,1,0,0,0,0,0,0,0},
	{1,0,1,0,0,0,0,0,0,0},
	{1,1,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,0,1,0,0,1},
    {1,1,0,0,0,0,1,0,0,1},
	{1,1,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,0,1,0,0,1},
};

unsigned char sharpe[][4] =
{
	{0,0,0,0},
	{1,1,1,0},
	{0,0,1,0},
	{0,0,0,0}
};

void background_show(void)
{
	int i = 0, j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%d ", background[i][j]);
		}
		printf("\n");
	}
}

void down(unsigned char x, unsigned char y)
{
	int i = 0;

	for (i = 0; i < 4; i++)
	{
		if (background[x+4][y+i] + sharpe[3][i] > 1)
		{
			//不能再下
		}
	}


}

int flag = 0;
void dispear(unsigned char x, unsigned char y)
{
	int i = 0, j = 0;
	int a = 0, b = 4;

	for (i = y; i < 10; i++)
	{
		a = 0; b--;
		for (j = x; j < x+4; j++)
		{
			if (sharpe[b][a] + background[i][j] > 1)
			{
				flag = 1;
				break;
			}
			else if (sharpe[b][a] + background[i][j] == 1)
			{

			}
			else
			{
				b = 3;
			}
			a++;
		}
		
		if (flag) break;
		
		
	}

	printf("a = %d, b = %d \n", a, b);
	printf("i = %d, j = %d \n", i, j);
}

void compare(unsigned char x, unsigned char y)
{
	int i = 0, j = 0, a = 0, b = 0;

	for (i = x; i < x+4; i++, b=0, a++)
	{
		for (j = y; j < y + 4; j++)
		{
			if (sharpe[a][b] + background[i][j] < 2)
			{
				
			}
			else
			{
				printf("a = %d, b = %d \n", a, b);
				printf("i = %d, j = %d \n", i, j);
				return;
			}
		}
	}
}

int main(void)
{
	background_show();
	//dispear(1,1);

	compare(0, 2);

	return 0;
}