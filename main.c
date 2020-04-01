#include "main.h"

int X = 0, Y = 0;
char key = 0;
unsigned char sharpe[4][4];
int SCORE = 0;

void sharpe_show(int x, int y)
{
	int i = x - X, j = y - Y;

	if ((i > -1 && i < 4 && j > -1 && j < 4 && sharpe[i][j]) || background[x][y])
		printf("■");
	else
		printf("　");
}

void all_show(void)
{
	int i = 0, j = 0;
	printf("┏━━━━━━━━━━━━━━━┓\n");
	printf("┃ SCORE：%5d  ┃\n",SCORE); 
	printf("┗━━━━━━━━━━━━━━━┛\n");

	printf("┏━━━━━━━━━━━━━━━━━━━━┓\n"); //上边框
	for (i = 0; i < 19; i++)
	{
		printf("┃"); //左边框
		for (j = 1; j < 11; j++)
			sharpe_show(i, j);
		printf("┃\n"); //右边框
	}
	printf("┗━━━━━━━━━━━━━━━━━━━━┛\n");//下边框
}

void mass(unsigned char x, unsigned char y)//将背景和图形混合
{
	int i = 0, j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (sharpe[i][j])  background[x + i][y + j] = 1;
		}
	}
}

int handle(void) //判断并消除符合条件的行
{
	int i = 0, j = 0, c = 0, k = 18, s = 0;
	unsigned char copy[20][15] = { 0 };

	memcpy(copy, background_default, 300 * sizeof(copy[0][0]));

	for (i = 18; i > 0; i--)
	{
		c = 0;
		for (j = 10; j > 0; j--)
		{
			if (background[i][j]) c++;
			else break;
		}
		if (c == 10) {
			s++;
			for (j = 1; j < 11; j++) background[i][j] = 0;
			
			all_show();Sleep(100);
			system("cls"); //清屏
		}
		else
		{
			for (j = 1; j < 11; j++) copy[k][j] = background[i][j];
			k--;
		}
	}
	
	memcpy(background,copy,300*sizeof(copy[0][0]));

	switch (s) {
		case 1: SCORE += 10; break;
		case 2: SCORE += 30; break;
		case 3: SCORE += 50; break;
		case 4: SCORE += 80; break;
		default: break;
	}
	return 1;
}

int compare(unsigned char x, unsigned char y)
{
	int i = 0, j = 0, a = 0, b = 0;

	if (x > 16 || y < 0 || y > 11) return 0;//超出屏幕范围

	for (i = x; i < x + 4; i++, b = 0, a++)
	{
		for (j = y; j < y + 4; b++, j++)
		{
			if (sharpe[a][b] + background[i][j] > 1)
				return  0;
		}
	}
	return 1;
}

void timer_handle(void)
{
#if 0 
	static int count = 0;
	count++;
	if (count > 2) {
		count = 0;  c = 'c';
	}
#else
	key = 'c';
#endif
}

int r = 0, space = 0, old_space = 0;
const int sharpe_count[] = { 3,3,1,1,3,1,1 };
const int sharpe_sum[] = { 0,4,8,10,12,16,18 };
void r_rand(void)//产生新图形
{
	srand((unsigned int)time(0));
	r = rand() % 7;
	memcpy(sharpe, figure[sharpe_sum[r]], 16 * sizeof(sharpe[0][0]));
	space = 0;X = 0; Y = 4;

	if (!compare(X+1, Y))  //封顶，结束游戏
	{
		all_show();
		printf("Game Over!!!");
		while (1);
	}
}

void sharpe_change()
{
	old_space = space;
	space++;
	if (space > sharpe_count[r]) space = 0;
	memcpy(sharpe, figure[sharpe_sum[r] + space], 16 * sizeof(sharpe[0][0]));

	while (!compare(X, Y)) //变形时遇到的边界问题
	{
		//if ( Y > 1) Y--;  //是否适应边界
		//else 
		{
			space = old_space;
			memcpy(sharpe, figure[sharpe_sum[r] + space], 16 * sizeof(sharpe[0][0]));
			break;
		}
	}
}

int main2(void)
{
	timeSetEvent(1000, 1, (LPTIMECALLBACK)timer_handle, (DWORD)1, TIME_PERIODIC);//定时器 - 1000ms
	r_rand();

	while (1)
	{
		if (_kbhit()) key = _getch();//如果键盘被按下,判断字符

		if ((key == 'd') && (Y < 11) && compare(X, Y + 1)) Y++;
		else if ((key == 'a') && (Y > 0) && compare(X, Y - 1)) Y--;
		else if ((key == 's') && (X < 16)) X++;
		else if ((key == 'c') && (X < 16)) X++;
		else if (key == ' ')  sharpe_change();
		else continue;

		system("cls"); //清屏

		if (compare(X, Y)) //图形可以嵌合背景
		{
			if (!compare(X + 1, Y))//图形的向下一步不可嵌合背景
			{
				if(key == 'c'||key == 's') //图形向下移动
				{
					mass(X, Y);
					handle();
					r_rand();//产生新的图形
				}
				else if (key == 'a' || key == 'd')
				{ 
					mass(X, Y);
					r_rand();//新的图形
				}
			}
		}
		all_show();
		key = 0;
	}
	return 0;
}
