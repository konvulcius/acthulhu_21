int		ft_factorial(int n)
{
	int r;

	if (n < 0 || n > 12)
		return (0);
	if (n == 0 || n == 1)
		return (1);
	r = 1;
	while (n)
		r *= n--;
	return (r);
}
