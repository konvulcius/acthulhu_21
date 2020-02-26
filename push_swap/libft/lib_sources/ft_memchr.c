#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string_of_bytes;
	unsigned char	value_of_byte;

	string_of_bytes = (unsigned char*)s;
	value_of_byte = c;
	while (n > 0)
	{
		if (*string_of_bytes == value_of_byte)
			return (string_of_bytes);
		string_of_bytes++;
		n--;
	}
	return (NULL);
}
