#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*filler;

	counter = 0;
	filler = b;
	while (counter < len)
	{
		filler[counter] = (unsigned char)c;
		counter++;
	}
	return (filler);
}
