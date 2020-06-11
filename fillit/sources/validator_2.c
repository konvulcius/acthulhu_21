#include "monkey_cthulhu.h"

int		fig_1(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 3 < 4)
				{
					if (p[a + 1][b] == '#' && p[a + 2][b] == '#' &&
						p[a + 3][b] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_2(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 1 < 4 && b + 2 < 4)
				{
					if (p[a + 1][b] == '#' && p[a + 1][b + 1] == '#' &&
						p[a + 1][b + 2] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_3(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 1 < 4 && b - 2 >= 0)
				{
					if (p[a + 1][b - 2] == '#' &&
					p[a + 1][b - 1] == '#' && p[a + 1][b] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_4(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 2 < 4 && b - 1 >= 0)
				{
					if (p[a + 1][b] == '#' && p[a + 2][b - 1] == '#' &&
						p[a + 2][b] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}

int		fig_5(char **p)
{
	int a;
	int b;

	a = 0;
	while (a < LEN_A)
	{
		b = 0;
		while (b < LEN_B)
		{
			if (p[a][b] == '#' && p[a][b + 1] != '#')
			{
				if (a + 2 < 4 && b + 1 < 4)
				{
					if (p[a + 1][b] == '#' && p[a + 2][b] == '#' &&
						p[a + 2][b + 1] == '#')
						return (1);
				}
			}
			b++;
		}
		a++;
	}
	return (0);
}
