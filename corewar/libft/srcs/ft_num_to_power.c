long long	ft_num_to_power(long long num, int power)
{
	int			p;
	long long	r;

	p = power;
	r = 1;
	while (p > 0)
	{
		r *= num;
		--p;
	}
	return (r);
}
