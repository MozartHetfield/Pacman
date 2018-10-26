#include <stdio.h>
#include <ctype.h>

void show_map_0(char hero, int N, int M, int x, int y)
{
	int i, j;
	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < M + 2; j++)
		{
			if (i == 0 || i == N + 1)
				printf("*");
			else if (j == 0 || j == M + 1)
				printf("*");
			else if (i == x && j == y)
				printf("%c", hero);
			else
				printf(" ");
		}
		printf("\n");
	}
}
void show_map_1(char hero, int N, int M, int x, int y, int l, int c, char m)
{
	int i, j;
	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < M + 2; j++)
		{
			if (i == 0 || i == N + 1)
				printf("*");
			else if (j == 0 || j == M + 1)
				printf("*");
			else if (i == x && j == y)
				printf("%c", hero);
			else if (l == i && j == c)
				printf("x");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void show_map_2(char hero, int N, int M, int x, int y, int l, int c, int l2, int c2, char m, char m2)
{
	int i, j;
	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < M + 2; j++)
		{
			if (i == 0 || i == N + 1)
				printf("*");
			else if (j == 0 || j == M + 1)
				printf("*");
			else if (i == x && j == y)
				printf("%c", hero);
			else if (l == i && j == c)
				printf("x");
			else if (l2 == i && c2 == j)
				printf("x");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void show_map_3(char hero, int N, int M, int x, int y, int l, int c, int l2, int c2, int l3, int c3, char m, char m2, char m3)
{
	int i, j;
	for (i = 0; i < N + 2; i++)
	{
		for (j = 0; j < M + 2; j++)
		{
			if (i == 0 || i == N + 1)
				printf("*");
			else if (j == 0 || j == M + 1)
				printf("*");
			else if (i == x && j == y)
				printf("%c", hero);
			else if (l == i && j == c)
				printf("x");
			else if (l2 == i && c2 == j)
				printf("x");
			else if (l3 == i && c3 == j)
				printf("x");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void move_pos_0(char* hero, char move, int N, int M, int* x, int* y)
{
	if (!isspace(move))
	{
		if (move == 'w')
		{
			(*x)--;
			if ((*x) >= 1)
				*hero = '^';
			if ((*x) < 1)
				(*x)++;
		}
		else if (move == 's')
		{
			(*x)++;
			if ((*x) <= N)
				*hero = 'v';
			if ((*x) > N)
				(*x)--;
		}
		else if (move == 'd')
		{
			(*y)++;
			if ((*y) <= M)
				*hero = '>';
			if ((*y) > M)
				(*y)--;
		}
		else if (move == 'a')
		{
			(*y)--;
			if ((*y) >= 1)
				*hero = '<';
			if ((*y) < 1)
				(*y)++;
		}
		else if (move == 'q')
		{
			return;
		}
	}
}
void move_pos_1(char* hero, char move, int N, int M, int* x, int* y, int* l, int* c, char m, int* count)
{
	if (!isspace(move))
	{
		if (move == 'w')
		{
			(*x)--;
			if ((*x) >= 1)
				*hero = '^';
			else if ((*x) < 1)
				(*x)++;
		}
		else if (move == 's')
		{
			(*x)++;
			if ((*x) <= N)
				*hero = 'v';
			else if ((*x) > N)
				(*x)--;
		}
		else if (move == 'd')
		{
			(*y)++;
			if ((*y) <= M)
				*hero = '>';
			else if ((*y) > M)
				(*y)--;
		}
		else if (move == 'a')
		{
			(*y)--;
			if ((*y) >= 1)
				*hero = '<';
			else if ((*y) < 1)
				(*y)++;
		}
		else if (move == 'q')
		{
			return;
		}
		if (m == 'f')
		{
			if ((*x) == (*l) && (*y) == (*c))
				return;
		}
		else if (m == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l))
				{
					if ((*y) < (*c))
						(*c)--;
					else if ((*y) > (*c))
						(*c)++;
				}
				if ((*x) > (*l))
				{
					if ((*y) == (*c))
						(*l)++;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)++;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)++;
					}
				}
				if ((*x) < (*l))
				{
					if ((*y) == (*c))
						(*l)--;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)--;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)--;
					}
				}
			}
			(*count)++;
		}
	}
}
void move_pos_2(char* hero, char move, int N, int M, int* x, int* y, int* l, int* c, int* l2, int* c2, char m, char m2, int* count)
{
	if (!isspace(move))
	{
		if (move == 'w')
		{
			(*x)--;
			if ((*x) >= 1)
				*hero = '^';
			else if ((*x) < 1)
				(*x)++;
		}
		else if (move == 's')
		{
			(*x)++;
			if ((*x) <= N)
				*hero = 'v';
			else if ((*x) > N)
				(*x)--;
		}
		else if (move == 'd')
		{
			(*y)++;
			if ((*y) <= M)
				*hero = '>';
			if ((*y) > M)
				(*y)--;
		}
		else if (move == 'a')
		{
			(*y)--;
			if ((*y) >= 1)
				*hero = '<';
			else if ((*y) < 1)
				(*y)++;
		}
		else if (move == 'q')
		{
			return;
		}
		if (m == 'f')
		{
			if (x == l && y == c)
				return;
		}
		else if (m == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l))
				{
					if ((*y) < (*c))
						(*c)--;
					else if ((*y) > (*c))
						(*c)++;
				}
				if ((*x) > (*l))
				{
					if ((*y) == (*c))
						(*l)++;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)++;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)++;
					}
				}
				if ((*x) < (*l))
				{
					if ((*y) == (*c))
						(*l)--;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)--;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)--;
					}
				}
			}
		}
		if (m2 == 'f')
		{
			if (x == l2 && y == c2)
				return;
		}
		else if (m2 == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l2))
				{
					if ((*y) < (*c2))
						(*c2)--;
					else if ((*y) > (*c2))
						(*c2)++;
				}
				if ((*x) > (*l2))
				{
					if ((*y) == (*c2))
						(*l2)++;
					if ((*y) > (*c2))
					{
						(*c2)++;
						(*l2)++;
					}
					if ((*y) < (*c2))
					{
						(*c2)--;
						(*l2)++;
					}
				}
				if ((*x) < (*l2))
				{
					if ((*y) == (*c2))
						(*l2)--;
					if ((*y) > (*c2))
					{
						(*c2)++;
						(*l2)--;
					}
					if ((*y) < (*c2))
					{
						(*c2)--;
						(*l2)--;
					}
				}
			}
		}
		(*count)++;
	}
}
void move_pos_3(char* hero, char move, int N, int M, int* x, int* y, int* l, int* c, int* l2, int* c2, int* l3, int* c3, char m, char m2, char m3, int* count)
{
	if (!isspace(move))
	{
		if (move == 'w')
		{
			(*x)--;
			if ((*x) >= 1)
				*hero = '^';
			else if ((*x) < 1)
				(*x)++;
		}
		else if (move == 's')
		{
			(*x)++;
			if ((*x) <= N)
				*hero = 'v';
			else if ((*x) > N)
				(*x)--;
		}
		else if (move == 'd')
		{
			(*y)++;
			if ((*y) <= M)
				*hero = '>';
			else if ((*y) > M)
				(*y)--;
		}
		else if (move == 'a')
		{
			(*y)--;
			if ((*y) >= 1)
				*hero = '<';
			else if ((*y) < 1)
				(*y)++;
		}
		else if (move == 'q')
		{
			return;
		}
		if (m == 'f')
		{
			if (x == l && y == c)
				return;
		}
		else if (m == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l))
				{
					if ((*y) < (*c))
						(*c)--;
					else if ((*y) > (*c))
						(*c)++;
				}
				if ((*x) > (*l))
				{
					if ((*y) == (*c))
						(*l)++;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)++;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)++;
					}
				}
				if ((*x) < (*l))
				{
					if ((*y) == (*c))
						(*l)--;
					if ((*y) > (*c))
					{
						(*c)++;
						(*l)--;
					}
					if ((*y) < (*c))
					{
						(*c)--;
						(*l)--;
					}
				}
			}
		}
		if (m2 == 'f')
		{
			if (x == l2 && y == c2)
				return;
		}
		else if (m2 == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l2))
				{
					if ((*y) < (*c2))
						(*c2)--;
					else if ((*y) > (*c2))
						(*c2)++;
				}
				if ((*x) > (*l2))
				{
					if ((*y) == (*c2))
						(*l2)++;
					if ((*y) > (*c2))
					{
						(*c2)++;
						(*l2)++;
					}
					if ((*y) < (*c2))
					{
						(*c2)--;
						(*l2)++;
					}
				}
				if ((*x) < (*l2))
				{
					if ((*y) == (*c2))
						(*l2)--;
					if ((*y) > (*c2))
					{
						(*c2)++;
						(*l2)--;
					}
					if ((*y) < (*c2))
					{
						(*c2)--;
						(*l2)--;
					}
				}
			}
		}
		if (m3 == 'f')
		{
			if (x == l3 && y == c3)
				return;
		}
		else if (m3 == 'm')
		{
			if ((*count) % 2 == 1)
			{
				if ((*x) == (*l3))
				{
					if ((*y) < (*c3))
						(*c3)--;
					else if ((*y) > (*c3))
						(*c3)++;
				}
				if ((*x) > (*l3))
				{
					if ((*y) == (*c3))
						(*l3)++;
					if ((*y) > (*c3))
					{
						(*c3)++;
						(*l3)++;
					}
					if ((*y) < (*c3))
					{
						(*c3)--;
						(*l3)++;
					}
				}
				if ((*x) < (*l3))
				{
					if ((*y) == (*c3))
						(*l3)--;
					if ((*y) > (*c3))
					{
						(*c3)++;
						(*l3)--;
					}
					if ((*y) < (*c3))
					{
						(*c3)--;
						(*l3)--;
					}
				}
			}
		}
		(*count)++;
	}
}


int main()
{
	char hero = 'v', move;
	int N, M, x, y, P = 0;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &P);
	if (x < 1 || y < 1 || N < y || M < x || 80 < N || 80 < M || P < 0 || P > 3)
		return 0;
	int l, l2, l3, c, c2, c3;
	int count = 0;
	char m, m2, m3;

	switch (P)
	{
	case (0):
		show_map_0(hero, N, M, y, x);
		while (y != N || x != M)
		{
			scanf("%c", &move);
			if (!isspace(move))
			{
				if (move == 'q')
					return 0;
				move_pos_0(&hero, move, N, M, &y, &x);
				if (y == N && x == M)
				{
					show_map_0(hero, N, M, y, x);
					printf("GAME COMPLETED\n");
					return 0;
				}
				show_map_0(hero, N, M, y, x);
			}

		}
	case (1):
		scanf("%d %d %c", &l, &c, &m);
		show_map_1(hero, N, M, y, x, l, c, m);
		while (y != N || x != M)
		{
			scanf(" %c", &move);
			if (move == 'q')
				return 0;
			move_pos_1(&hero, move, N, M, &y, &x, &l, &c, m, &count);
			if (y == l && x == c)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == N && x == M)
			{
				show_map_1(hero, N, M, y, x, l, c, m);
				printf("GAME COMPLETED\n");
				return 0;
			}
			show_map_1(hero, N, M, y, x, l, c, m);
		}
	case (2):
		scanf("%d %d %c", &l, &c, &m);
		scanf("%d %d %c", &l2, &c2, &m2);
		show_map_2(hero, N, M, y, x, l, c, l2, c2, m, m2);
		while (y != N || x != M)
		{
			scanf(" %c", &move);
			if (move == 'q')
				return 0;
			move_pos_2(&hero, move, N, M, &y, &x, &l, &c, &l2, &c2, m, m2, &count);
			if (y == l && x == c)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == l2 && x == c2)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == N && x == M)
			{
				show_map_2(hero, N, M, y, x, l, c, l2, c2, m, m2);
				printf("GAME COMPLETED\n");
				return 0;
			}
			show_map_2(hero, N, M, y, x, l, c, l2, c2, m, m2);
		}
	case (3):
		scanf("%d %d %c", &l, &c, &m);
		scanf("%d %d %c", &l2, &c2, &m2);
		scanf("%d %d %c", &l3, &c3, &m3);
		show_map_3(hero, N, M, y, x, l, c, l2, c2, l3, c3, m, m2, m3);
		while (y != N || x != M)
		{
			scanf(" %c", &move);
			if (move == 'q')
				return 0;
			move_pos_3(&hero, move, N, M, &y, &x, &l, &c, &l2, &c2, &l3, &c3, m, m2, m3, &count);
			if (y == l && x == c)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == l2 && x == c2)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == l3 && x == c3)
			{
				printf("GAME OVER\n");
				return 0;
			}
			if (y == N && x == M)
			{
				show_map_3(hero, N, M, y, x, l, c, l2, c2, l3, c3, m, m2, m3);
				printf("GAME COMPLETED\n");
				return 0;
			}
			show_map_3(hero, N, M, y, x, l, c, l2, c2, l3, c3, m, m2, m3);
		}
	}
	return 0;
}

