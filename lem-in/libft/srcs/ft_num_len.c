#include <stddef.h>

size_t	ft_num_len(long long num, int base)
{
	size_t r;

	r = 0;
	while (num != 0)
	{
		r++;
		num /= base;
	}
	return (r);
}
