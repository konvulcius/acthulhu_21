#include <stddef.h>

size_t	ft_unsigned_num_len(unsigned long long num, unsigned int base)
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
