void	ft_swap_nums(int *a, int *b)
{
	int temp;

	if (a && b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
