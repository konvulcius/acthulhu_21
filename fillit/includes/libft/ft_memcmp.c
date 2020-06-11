#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				number_byte;
	unsigned char const	*first_string;
	unsigned char const	*second_string;

	number_byte = 0;
	first_string = s1;
	second_string = s2;
	while (number_byte < n)
	{
		if (first_string[number_byte] != second_string[number_byte])
			return (first_string[number_byte] - second_string[number_byte]);
		number_byte++;
	}
	return (0);
}
