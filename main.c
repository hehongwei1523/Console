#include "main.h"

int X = 0, Y = 0;
char c = 0;
unsigned char sharpe[4][4];

void sharpe_show(int x, int y)
{
	int i = x - X, j = y - Y;

	if ((i > -1 && i < 4 && j > -1 && j < 4 && sharpe[i][j]) || background[x][y])
		printf("��");
	else
		printf("��");
}

void all_show(void)
{
	int i = 0, j = 0;
	printf("x\\y ");
	for (j = 0; j < 12; j++) printf("%d ", j);
	printf("\n--------------------------------------\n");

	for (i = 0; i < 19; i++)
	{
		printf(" %2d |", i);
		for (j = 1; j < 11; j++)
		{
			sharpe_show(i, j);
		}
		printf("\n");
	}
}

void mass(unsigned char x, unsigned char y)//��������ͼ�λ��
{
	int i = 0, j = 0;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (sharpe[i][j])
				background[x + i][y + j] = 1;
		}
	}
}

int Z = 0;

int handle(void) //�жϲ�����������������
{
	int i = 0, j = 0, c = 0, k = 18;
	unsigned char copy[20][15] = { 0 };

	memcpy(copy, background_default, 300 * sizeof(copy[0][0]));
	Z = 0;
	for (i = 18; i > 0; i--)
	{
		c = 0;
		for (j = 10; j > 0; j--)
		{
			if (background[i][j])
				c++;
			else break;
		}
		if (c == 10) {
			Z++;
			for (j = 1; j < 11; j++) background[i][j] = 0;
			
			all_show();
			Sleep(100);
			system("cls"); //����
		}
		else
		{
			for (j = 1; j < 11; j++) copy[k][j] = background[i][j];
			k--;
		}
	}
	
	memcpy(background,copy,300*sizeof(copy[0][0]));

	return 1;
}

int compare(unsigned char x, unsigned char y)
{
	int i = 0, j = 0, a = 0, b = 0;

	if (x > 16) return 0;//������Ļ��Χ
	if (y < 0 || y > 11) return 0;

	for (i = x; i < x + 4; i++, b = 0, a++)
	{
		for (j = y; j < y + 4; b++, j++)
		{
			if (sharpe[a][b] + background[i][j] < 2);
			else return  0;
		}
	}
	return 1;
}

void timer_handle(void){  c = 'c'; }

int r = 0, space = 0, count = 0;
int sharpe_count[] = { 3,3,1,1,3,1,1 };
int sharpe_sum[] = { 0,4,8,10,12,16,18 };
void r_rand(void)//������ͼ��
{
	srand(time(0));
	r = rand() % 7;
	space = 0;
	memcpy(sharpe, figure[sharpe_sum[r] + space], 16 * sizeof(sharpe[0][0]));
	X = 0; Y = 4;
}

void sharpe_change()
{
	space++;
	if (space > sharpe_count[r]) space = 0;
	memcpy(sharpe, figure[sharpe_sum[r] + space], 16 * sizeof(sharpe[0][0]));
}

int main8(void)
{
	timeSetEvent(700, 1, (LPTIMECALLBACK)timer_handle, (DWORD)1, TIME_PERIODIC);//��ʱ�� - 1000ms
	r_rand();

	while (1)
	{
		if (_kbhit()) //������̱�����
		{
			c = _getch();//�ж��ַ�
		}

		if ((c == 'd')&&(Y<11)) Y++;
		else if ((c == 'a')&&(Y>0)) Y--;
		else if ((c == 's')&&(X<16)) X++;
		else if ((c == 'c') && (X < 16))
		{
			count++;
			if (count > 2) {count = 0; X++; } else continue;
		}
		else if (c == ' ')  sharpe_change();
		//else if (c == 'w') X--;

		if(c == 'd' || c == 'a' || c == 's' || c == 'c' || c == ' ') 
		{
			system("cls"); //����

			if (compare(X, Y)) //ͼ�ο���Ƕ�ϱ���
			{
				if (!compare(X + 1, Y))//ͼ�ε�����һ������Ƕ�ϱ���
				{
					if(c == 'c'||c == 's') //ͼ�������ƶ�
					{
						mass(X, Y);
						handle();
						r_rand();//�����µ�ͼ��
					}
					else if (c == 'a' || c == 'd')
					{ 
						mass(X, Y);
						r_rand();//�µ�ͼ��
					}
				}
			}
			else//�����ƶ��������Ƕ�ϱ���
			{
				if (c == 'd') { Y--; }
				else if (c == 'a') { Y++; }
				else if (c == 's') { X--; }
				//else if (c == 'w') { X++; }
			}
			all_show();
			c = 0;
		}
	}
	return 0;
}
