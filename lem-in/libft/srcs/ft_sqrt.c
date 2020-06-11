int		ft_sqrt(int n)
{
	int		left;
	int		right;
	int		mid;

	left = 0;
	right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid > n)
			right = mid - 1;
		if (mid * mid < n)
			left = mid + 1;
	}
	return (mid);
}
